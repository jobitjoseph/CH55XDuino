/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the simpleCH552
  it is attached to digital pin P3.3

  this example uses marco-based function to accelerate IO access speed. 
  Note these functions will not disable analog output(PWM)
  And they only accept constants.

  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman
  modified 13 Jun 2020
  by Deqing Sun for use with CH55xduino

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

//P33
#define LED_BUILTIN_PORT 3
#define LED_BUILTIN_PIN 3



// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinModeFast(LED_BUILTIN_PORT,LED_BUILTIN_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWriteFast(LED_BUILTIN_PORT,LED_BUILTIN_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWriteFast(LED_BUILTIN_PORT,LED_BUILTIN_PIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
