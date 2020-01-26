#include <Arduino.h>
#include <SoftwareSerial.h>
void setup();
void loop();
#line 1 "src/sketch.ino"
//#include <SoftwareSerial.h>

//SoftwareSerial mySerial(19, 18); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  // Deleted while loop, unnecessary

  // set the data rate for the SoftwareSerial port
  // notice that your comment on previous line says SoftwareSerial port
  // but you are setting the Serial3 port -- this is where we use mySerial
  // Serial3.begin(38400); // commented your line of code


  //Serial1.begin(1382400);
  Serial1.begin(9600);
}

void loop() { // run over and over
  //if (Serial3.available()) { // we don't use Serial3 any more
  //Serial.println("SEARCHING FOR BLUETOOTH DATA");
  if (Serial1.available()) {
    //Serial.println("DATA DETECTED");
    //Serial.write(Serial3.read());
    Serial.write(Serial1.read());
    //Serial.println(Serial1.read());
  }
  delay(500);
  //if (Serial.available()) {
    //Serial3.write(Serial.read());
    //mySerial.write(Serial.read());
  //}
}
