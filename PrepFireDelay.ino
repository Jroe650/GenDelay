/*
  PrepInFireDelay
Passes PrepIn switch status to the Relay 1 directly and Fire is delayed by a fixed time to Relay 2






 */

// constants

const int PrepIn = 1;    
const int ExpIn =  2;     
const int PrepOut = 9;    
const int ExpOut =  11;    
const int WaitTime = 750;

// variables will change:
int PrepState = 0;         
int OldPrepState = 0;
int ExpState = 0;         
int OldExpState = 0;

void setup() {
  
  pinMode(PrepIn, INPUT);
  pinMode(ExpIn, INPUT);
  pinMode(PrepOut, OUTPUT);
  pinMode(ExpOut, OUTPUT);
  digitalWrite(PrepOut, HIGH);
  digitalWrite(ExpOut, HIGH);
  // Serial.begin(9600);
}

void loop() {
  // read the state of the Prep value:
  PrepState = digitalRead(PrepIn);
  
  // check if the Prep has changed
  if (PrepState !=  OldPrepState ) {
     if (PrepState == HIGH && OldPrepState == LOW) {
        // turn Relay on:
       digitalWrite(PrepOut, LOW);  }
      // Serial.println("Prep On"); 
     else {
       // turn LED off:
       digitalWrite(PrepOut, HIGH); }
      // Serial.println("Prep Off"); 
     OldPrepState = PrepState; 
     }

  if (PrepState == HIGH) {
      ExpState = digitalRead(ExpIn);
  
      // check if the Exp has changed
      if (ExpState !=  OldExpState ) {
         if (ExpState == HIGH && OldExpState == LOW) {
            // turn Relay on:
            delay(WaitTime);
            digitalWrite(ExpOut, LOW);}
         else {
        // turn LED off:
           digitalWrite(ExpOut, HIGH);}
      OldExpState = ExpState;       
      }
     }
}

