#include <RH_ASK.h> // Include RadioHead Amplitude Shift Keying Library
#include <SPI.h> // Include dependant SPI Library

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

void setup()
{
// Initialize ASK Object
rf_driver.init();
// Setup Serial Monitor
Serial.begin(9600);
}

void loop()
{
const char *msg = "engine_number-plate_number";
rf_driver.send((uint8_t *)msg, strlen(msg));
rf_driver.waitPacketSent();
{
Serial.println("Message Transmitted: ");
delay(1000);
}
}
