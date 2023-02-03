/*
  Calibration

  Demonstrates one technique for calibrating sensor input. The sensor readings
  during the first five seconds of the sketch execution define the minimum and
  maximum of expected values attached to the sensor pin.

  The sensor minimum and maximum initial values may seem backwards. Initially,
  you set the minimum high and listen for anything lower, saving it as the new
  minimum. Likewise, you set the maximum low and listen for anything higher as
  the new maximum.

  The circuit:
  - analog sensor (potentiometer will do) attached to analog input P1.1
  - LED attached from digital pin P3.4 to ground

  created 29 Oct 2008
  by David A Mellis
  modified 30 Aug 2011
  by Tom Igoe
  modified 28 Feb 2017 for use with sduino
  by Michael Mayer
  modified 13 Jun 2020
  by Deqing Sun for use with CH55xduino

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Calibration
*/

// These constants won't change:
const int sensorPin = 11;    // pin that the sensor is attached to. You may use P1.1, P1.4, P1.5 and P3.2
const int ledPin = 33;        // pin that the LED is attached to 
const int ledPinFade = 34;        // pin that the LED is attached to.  You may use P1.5/P3.0 (mutually exclusive) and P3.4/P3.1 (mutually exclusive)


// variables:
int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value


void setup() {
  // turn on LED to signal the start of the calibration period:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPinFade, OUTPUT);
  // By default 8051 enable every pin's pull up resistor. Disable pull-up to get full input range.
  pinMode(sensorPin, INPUT);
  digitalWrite(ledPin, HIGH);

  // calibrate during the first five seconds
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);

    // record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }

  // signal the end of the calibration period
  digitalWrite(ledPin, LOW);
}

void loop() {
  // read the sensor:
  sensorValue = analogRead(sensorPin);

  // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, 0, 255);

  // fade the LED using the calibrated value:
  analogWrite(ledPinFade, sensorValue);
}
