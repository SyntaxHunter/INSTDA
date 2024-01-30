// Constants
const int buttonPin = 12;         // the number of the pushbutton pin
const int ledPowerPin = 27;       // the number of the LED power pin
const int ledProcessingPin = 33;  // the number of the LED processing pin
const int ledNegativePin = 15;    // the number of the LED negative pin
const int ledPositivePin = 32;    // the number of the LED positive pin

// variables will change:
int buttonState = LOW;            // current reading from the input pin
int lastButtonState = LOW;        // previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;   // the last time the output pin was toggled
unsigned long debounceDelay = 50;     // the debounce time; increase if the output flickers
unsigned long processingDelay = 1000; // processing delay (temporary for demonstration purposes)

void setup() {
  // initialize the LED pins as outputs:
  pinMode(ledPowerPin, OUTPUT);
  pinMode(ledProcessingPin, OUTPUT);
  pinMode(ledNegativePin, OUTPUT);
  pinMode(ledPositivePin, OUTPUT);
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  // set initial LED states
  digitalWrite(ledPowerPin, HIGH);
  digitalWrite(ledProcessingPin, LOW);
  digitalWrite(ledNegativePin, LOW);
  digitalWrite(ledPositivePin, LOW);
}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        processSample();
      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}

void processSample() {
  digitalWrite(ledProcessingPin, HIGH);
  digitalWrite(ledPositivePin, LOW);
  digitalWrite(ledNegativePin, LOW);
 
  delay(processingDelay);
  digitalWrite(ledProcessingPin, LOW);

  // randomly choose a positive or negative result
  int result = random(2);
  if (result == 0) {
    digitalWrite(ledPositivePin, HIGH);
  } else {
    digitalWrite(ledNegativePin, HIGH);
  }
}
