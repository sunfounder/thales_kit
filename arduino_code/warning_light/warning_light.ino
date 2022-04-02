// constants won't change. They're used here to set pin numbers:
const int switchPin = 14;     // the number of the switch pin
const int ledPin =  15;      // the number of the LED pin

// variables will change:
int switchState = 0;         // variable for reading the switch status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the switch pin as an input:
  pinMode(switchPin, INPUT);
}

void loop() {
  // read the state of the switch value:
  switchState = digitalRead(switchPin);

  // check if the switch is pressed. If it is, the switchState is HIGH:
  if (switchState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
