#include <Arduino.h>

void setup();
void loop();
#line 1 "src/sketch.ino"
char data = 0;                //Variable for storing received data
int greenLED = 42;
int redLED = 44;
int blueLED = 45;
int LEDpins[] = {greenLED, redLED, blueLED};
int ledCount = 0;
bool reset = false;

void setup(){
  Serial.begin(600);         //Sets the data rate in bits per second (baud) for serial data
  pinMode(greenLED, OUTPUT);        //Sets digital pin 13 as output pini
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.println("Finished setup.");

}
void loop() {

  Serial.println("Writing to digital pin ..."+String(LEDpins[ledCount]));
  digitalWrite(LEDpins[ledCount], HIGH); // sets the LED on
  int highPin = LEDpins[ledCount];

  if (ledCount >= 2) {
    ledCount = 0;
  } else {
    ledCount = ledCount + 1;
  }
  delay(1000);                // waits for a second
  digitalWrite(highPin, LOW);
  delay(1000);

}
