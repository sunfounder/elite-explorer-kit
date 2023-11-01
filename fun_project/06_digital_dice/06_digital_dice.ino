/*
  This code simulates a dice roll on a 7-segment display. Pressing a button starts
  the roll, displaying random numbers rapidly and stopping after 1 second.

  Board: Arduino Uno R4 
  Component: 7-segment Display with 74HC595 and Button
*/

const int dataPin = 10;   // DS of 74HC595
const int clockPin = 13;  // SH_CP of 74HC595
const int latchPin = 12;  // ST_CP of 74HC595
const int buttonPin = 2;  // The pin where the button is connected

// Byte representation for numbers in a common-cathode 7-segment display
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

// State and timing variables
volatile bool rolling = false;
unsigned long lastButtonPress = 0;

void setup() {
  // Initialize pins
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // Enable internal pull-up resistor

  // Attach an interrupt to the buttonPin. When the button state changes (pressed or released), the rollDice function will be called
  attachInterrupt(digitalPinToInterrupt(buttonPin), rollDice, CHANGE);
}

void loop() {
  // Check if it's rolling
  if (rolling) {
    byte number = random(1, 7);  // Generate a random number between 1 and 6
    displayNumber(number);
    delay(80);  // Delay to make the rolling effect visible

    // Stop rolling after 1 second
    if ((millis() - lastButtonPress) > 1000) {
      rolling = false;
    }
  }
}

// Interrupt handler for button press
void rollDice() {
  if (digitalRead(buttonPin) == LOW) {
    lastButtonPress = millis();  // Record the time of button press
    rolling = true;              // Start rolling
  }
}

// Function to display a number on the 7-segment display
void displayNumber(byte number) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, numbers[number - 1]);
  digitalWrite(latchPin, HIGH);
}
