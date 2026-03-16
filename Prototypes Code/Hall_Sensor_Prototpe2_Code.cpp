/** Name of Author: Gerald Onyedika
 * Course: ECSE 395
 * Project Name: Hall Effect Sensor Code for Prototype 2
 * This is just a prototype code, it's not meant to account for edge cases
 *  */ 

 #include <Arduino.h>

 const int hallEffect1 = 0; // Assigning the first hall effect sensor to a pin
 const int  hallEffect2=1; // Assigning the second hall effect sensor to a pin 
int numOfPillsDispensed =0; // Starts at Zero
int numOfPillsInContainer = 100; // Defined by the user or using volume calcuations
int numberOfPillsLeft = numOfPillsInContainer - numOfPillsDispensed;

 // Creating a state  enum  to track when different sensors are activated/ when to wait for them

 enum State{
   WAITING_FOR_SENSOR1, // This is before any of the sensors detect a mag field
   WAITING_FOR_SENSOR2 // This is for when the  first sensor detects  a mg field
 };

 State currentState = WAITING_FOR_SENSOR1;


 void setup(){
    // initalizing baud rate for terminal printing(remember to adjust your monitor speed in platformio.ini accordingly
      Serial.begin(115200); 
      pinMode(hallEffect1, INPUT); // Defining the sensors as inputs
      pinMode(hallEffect2, INPUT);  // Defining the sensors as inputs


 }

 void loop(){
   if (turnCompleted() == true){
      numOfPillsDispensed = numOfPillsDispensed +1;
      Serial.Print("You have ");
      Serial.Print(numOfPillsDispensed);
      serial.Print (" left before refill");
   }
   
 }

 // Function to tell when a sucessfull turn in complete
 // Sensor 1 and Sensor 2 would be at fixed location, and the rotary would go through sensor 1 before sensor 2

bool turnCompleted(){
 // Sensor is automatically starts not detecting anything, and changes state when sensor 1 detects
 if (currentState == WAITING_FOR_SENSOR1){ 
   if( digitalRead(hallEffect1) == LOW){
      currentState =  WAITING_FOR_SENSOR2;
   }
 }

 // System State is at WAITING_FOR_SENSOR2, check the second sensor for it's activation
 if (currentState == WAITING_FOR_SENSOR2)
 {
   if(digitalRead(hallEffect2)== LOW){
      currentState = WAITING_FOR_SENSOR1; // Resets the state back to before sensor1 is detected
      return true; // Returns true for the boolean
     }
 }
  return false;

}

