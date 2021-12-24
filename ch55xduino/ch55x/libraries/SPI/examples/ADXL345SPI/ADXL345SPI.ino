#include <SPI.h>

//On CH552: SCK->P1.7, MISO->P1.6 MOSI->P1.5

#define CS_PIN 14

void setup() {
  digitalWrite(CS_PIN, HIGH);
  pinMode(CS_PIN, OUTPUT);

  SPI_begin();
  SPI_beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));

  while (!USBSerial()) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  USBSerial_println_s("Access ADXL345 with SPI.");

  digitalWrite(CS_PIN, LOW);
  SPI_transfer(0x00 | 0x80); //read DEVID 0x00
  uint8_t ret = SPI_transfer(0xFF);
  digitalWrite(CS_PIN, HIGH);

  if (ret == 0xE5) {
    USBSerial_println_s("DEVID OK");
  } else {
    USBSerial_println_s("DEVID NOT OK");
    while (1);
  }

  digitalWrite(CS_PIN, LOW);
  SPI_transfer(0x2D); //write 0x2D
  SPI_transfer(0); // Wakeup
  digitalWrite(CS_PIN, HIGH);

  digitalWrite(CS_PIN, LOW);
  SPI_transfer(0x2D); //write 0x2D
  SPI_transfer(0x10); //Auto_Sleep
  digitalWrite(CS_PIN, HIGH);

  digitalWrite(CS_PIN, LOW);
  SPI_transfer(0x2D); //write 0x2D
  SPI_transfer(0x08); // Measure
  digitalWrite(CS_PIN, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);

  int16_t x = 0, y = 0, z = 0;
  uint8_t ret1, ret2;

  digitalWrite(CS_PIN, LOW);
  USBSerial_println_s("send:");

  SPI_transfer(0x32 | 0x80 | 0x40); //read DATAX0 0x32, multiple bytes
  ret1 = SPI_transfer(0xFF);
  ret2 = SPI_transfer(0xFF);
  x = (int16_t)((((int)ret2) << 8) | ret1);
  ret1 = SPI_transfer(0xFF);
  ret2 = SPI_transfer(0xFF);
  y = (int16_t)((((int)ret2) << 8) | ret1);
  ret1 = SPI_transfer(0xFF);
  ret2 = SPI_transfer(0xFF);
  z = (int16_t)((((int)ret2) << 8) | ret1);
  digitalWrite(CS_PIN, HIGH);

  USBSerial_print_s("ACCEL: ");
  USBSerial_print_i(x);
  USBSerial_print_s(", ");
  USBSerial_print_i(y);
  USBSerial_print_s(", ");
  USBSerial_println_i(z);
}
