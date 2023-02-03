/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin P1.1 and
  turning on and off a light emitting diode(LED) connected to digital pin P3.3.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input P1.1
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output P3.3
    cathode (short leg) attached to ground

  - Note: because the simpleCH552 breakout board has a built-in LED attached to
    pin P3.3 on the board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe
  modified 13 Jun 2020
  by Deqing Sun for use with CH55xduino

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInput
*/
#define LED_BUILTIN 33

int sensorPin = 11;    // select the input pin for the potentiometer. You may use P1.1, P1.4, P1.5 and P3.2
int ledPin = LED_BUILTIN; // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  //By default 8051 enable every pin's pull up resistor. Disable pull-up to get full input range.
  pinMode(sensorPin, INPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);
}
