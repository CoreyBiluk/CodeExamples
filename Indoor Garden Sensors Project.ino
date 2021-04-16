/************************************  
 *  Automated Indoor Garden Sensors *
 *  Corey Biluk                     *
 ************************************/

/********************************
 * DHT11 Temp & Humidity Sensor *
 ********************************/
#include <dht_nonblocking.h>
#define DhtSensorType DHT_TYPE_11
int TempSensorPin = 2;
DHT_nonblocking dht_sensor(TempSensorPin, DhtSensorType);

/**************
 * LCD Screen *
 **************/
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

/***************
 * Analog Pins *
 ***************/
int fanPin=A3;
int wLvlPin=A4;
int lSensorPin=A5;

/****************
 * Digital Pins *
 ****************/
int greenLedPin = 4;
int redLedPin = 5;
int whiteLedPin=6;


void setup( )
{
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(greenLedPin,OUTPUT);
  pinMode(redLedPin,OUTPUT);
  pinMode(whiteLedPin,OUTPUT);
  pinMode(fanPin,OUTPUT);
}
void loop( ){

/**********************************
* Temperature & Humidity Reading *
**********************************/
  float tempVal;
  float humidVal;

  if(dht_sensor.measure(&tempVal, &humidVal))
  {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(tempVal, 0);
    lcd.print(" C");
    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(humidVal, 0);
    lcd.print("%");
  }
  if (tempVal > 21.50 || humidVal > 75.00){
    analogWrite(fanPin, 255);
  }
  else{
    analogWrite(fanPin, 0);
  }
  
/**********************
* Light Level Reading *
***********************/
  int lSensorVal;
  
  lSensorVal=analogRead(lSensorPin);
  if(lSensorVal > 500){
    digitalWrite(whiteLedPin, HIGH);
  }
  if(lSensorVal < 500){
    digitalWrite(whiteLedPin, LOW);
  }
  
/**********************
* Water Level Reading *
***********************/
  int wLvl;
  
  wLvl=analogRead(wLvlPin);
  if (wLvl > 100){
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
  }
  if (wLvl <= 100){
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
  }
  delay(10);
}
