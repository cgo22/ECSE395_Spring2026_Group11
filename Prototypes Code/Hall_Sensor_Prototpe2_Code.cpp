/** Name of Author: Gerald Onyedika
 * Course: ECSE 395
 * Project Name: Hall Effect Sensor Code for Prototype 2 */ 

 #include <Arduino.h>

 const int hallEffect1 = 0; // Assigning the first hall effect sensor to a pin
 const int  hallEffect2=1; // Assigning the second hall effect sensor to a pin 


 void setup(){
    // initalizing baud rate for terminal printing(remember to adjust your monitor speed in platformio.ini accordingly
      Serial.begin(115200); 
      pinMode(hallEffect1, INPUT); // Defining the sensors as inputs
      pinMode(hallEffect2, INPUT);  // Defining the sensors as inputs


 }

 void loop(){
    // Using the turnComplteted function , report how many supplement is dispensed.

 }

 // Function to tell when a sucessfull turn in complete
 // Sensor 1 and Sensor 2 ould be at fixed location, and the rotary would go through sensor 1 before sensor 2

bool turnCompleted( int sensor1, int sensor2){

// If sensor 1 is triggered, check if sensor 2 is triggered, if it's sensor 2 is triggered after sensor 1, return that turn was completed
// If sensor 2 isn't triggered after sensor do nothing, 
// Add soemthing for when the user turns past sensor 1 and then turns back to starting point 
}

