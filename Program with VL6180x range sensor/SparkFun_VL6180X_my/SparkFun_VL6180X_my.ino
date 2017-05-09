/******************************************************************************
 * SparkFun_VL6180X_demo.ino
 * Example Sketch for VL6180x time of flight range finder.
 * Casey Kuhns @ SparkFun Electronics
 * 10/29/2014
 * https://github.com/sparkfun/SparkFun_ToF_Range_Finder-VL6180_Arduino_Library
 * 
 * The VL6180x by ST micro is a time of flight range finder that
 * uses pulsed IR light to determine distances from object at close
 * range.  The average range of a sensor is between 0-200mm
 * 
 * Resources:
 * This library uses the Arduino Wire.h to complete I2C transactions.
 * 
 * Development environment specifics:
 * 	IDE: Arduino 1.0.5
 * 	Hardware Platform: Arduino Pro 3.3V/8MHz
 * 	VL6180x Breakout Version: 1.0
 *  **Updated for Arduino 1.6.4 5/2015**

 * 
 * This code is beerware. If you see me (or any other SparkFun employee) at the
 * local pub, and you've found our code helpful, please buy us a round!
 * 
 * Distributed as-is; no warranty is given.
 ******************************************************************************/

#include <Wire.h>
#include "SparkFun_VL6180X.h"

#define VL6180X_ADDRESS 0x29

VL6180xIdentification identification;
VL6180x sensor(VL6180X_ADDRESS);

int calibrate = 0;  // This is the value for calibrated empty distance
int distance = calibrate;
  
  //int historyCount = 1;  // The number of running average, 2 seems doable, 5 will sometimes miss the counting
  
  //int history[historyCount];
  //for ( int i = 0; i < historyCount; i++){
  //  history[i] = calibrate;
  //}

  int sum = 0;
  int avg;
  int count = 0;
  
  int thresholdIn = 3; // The threshold to detect a berry
  int thresholdOut = 8;  // The threshold to detect there's no berries

  int detected = 0;  // 1: detected, a flag

void setup() {
  Serial.begin(115200); //Start Serial at 2000000bps
  Wire.begin(); //Start I2C library
  pinMode(12, INPUT_PULLUP);  // Connect 12 to GPIO1
  delay(100); 

  
  sensor.getIdentification(&identification); // Retrieve manufacture info from device memory
  printIdentification(&identification); // Helper function to print all the Module information

  int result = sensor.VL6180xInit();
    if(result != 0){
    Serial.println("Init failed! Please check the wire!"); //Initialize device and check for errors
    while (1){}
  }; 

  	sensor.VL6180xDefautSettings(); //Load default settings to get started.
   
   Serial.println("Initializing..."); //Initialize device and check for errors

   delay(200); // delay 1s
   
   Serial.println("Calibrating..."); //Initialize device and check for errors

   int distance = sensor.getDistance();
   int count = 0;
   while (count < 200){
    distance += sensor.getDistance();
    count++;
   }
   calibrate = distance/ count;
    Serial.println("Calibrated distance:"); //Initialize device and check for errors

   Serial.println(calibrate); //Initialize device and check for errors
   Serial.println("Ready for counting"); //Initialize device and check for errors
   sensor.startMultipleRange();   //Start multiple ranging mode!!!!
   
}
unsigned long previousMillis = 0;        // will store last time LED was updated
int oldCount = 0;
void loop() {
  
  // Initialize all the variables


     distance = sensor.mygetDistance();


      if ( ! detected){
        if ( distance + thresholdIn < calibrate){
          // Detected a new berry
          detected = 1;
          count ++;

        }
      }
      else {
        if ( distance + thresholdOut > calibrate){   // (avg + )
          // No berries
          detected = 0;

        }
      }
 
  if (digitalRead(12) == LOW){
    Serial.println(distance);
    //      Serial.println( count ); 

  }

};

void printIdentification(struct VL6180xIdentification *temp){
  Serial.print("Model ID = ");
  Serial.println(temp->idModel);

  Serial.print("Model Rev = ");
  Serial.print(temp->idModelRevMajor);
  Serial.print(".");
  Serial.println(temp->idModelRevMinor);


  Serial.print(temp->idModuleRevMajor);
  Serial.print(".");
  Serial.println(temp->idModuleRevMinor);  

  Serial.print("Manufacture Date = ");
  Serial.print((temp->idDate >> 3) & 0x001F);
  Serial.print("/");
  Serial.print((temp->idDate >> 8) & 0x000F);
  Serial.print("/1");
  Serial.print((temp->idDate >> 12) & 0x000F);
  Serial.print(" Phase: ");
  Serial.println(temp->idDate & 0x0007);

  Serial.print("Manufacture Time (s)= ");
  Serial.println(temp->idTime * 2);
  Serial.println();
  Serial.println();
}


