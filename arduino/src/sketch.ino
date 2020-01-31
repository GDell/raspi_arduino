#include <SoftwareSerial.h>

const int baud_rate = 9600;
const int endSig = 7651234;

int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;

String received_data;
String last_operation;

void RGB_color(int red_light_value, int green_light_value, int blue_light_value) {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}

void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  // MAKE SURE THAT THE TX AND RX PINS ARE CONNECTED TO:
  // NOTE: This is only validated for the Elegoo Mega 2560 Third Party Board.
  //       If you are using an Arduino board, the following TX/RX config may
  //       not apply.
  // TXD --> RXA (19 for Serial 1)
  // RXD --> TXA (18 for Serial 1)
  Serial.begin(baud_rate);
  Serial1.begin(baud_rate);
  Serial.print("Bluetooth configured, baud rate: ");
  Serial.print(baud_rate);
  Serial.println(".");
}

void loop() { // run over and over

  bool reading = false;
  char recv_data;

  RGB_color(255, 0, 0);

  if (Serial1.available()) {
    reading = true;
    recv_data = Serial1.read();
    Serial.write(recv_data);
    received_data += recv_data;
  }

  if (reading) {
    delay(5); // Very short delay as we are reading data.
  } else {

    if (received_data.length() > 2) {
      Serial.println("");
      Serial.println("Finished receiving operation:");
      Serial.println(received_data);
      Serial.println("");
      last_operation = received_data;
      received_data = '\0';
    }

    //Serial.println("Listening ...");
    delay(1000); // Wait a second
  }

}
