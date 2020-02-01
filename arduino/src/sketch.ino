#include <SoftwareSerial.h>

const int baud_rate = 9600;
const int endSig = 7651234;

int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;

String received_data;
String last_operation;

typedef struct {
  int red_light_value;
  int green_light_value;
  int blue_light_value;
} color;

color red = {255, 0, 0};
color green = {0, 255, 0};
color blue = {0, 0, 255};
color raspberry = {255, 255, 125};
color cyan = {0, 255, 255};
color magenta = {255, 0, 255};
color yellow = {255, 255, 0};

color colors[7] = {
  red, // Red 0
  green, // Green 1
  blue, // Blue 2
  raspberry, // Raspberry 3
  cyan, // Cyan 4
  magenta, // Magenta 5
  yellow // Yellow 6
};

void fire_color(int red_light_value, int green_light_value, int blue_light_value) {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}

void select_color(int index) {
  fire_color(colors[index][0], colors[index][1], colors[index][2]);
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

  select_color(0);

  // fire_color(255, 0, 0); // Red
  // fire_color(0, 255, 0); // Green
  // fire_color(0, 0, 255); // Blue
  // fire_color(255, 255, 125); // Raspberry
  // fire_color(0, 255, 255); // Cyan
  // fire_color(255, 0, 255); // Magenta
  // fire_color(255, 255, 0); // Yellow

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
