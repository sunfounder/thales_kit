const int ledPins[] = {11, 12, 13, 14, 15};
const int photocellPin = A0;  //photoresistor attach to A0
int sensorValue = 0;        // value read from the sensor
int Level = 0;           // sensor value converted into LED 'bars'

void setup()
{
  Serial.begin(9600);  // start serial port at 9600 bps:
  for (int i = 0; i < 5; i++)
  {
    pinMode(ledPins[i], OUTPUT);// make all the LED pins outputs
  }
}

void loop()
{
  sensorValue = analogRead(photocellPin); //read the value of A0
  Level = map(sensorValue, 0, 1023, 0, 5);  // map to the number of LEDs
  Serial.println(Level);
  delay(10);
  for (int i = 0; i < 5; i++)
  {
    if (i <= Level ) //When i is smaller than Level, run the following code.
    {
      digitalWrite(ledPins[i], HIGH);     // turn on LEDs less than the level
    }
    else
    {
      digitalWrite(ledPins[i], LOW);     // turn off LEDs higher than level
    }
  }
}
