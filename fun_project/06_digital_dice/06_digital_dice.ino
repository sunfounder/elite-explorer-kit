const int dataPin = 10;    // DS of 74HC595
const int clockPin = 13;   // SH_CP of 74HC595
const int latchPin = 12;   // ST_CP of 74HC595
const int buttonPin = 2;  // The pin where the button is connected

//common cathode
byte numbers[] = {
  // 0b00111111,  // 0
  0b00000110,  // 1
  0b01011011,  // 2
  0b01001111,  // 3
  0b01100110,  // 4
  0b01101101,  // 5
  0b01111101,  // 6
  //... Add the values for the rest of the numbers
};

volatile bool rolling = false;
unsigned long lastButtonPress = 0;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Use an internal pull-up resistor

  attachInterrupt(digitalPinToInterrupt(buttonPin), rollDice, CHANGE);
}

void loop() {
  if (rolling) {
    byte number = random(1, 7);  // Get a random number between 1 and 6
    displayNumber(number);
    delay(80);

    if ((millis() - lastButtonPress) > 1000) {
      rolling = false;
    }
  }
}

void rollDice() {
  if (digitalRead(buttonPin) == LOW) {
    lastButtonPress = millis();
    rolling = true;
  }
}

void displayNumber(byte number) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, numbers[number - 1]);
  digitalWrite(latchPin, HIGH);
}
