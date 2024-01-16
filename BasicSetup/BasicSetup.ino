// Constants
const int buttonPin = 12;         // the number of the pushbutton pin
const int ledPin = 13;            // the number of the LED pin
const int ledPowerPin = 27;       // the number of the LED power pin
const int ledProcessingPin = 33;  // the number of the LED processing pin
const int ledNegativePin = 15;    // the number of the LED negative pin
const int ledPositivePin = 32;    // the number of the LED positive pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
