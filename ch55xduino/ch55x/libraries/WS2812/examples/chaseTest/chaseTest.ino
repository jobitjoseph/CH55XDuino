#include <WS2812.h>

#define NUM_LEDS 8
#define COLOR_PER_LEDS 3
#define NUM_BYTES (NUM_LEDS*COLOR_PER_LEDS)

#if NUM_BYTES > 255
#error "NUM_BYTES can not be larger than 255."
#endif

__xdata uint8_t ledData[NUM_BYTES];

void setup() {
  pinMode(15, OUTPUT); //Possible to use other pins. 
}

void loop() {

  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    set_pixel_for_GRB_LED(ledData, i, 1, 0, 0); //Choose the color order depending on the LED you use. 
    neopixel_show_P1_5(ledData, NUM_BYTES); //Possible to use other pins. 
    delay(100);
  }
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    set_pixel_for_GRB_LED(ledData, i, 0, 1, 0);
    neopixel_show_P1_5(ledData, NUM_BYTES);
    delay(100);
  }
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    set_pixel_for_GRB_LED(ledData, i, 0, 0, 1);
    neopixel_show_P1_5(ledData, NUM_BYTES);
    delay(100);
  }

}
