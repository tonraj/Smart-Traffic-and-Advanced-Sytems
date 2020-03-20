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
// Set buffer to size of expected message
uint8_t buf[35];
uint8_t buflen = sizeof(buf);
// Check if received packet is correct size
if (rf_driver.recv(buf, &buflen))
{
// Message received with valid che-cksum
//Serial.print("Message Received: ");
Serial.println((char*)buf);
}
}
