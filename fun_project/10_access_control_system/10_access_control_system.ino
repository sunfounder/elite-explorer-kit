#include <rfid1.h>
#include <Stepper.h>
#include <Wire.h>

#define ID_LEN 4

/*Stepper Motor*/
const int stepsPerRevolution = 2048;
const int rolePerMinute = 16;
const int IN1 = 11;
const int IN2 = 10;
const int IN3 = 9;
const int IN4 = 8;

/*Buzzer*/
const int buzPin = 12;

/*Authentication Parameters*/
uchar userIdRead[ID_LEN] = { "" };
uchar userId[ID_LEN] = {0x36, 0xE2, 0xC4, 0xF7};  // Authenticated ID
bool approved = 0;

RFID1 rfid;  //create a variable type of RFID1
Stepper stepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup() {
  Serial.begin(9600);
  stepper.setSpeed(rolePerMinute);
  pinMode(buzPin, OUTPUT);
  rfid.begin(7, 5, 4, 3, 6, 2);
  rfid.init();  //initialize the RFID
  Serial.println("start");
}

void loop() {
  if (approved == 0) {
    approved = rfidRead();
    for (int i = 0; i < ID_LEN; i++) {
      userIdRead[i] = NULL;
    }
  }
  if (approved == 1) {
    openDoor();
    approved = 0;
  }
}

void beep(int duration, int frequency) {
  for (int i = 0; i < frequency; i++) {
    digitalWrite(buzPin, HIGH);
    delay(duration);
    digitalWrite(buzPin, LOW);
    delay(100);
  }
}

void verifyPrint(bool result) {
  if (result == true) {
    beep(100, 3);
    delay(400);
  } else {
    beep(500, 1);
    delay(400);
  }
}

void openDoor() {
  int doorStep = 512;  //This means the door will open to 90 degrees
  stepper.step(doorStep);
  for (int i = 0; i < 5; i++) {
    delay(1000);
  }
  stepper.step(-doorStep);
}

bool rfidRead() {
  getId();
  if (userIdRead[0] != NULL) {
    return idVerify();
  }
  return 0;
}

void getId() {
  uchar status;
  uchar str[MAX_LEN];
  status = rfid.request(PICC_REQIDL, str);
  if (status != MI_OK) {
    return;
  } else {
    status = rfid.anticoll(str);
    Serial.println("");
    Serial.print("Reading Card ID: ");
    if (status == MI_OK) {
      for (int i = 0; i < ID_LEN; i++) {
        userIdRead[i] = str[i];
        Serial.print("0x");
        Serial.print(userIdRead[i],HEX);
        Serial.print(", ");
      }
    }
    delay(500);
    rfid.halt();
    beep(150, 1);
  }
}

bool idVerify() {
  for (int i = 0; i < ID_LEN; i++) {
    if (userIdRead[i] != userId[i]) {
      verifyPrint(0);
      return 0;
    }
  }
  verifyPrint(1);
  return 1;
}
