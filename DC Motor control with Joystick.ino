/*********************************
 * EETG3011 Embedded Controllers *
 * Lab 8 - DC Motor Control      *
 * Corey Biluk - W0425561        *
 * December 14, 2020             *
 *********************************/

/****************************************************************************************************
 * This program controls the speed and direction of a small DC motor using an L293d and a joystick. * 
 ****************************************************************************************************/

int motorSpeedPin = 3;
int dirForwardPin = 4;
int dirBackwardPin = 5;
int joystickPin = A1;
int motorSpeed;
int joystickVal;


void setup() {
  pinMode (motorSpeedPin, OUTPUT);               //Set outputs
  pinMode (dirForwardPin, OUTPUT);
  pinMode (dirBackwardPin, OUTPUT);
  pinMode (joystickPin, INPUT);                  //Set input
  //Serial.begin(9600);                          //Initialize serial monitor (used for calculations)
}

void loop() {
  
  joystickVal = analogRead(joystickPin);         //Read y-axis value from joystick
  //Serial.println (joystickVal);                //Print joystick value to serial monitor (used for calculations)
  
  if (joystickVal < 512)                         //If the joystick value is less than 512, Motor will be in backwards direction
  {
    digitalWrite(dirForwardPin, LOW);            //Write LOW to forward pin of L293d
    digitalWrite(dirBackwardPin, HIGH);          //Write HIGH to backward pin of L293d
    motorSpeed = (-255./512)*joystickVal+255.;   //Formula to convert joystick value to motor speed
    analogWrite(motorSpeedPin, motorSpeed);      //Write motor speed value to motor speed pin of L293
  }
  if (joystickVal >=512)                         //If the joystick value is greater than or equal to 512, Motor will be in forward direction          
  {
    digitalWrite(dirForwardPin, HIGH);           //Write HIGH to forward pin of L293d
    digitalWrite(dirBackwardPin, LOW);           //Write LOW to backward pin of L293d       
    motorSpeed = (255./512.)*joystickVal-255.;   //Formula to convert joystick value to motor speed
    analogWrite(motorSpeedPin, motorSpeed);      //Write motor speed value to motor speed pin of L293
  }
}
