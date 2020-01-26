#include <SoftwareSerial.h>

const int baud_rate = 9600;

void setup() {
  // MAKE SURE THAT THE TX AND RX PINS ARE CONNECTED TO:
  // NOTE: This is only validated for the Elegoo Mega 2560 Third Party Board.
  //       If you are using an Arduino board, the foloowing TX/RX config may
  //       not apply.
  // TXD --> RXA (19 for Serial 1)
  // RXD --> TXA (18 for Serial 1)
  Serial.begin(baud_rate); // Serial monitor.
  Serial1.begin(baud_rate); // Listin to bluetooth module over Serial1 pins (18/19).
  Serial.print("Bluetooth configured, baud rate: ");
  Serial.print(baud_rate);
  Serial.println(".");
}

void loop() { // run over and over

  if (Serial1.available()) {
    Serial.write(Serial1.read());
  }

  delay(500); // Process one byte every half second

}
