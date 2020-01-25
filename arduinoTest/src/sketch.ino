//Include the module so we don't
//have to use the default Serial
//so the Arduino can be plugged in
//to a computer and still use bluetooth
#include <SoftwareSerial.h>

//Define the pins used for receiving
//and transmitting information via Bluetooth
const int rxpin = 0;
const int txpin = 1;

//Variable to store input value
//initialized with arbitrary value
char k = 'A';
//Connect the Bluetooth module
SoftwareSerial bluetooth(rxpin, txpin);

char data = 0;                //Variable for storing received data
int greenLED = 42;
int redLED = 44;
int blueLED = 45;
int LEDpins[] = {greenLED, redLED, blueLED};
int ledCount = 0;
bool reset = false;

void setup(){
  Serial.begin(600); //Sets the data rate in bits per second (baud) for serial data
  Serial.println("Serial monitor ready.");

  //Initialize the bluetooth
  bluetooth.begin(9600);
  Serial.println("Bluetooth ready.");
  bluetooth.println("Bluetooth ready.");

  pinMode(greenLED, OUTPUT);        //Sets digital pin 13 as output pini
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);


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

  //if(bluetooth.available()){
    //Remember new data
  Serial.println("Reading bluetooth ...");
  k = bluetooth.read();
    //Print the data for debugging purposes
  Serial.println(k);
  //}

  delay(2500);                // waits for a second
  digitalWrite(highPin, LOW);
  delay(2500);

}
