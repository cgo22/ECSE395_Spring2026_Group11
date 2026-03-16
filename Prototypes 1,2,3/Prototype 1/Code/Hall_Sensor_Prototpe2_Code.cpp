/** Name of Author: Gerald Onyedika
 * Course: ECSE 395
 * Project Name: Hall Effect Sensor Code for Prototype 2
 * This is just a prototype code, it's not meant to account for edge cases
 *  */ 

 #include <Arduino.h>

 const int hallEffect1 = 26; // Assigning the first hall effect sensor to a GPIo 26(A0)
 const int  hallEffect2=25; // Assigning the second hall effect sensor to a GPI 25(A1)
int numOfPillsDispensed =0; // Starts at Zero
const int numOfPillsInContainer = 100; // Defined by the user or using volume calcuations


 // Creating a state  enum  to track when different sensors are activated/ when to wait for them

 enum State{
   WAITING_FOR_SENSOR1, // This is before any of the sensors detect a mag field
   WAITING_FOR_SENSOR2, // This is for when the  first sensor detects  a mag field
    WAITING_FOR_CLEAR // This is for when both sensors are activated and we are waiting for them to be clear before detecting the next turn
 };

 State currentState = WAITING_FOR_SENSOR1;

 // Function to tell when a sucessfull turn in complete
 // Sensor 1 and Sensor 2 would be at fixed location, and the rotary would go through sensor 1 before sensor 2

 // Detecting a completed rotation
bool turnCompleted(){
 // Sensor is automatically starts not detecting anything, and changes state when sensor 1 detects
 if (currentState == WAITING_FOR_SENSOR1){ 
   if( digitalRead(hallEffect1) == LOW){
      currentState =  WAITING_FOR_SENSOR2;
   }
 }

 // System State is at WAITING_FOR_SENSOR2, check the second sensor for it's activation
 else if (currentState == WAITING_FOR_SENSOR2)
 {
   if(digitalRead(hallEffect2)== LOW){
      currentState = WAITING_FOR_CLEAR; // Change state to waiting for clear since both sensors are now activated
      return true; // Returns true for the boolean
     }
 }
 else if (currentState == WAITING_FOR_CLEAR)
 { if (digitalRead(hallEffect1) == HIGH && digitalRead(hallEffect2) == HIGH) {
      currentState = WAITING_FOR_SENSOR1;
    }

    
 }
  return false;

}



 void setup(){
    // initalizing baud rate for terminal printing(remember to adjust your monitor speed in platformio.ini accordingly
      Serial.begin(115200); 
      pinMode(hallEffect1, INPUT_PULLUP); // Defining the sensors as input pullup since they would be connected to ground when activated
      pinMode(hallEffect2, INPUT_PULLUP);  // Defining the sensors as inputs pullup since they would be connected to ground when activated

 }

 void loop(){
  int sensor1Value = digitalRead(hallEffect1); // Reading the value of the first sensor and assigning it to a variable for debugging purposes
  int sensor2Value = digitalRead(hallEffect2); // Reading the value of the  seccond sensor and assigning it to a variable for debugging purposes

  // Print raw sensor values for debugging purposes
  Serial.print("Sensor1: ");
  Serial.print(sensor1Value);
  Serial.print("  Sensor2: ");
  Serial.println(sensor2Value);

  // Check for completed turn
  if (turnCompleted()) {

    numOfPillsDispensed++;

    int numberOfPillsLeft = numOfPillsInContainer - numOfPillsDispensed;

    Serial.print("Turn detected. Pills dispensed: ");
    Serial.println(numOfPillsDispensed);

    Serial.print("You have ");
    Serial.print(numberOfPillsLeft);
    Serial.println(" pills left before refill.");
  }

  delay(500);
   
 }

 