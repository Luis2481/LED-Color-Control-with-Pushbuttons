// Variable declaration --> LEDS!
int redPinLED = 12;
int greenPinLED = 11;
int bluePinLED = 10;
int yellowPinLED = 5;

int redLEDStateNow = 0;
int greenLEDStateNow = 0;
int blueLEDStateNow = 0;
int yellowLEDStateNow = 0;

// Variable declaration --> button pins!
int redButtonPin = 9;
int greenButtonPin = 8;
int blueButtonPin = 7;
int yellowButtonPin = 6;

int yellowButtonStateReadNow = 1; // value to be read digitally from the buttonPin
int yellowButtonStateOld = 1;

int redButtonStateReadNow = 1; // value to be read digitally from the buttonPin
int redButtonStateOld = 1;

int greenButtonStateReadNow = 1; // value to be read digitally from the buttonPin
int greenButtonStateOld = 1;

int blueButtonStateReadNow = 1; // value to be read digitally from the buttonPin
int blueButtonStateOld = 1;

int br = 115200; // for the Serial monitor

int endingLoop = 50; // delay

void setup() {
  // Set the LEDs pins, button pins, and the serial monitor
  pinMode (redButtonPin, INPUT_PULLUP);
  pinMode (greenButtonPin, INPUT_PULLUP);
  pinMode (blueButtonPin, INPUT_PULLUP);
  pinMode (yellowButtonPin, INPUT_PULLUP);

  pinMode (redPinLED, OUTPUT);
  pinMode (greenPinLED, OUTPUT);
  pinMode (bluePinLED, OUTPUT);
  pinMode (yellowPinLED, OUTPUT);

  Serial.begin(br);

  Serial.println("There are 4 colors: RED, GREEN, BLUE and YELLOW.");
  Serial.println("Push the button switch with the color that you want to put in the RGB LED.");
  Serial.println("NOTE: You can mix the colors in the RGB LED if you like. :)");
  Serial.println("");
}

void loop() {
  // Perform the procedure
  // First, read the value from the button switches
  redButtonStateReadNow = digitalRead(redButtonPin);
  greenButtonStateReadNow = digitalRead(greenButtonPin);
  blueButtonStateReadNow = digitalRead(blueButtonPin);
  yellowButtonStateReadNow = digitalRead(yellowButtonPin);
  
  // if statements to turn on the RGB LED depending on whether the button switch is pressed or not. The colors are: RED, GREEN AND BLUE
  // Start with RED
  if (redButtonStateOld == 1 && redButtonStateReadNow == 0) { // when the button switch IS pressed

  if (redLEDStateNow == 0) {
    Serial.println("The red LED is ON.");
    Serial.println("");
    digitalWrite (redPinLED, HIGH); // pin 9 of the button switch will recognize the voltage drop from the 10k resistor, so there will be voltage (the LED WILL turn on)
  }

  if (redLEDStateNow == 1) {
    Serial.println("The red LED is OFF.");
    Serial.println("");
    digitalWrite (redPinLED, LOW);
  }

  redLEDStateNow = !redLEDStateNow; // --> invert from 0 to 1 and from 1 to 0. Always work with the logic of the button switches
  // and at the end change the logic of the LEDs so they can be implemented correctly
  }

  redButtonStateOld = redButtonStateReadNow; // the previous action of the red button switch is changed with the recent one so
  // the changes are updated in each loop
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // GREEN
  if (greenButtonStateOld == 1 && greenButtonStateReadNow == 0) { // when the button switch IS pressed

  if (greenLEDStateNow == 0) {
    Serial.println("The green LED is ON.");
    Serial.println("");
    digitalWrite (greenPinLED, HIGH); // pin 9 of the button switch will recognize the voltage drop from the 10k resistor, so there will be voltage (the LED WILL turn on)
  }

  if (greenLEDStateNow == 1) {
    Serial.println("The green LED is OFF.");
    Serial.println("");
    digitalWrite (greenPinLED, LOW);
  }

  greenLEDStateNow = !greenLEDStateNow; // --> invert from 0 to 1 and from 1 to 0. Always work with the logic of the button switches
  // and at the end change the logic of the LEDs so they can be implemented correctly
  }

  greenButtonStateOld = greenButtonStateReadNow; // the previous action of the red button switch is changed with the recent one so
  // the changes are updated in each loop
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
  // BLUE
  if (blueButtonStateOld == 1 && blueButtonStateReadNow == 0) { // when the button switch IS pressed

  if (blueLEDStateNow == 0) {
    Serial.println("The blue LED is ON.");
    Serial.println("");
    digitalWrite (bluePinLED, HIGH); // pin 9 of the button switch will recognize the voltage drop from the 10k resistor, so there will be voltage (the LED WILL turn on)
  }

  if (blueLEDStateNow == 1) {
    Serial.println("The blue LED is OFF.");
    Serial.println("");
    digitalWrite (bluePinLED, LOW);
  }

  blueLEDStateNow = !blueLEDStateNow; // --> invert from 0 to 1 and from 1 to 0. Always work with the logic of the button switches
  // and at the end change the logic of the LEDs so they can be implemented correctly
  }

  blueButtonStateOld = blueButtonStateReadNow; // the previous action of the red button switch is changed with the recent one so
  // the changes are updated in each loop
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // YELLOW
  if (yellowButtonStateOld == 1 && yellowButtonStateReadNow == 0) { // when the button switch IS pressed

  if (yellowLEDStateNow == 0) {
    Serial.println("The yellow LED is ON.");
    Serial.println("");
    digitalWrite (yellowPinLED, HIGH); // pin 9 of the button switch will recognize the voltage drop from the 10k resistor, so there will be voltage (the LED WILL turn on)
  }

  if (yellowLEDStateNow == 1) {
    Serial.println("The yellow LED is OFF.");
    Serial.println("");
    digitalWrite (yellowPinLED, LOW);
  }

  yellowLEDStateNow = !yellowLEDStateNow; // --> invert from 0 to 1 and from 1 to 0. Always work with the logic of the button switches
  // and at the end change the logic of the LEDs so they can be implemented correctly
  }

  yellowButtonStateOld = yellowButtonStateReadNow; // the previous action of the red button switch is changed with the recent one so
  // the changes are updated in each loop

  delay (endingLoop); // apply delay to avoid small errors in reading the button switches and in the signal transmission of the RGB LED
}
