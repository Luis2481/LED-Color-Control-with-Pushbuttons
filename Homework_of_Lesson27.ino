// declaracion de variables --> LEDS!
int redPinLED = 12;
int greenPinLED = 11;
int bluePinLED = 10;
int yellowPinLED = 5;

int redLEDStateNow = 0;
int greenLEDStateNow = 0;
int blueLEDStateNow = 0;
int yellowLEDStateNow = 0;

// declaracion de variables --> button pins!
int redButtonPin = 9;
int greenButtonPin = 8;
int blueButtonPin = 7;
int yellowButtonPin = 6;

int yellowButtonStateReadNow = 1; // valor que se leera digitalmente del buttonPin
int yellowButtonStateOld = 1;

int redButtonStateReadNow = 1; // valor que se leera digitalmente del buttonPin
int redButtonStateOld = 1;

int greenButtonStateReadNow = 1; // valor que se leera digitalmente del buttonPin
int greenButtonStateOld = 1;

int blueButtonStateReadNow = 1; // valor que se leera digitalmente del buttonPin
int blueButtonStateOld = 1;

int br = 115200; // para el Serial monitor

int endingLoop = 50; // delay

void setup() {
  // Seteo los LEDs pins, button pins, y el serial monitor
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
  // hago el procedimiento
  // primero se lee el valor de los button switchs
  redButtonStateReadNow = digitalRead(redButtonPin);
  greenButtonStateReadNow = digitalRead(greenButtonPin);
  blueButtonStateReadNow = digitalRead(blueButtonPin);
  yellowButtonStateReadNow = digitalRead(yellowButtonPin);
  // if statements para encender el RGB LED dependiendo si presiono el button switch o no. Los colores son: RED, GREEN AND BLUE
  // Se empieza con el ROJO
  if (redButtonStateOld == 1 && redButtonStateReadNow == 0) { // cuando SI presiono el button switch

  if (redLEDStateNow == 0) {
    Serial.println("The red LED is ON.");
    Serial.println("");
    digitalWrite (redPinLED, HIGH); // el pin 9 del button switch va a reconocer el voltage drop del 10k resistor, por lo cual va a haber voltaje (el LED SI va a prender)
  }

  if (redLEDStateNow == 1) {
    Serial.println("The red LED is OFF.");
    Serial.println("");
    digitalWrite (redPinLED, LOW);
  }

  redLEDStateNow = !redLEDStateNow; // --> se hace la inversion de 0 a 1 y de 1 a 0. Siempre se tiene que trabajar con la logica de los button switches
  // y en el final se cambia la logica de los LEDs para que se pueda implementar correctamente
  }

  redButtonStateOld = redButtonStateReadNow; // la accion pasada del red button switch se cambia con la que se hizo reciente para que
  // los cambios se actualizen en cada loop
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // VERDE
  if (greenButtonStateOld == 1 && greenButtonStateReadNow == 0) { // cuando SI presiono el button switch

  if (greenLEDStateNow == 0) {
    Serial.println("The green LED is ON.");
    Serial.println("");
    digitalWrite (greenPinLED, HIGH); // el pin 9 del button switch va a reconocer el voltage drop del 10k resistor, por lo cual va a haber voltaje (el LED SI va a prender)
  }

  if (greenLEDStateNow == 1) {
    Serial.println("The green LED is OFF.");
    Serial.println("");
    digitalWrite (greenPinLED, LOW);
  }

  greenLEDStateNow = !greenLEDStateNow; // --> se hace la inversion de 0 a 1 y de 1 a 0. Siempre se tiene que trabajar con la logica de los button switches
  // y en el final se cambia la logica de los LEDs para que se pueda implementar correctamente
  }

  greenButtonStateOld = greenButtonStateReadNow; // la accion pasada del red button switch se cambia con la que se hizo reciente para que
  // los cambios se actualizen en cada loop
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
  // AZUL
  if (blueButtonStateOld == 1 && blueButtonStateReadNow == 0) { // cuando SI presiono el button switch

  if (blueLEDStateNow == 0) {
    Serial.println("The blue LED is ON.");
    Serial.println("");
    digitalWrite (bluePinLED, HIGH); // el pin 9 del button switch va a reconocer el voltage drop del 10k resistor, por lo cual va a haber voltaje (el LED SI va a prender)
  }

  if (blueLEDStateNow == 1) {
    Serial.println("The blue LED is OFF.");
    Serial.println("");
    digitalWrite (bluePinLED, LOW);
  }

  blueLEDStateNow = !blueLEDStateNow; // --> se hace la inversion de 0 a 1 y de 1 a 0. Siempre se tiene que trabajar con la logica de los button switches
  // y en el final se cambia la logica de los LEDs para que se pueda implementar correctamente
  }

  blueButtonStateOld = blueButtonStateReadNow; // la accion pasada del red button switch se cambia con la que se hizo reciente para que
  // los cambios se actualizen en cada loop
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // YELLOW
  if (yellowButtonStateOld == 1 && yellowButtonStateReadNow == 0) { // cuando SI presiono el button switch

  if (yellowLEDStateNow == 0) {
    Serial.println("The yellow LED is ON.");
    Serial.println("");
    digitalWrite (yellowPinLED, HIGH); // el pin 9 del button switch va a reconocer el voltage drop del 10k resistor, por lo cual va a haber voltaje (el LED SI va a prender)
  }

  if (yellowLEDStateNow == 1) {
    Serial.println("The yellow LED is OFF.");
    Serial.println("");
    digitalWrite (yellowPinLED, LOW);
  }

  yellowLEDStateNow = !yellowLEDStateNow; // --> se hace la inversion de 0 a 1 y de 1 a 0. Siempre se tiene que trabajar con la logica de los button switches
  // y en el final se cambia la logica de los LEDs para que se pueda implementar correctamente
  }

  yellowButtonStateOld = yellowButtonStateReadNow; // la accion pasada del red button switch se cambia con la que se hizo reciente para que
  // los cambios se actualizen en cada loop

  delay (endingLoop); // se aplica delay para que no hayan errores pequeños en la leida de los button switches y en la transmiscion de señal del RGB LED
}
