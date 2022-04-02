const int buzzerPin = 15;
const int ledPin = 16;
const int photocellPin = A2;  //photoresistor attach to A2

int lightLow = 1023;
int lightHigh = 0;

int sensorValue = 0;        // value read from the sensor
int pitch = 0;           // sensor value converted into LED 'bars'

unsigned long previousMillis = 0;
const long interval = 1000;

void setup()
{
  pinMode(buzzerPin, OUTPUT);// make all the LED pins outputs


  /* calibrate the photoresistor max & min values */
  previousMillis = millis();
  digitalWrite(ledPin, HIGH);
  while (millis() - previousMillis <= interval) {
    sensorValue = analogRead(photocellPin);
    if (sensorValue > lightHigh) {
      lightHigh = sensorValue;
    }
    if (sensorValue < lightLow) {
      lightLow = sensorValue;
    }
  }
  digitalWrite(ledPin, LOW);
}

void loop()
{
  /* play*/
  sensorValue = analogRead(photocellPin); //read the value of A0
  pitch = map(sensorValue, lightLow, lightHigh, 50, 6000);  // map to the number of bu
  if (pitch > 50) {
    tone(buzzerPin, pitch, 20);
  }
  delay(10);
}
