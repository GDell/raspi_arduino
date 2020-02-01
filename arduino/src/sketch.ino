#include <SoftwareSerial.h>

// BLUETOOTH CONFIG
const int baud_rate = 9600;
const int endSig = 7651234;
String received_data; // Object to store read data.
String last_operation; // Object to store 1 operation after finished receiving.

// PUSH BUTTON
int inPin = 7;

// RGB LED
int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;

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

void fire_color_from_index(int index) {
  color selected_color = colors[index];
  fire_color(selected_color.red_light_value, selected_color.green_light_value, selected_color.blue_light_value);
}

void fire_color_from_string(char* selected_color) {
  int index = 0;
  if ("red" == selected_color || "Red" == selected_color) {
    //
  } else if ("green" == selected_color || "Green" == selected_color) {
    index = 1;
  } else if ("blue" == selected_color || "Blue" == selected_color) {
    index = 2;
  } else if ("raspberry" == selected_color || "Raspberry" == selected_color) {
    index = 3;
  } else if ("cyan" == selected_color || "Cyan" == selected_color) {
    index = 4;
  } else if ("magenta" == selected_color || "Magenta" == selected_color) {
    index = 5;
  } else if ("yellow" == selected_color || "Yellow" == selected_color) {
    index = 6;
  }
  fire_color_from_index(index);
}


int count = 0;
int max_count = 7;

void setup() {
  // RGB LED
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);

  // PUSH BUTTON
  pinMode(inPin, INPUT);

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

  val = digitalRead(inPin);  // read input value
  if (val == HIGH) {         // check if the input is HIGH (button released)
    fire_color_from_string("Blue");
  } else {
    fire_color_from_string("Magenta");
  }


  if (Serial1.available()) {
    reading = true;
    recv_data = Serial1.read();
    Serial.write(recv_data);
    received_data += recv_data;
  }


  if (reading) {
    delay(5); // Very short delay as we are reading data.

  } else {
    // Not currently recieving bluetooth data.

    // Are we done listening to an operation over bluetooth?
    // If so, store the data so we can listen for the next operation.
    if (received_data.length() > 2) {
      Serial.println("");
      Serial.println("Finished receiving operation:");
      Serial.println(received_data);
      Serial.println("");
      last_operation = received_data;
      received_data = '\0'; // Clear received data to store the next operation.
    }

    //Serial.println("Listening ...");
    delay(1500); // Wait a second.5

    // This iterates the color counter.
    // if (count < max_count) {
    //   count = count + 1;
    // } else {
    //   count = 0;
    // }

  }

}
