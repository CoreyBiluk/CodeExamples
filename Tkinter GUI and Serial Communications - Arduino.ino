/* Corey Biluk
   March 8, 2021*/

// LED pin variables
int led1 = 8;
int led2 = 9;
int led3 = 10;
int led4 = 11;
// Analog input pin variables
int aIn1 = A0;
int aIn2 = A1;
int aIn3 = A2;
int aIn4 = A3;
// Digital input pin variables
int dIn1 = 2;
int dIn2 = 3;
int dIn3 = 4;
int dIn4 = 5; 

// Variables
int pot1_val;
int pot2_val;
int pot3_val;
int pot4_val;

int digi1_val;
int digi2_val;
int digi3_val;
int digi4_val;

String led_num;                 

void setup() {
  Serial.begin(9600);       // Initialize Serial monitor/communications @ 9600 baudrate
  pinMode(led1, OUTPUT);    // Set output pins
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  pinMode(aIn1, INPUT);     // Set analog input pins
  pinMode(aIn2, INPUT);
  pinMode(aIn3, INPUT);
  pinMode(aIn4, INPUT);
  
  pinMode(dIn1, INPUT);     // Set digital input pins
  pinMode(dIn2, INPUT);
  pinMode(dIn3, INPUT);
  pinMode(dIn4, INPUT);
}

void loop() 
{
  if(Serial.available() == 0)                     // Wait for serial communication from Pi
  {
     led_num = Serial.readStringUntil('\n');      // Read communication from Pi up to carriage return
     if (led_num == "LED1")                       // If message is for LED #1 do:
     {
      digitalWrite(led1, HIGH);                   // Turn on LED 1
      delay(400);                                 // Keep LED on for 400 ms
      digitalWrite(led1, LOW);                    // Turn off LED 1
     }
     
     else if (led_num == "LED2")                  // If message is for LED #2 do:
     {
      digitalWrite(led2, HIGH);                   // Turn on LED 2
      delay(400);                                 // Keep LED on for 400 ms
      digitalWrite(led2, LOW);                    // Turn off LED 2
     }
     
     else if (led_num == "LED3")                  // If message is for LED #3 do:
     {
      digitalWrite(led3, HIGH);                   // Turn on LED 3
      delay(400);                                 // Keep LED on for 400 ms
      digitalWrite(led3, LOW);                    // Turn off LED 3
     }
     
     else if (led_num == "LED4")                  // If message is for LED #4 do:
     {
      digitalWrite(led4, HIGH);                   // Turn on LED 4
      delay(400);                                 // Keep LED on for 400 ms
      digitalWrite(led4, LOW);                    // Turn off LED 4
     }
     
     else                                         // Section to read inputs
     {
      pot1_val = analogRead(aIn1);                // Read value of pot1
      pot2_val = analogRead(aIn2);                // Read value of pot2
      pot3_val = analogRead(aIn3);                // Read value of pot3
      pot4_val = analogRead(aIn4);                // Read value of pot4
      
      digi1_val = digitalRead(dIn1);              // Read value of button1
      digi2_val = digitalRead(dIn2);              // Read value of button2
      digi3_val = digitalRead(dIn3);              // Read value of button3
      digi4_val = digitalRead(dIn4);              // Read value of button4
      
      Serial.print(pot1_val);                     // Print pot1 value to serial
      Serial.print("/");                          // Print "/" to serial to seperate input values.  The string will be split when recieved by the Pi.
      Serial.print(pot2_val);                     // Print pot2 value to serial
      Serial.print("/");                          
      Serial.print(pot3_val);                     // Print pot3 value to serial
      Serial.print("/");                         
      Serial.print(pot4_val);                     // Print pot4 value to serial
      Serial.print("/");                          
      
      Serial.print(digi1_val);                    // Print button1 state to serial
      Serial.print("/");                          
      Serial.print(digi2_val);                    // Print button2 state to serial
      Serial.print("/");                          
      Serial.print(digi3_val);                    // Print button3 state to serial
      Serial.print("/");                         
      Serial.println(digi4_val);                  // Print button4 state to serial
     }   
  }
  Serial.flush();                                 // Flush serial comms line
  delay(100);                                     // Short delay
} 
 
