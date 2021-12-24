/*
  Fade

  This example shows how to fade an LED on pin P3.4 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On CH552, You may use 
  P1.5/P3.0 (mutually exclusive) and P3.4/P3.1 (mutually exclusive)

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/

int led = 34;           // the PWM pin the LED is attached to, You may use P1.5/P3.0 (mutually exclusive) and P3.4/P3.1 (mutually exclusive) 
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
