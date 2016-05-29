
//een int is een eenheid van 8 bits, je moet zuinig zijn met geheugen, dus daarom beperk je het zoveel mogelijk en geef je dat hier aan.
int ledpoort1 = 3;
int ledpoort2 = 4;
int ledpoort3 = 5;
int ledpoort4 = 6;
int ledpoort5 = 7;
int ledpoort6 = 8;
int ledpoort7 = 9;

int knopjepoort2 = 2;
int delaytime = 3;

//unsigned is een variabele die niet negatief kan zijn, 
//long is 2x zo lang als een heel getal; 
unsigned long timestamp;

//nieuw
int ledState = LOW;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 100;    // the debounce time; increase if the output flickers
int randomgetal;


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
  // met serial stuurt hij de output ook terug naar de computer, je kan het vinden in het document met dit nummer
  pinMode(ledpoort1, OUTPUT);
  pinMode(ledpoort2, OUTPUT);
  pinMode(ledpoort3, OUTPUT);
  pinMode(ledpoort4, OUTPUT);
  pinMode(ledpoort5, OUTPUT);
  pinMode(ledpoort6, OUTPUT);
  pinMode(ledpoort7, OUTPUT);
  pinMode(knopjepoort2, INPUT);
  digitalWrite(ledpoort1, ledState);
  digitalWrite(ledpoort2, ledState);
  digitalWrite(ledpoort3, ledState);
  digitalWrite(ledpoort4, ledState);
  digitalWrite(ledpoort5, ledState);
  digitalWrite(ledpoort6, ledState);
  digitalWrite(ledpoort7, ledState);
}

void loop() {
  // put your main code here, to run repeatedly:

//dit stuk is bedoeld om te debouncen
  int reading = digitalRead(knopjepoort2);
  //zodra de status van de knop anders is dan daarvoor begint hij tijd te registreren

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        generateNumber();
      }
    }
  }
    // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
}

void generateNumber() {
  for(int counter = 0; counter <15; counter++) {
    displayNumber (random(1,7));
    delay (100);
  }
  int final_number(random(1,7));
  for (int counter = 0; counter <5;counter++) {
    displayNumber(final_number);
    delay (400);
    clearallpins();
    delay(400);
    displayNumber(final_number);
  }
}

void displayNumber (int getal) {
   Serial.println(getal);
        switch (getal) {
  case 1:   digitalWrite(ledpoort1, LOW);
            digitalWrite(ledpoort2, LOW);
            digitalWrite(ledpoort3, LOW);
            digitalWrite(ledpoort4, LOW);
            digitalWrite(ledpoort5, LOW);
            digitalWrite(ledpoort6, LOW);
            digitalWrite(ledpoort7, HIGH);
    break;
  case 2:   clearallpins();
            digitalWrite(ledpoort1, HIGH);
            digitalWrite(ledpoort6, HIGH);
    break;
  case 3:   clearallpins();
            digitalWrite(ledpoort1, HIGH);
            digitalWrite(ledpoort6, HIGH);
            digitalWrite(ledpoort7, HIGH);
    break;
  case 4:   clearallpins();
            digitalWrite(ledpoort1, HIGH);
            digitalWrite(ledpoort2, HIGH);
            digitalWrite(ledpoort5, HIGH);
            digitalWrite(ledpoort6, HIGH);          
    break;
  case 5:   clearallpins();
            digitalWrite(ledpoort1, HIGH);
            digitalWrite(ledpoort2, HIGH);
            digitalWrite(ledpoort5, HIGH);
            digitalWrite(ledpoort6, HIGH);
            digitalWrite(ledpoort7, HIGH);        
    break;
    case 6:   clearallpins();
            digitalWrite(ledpoort1, HIGH);
            digitalWrite(ledpoort2, HIGH);
            digitalWrite(ledpoort5, HIGH);
            digitalWrite(ledpoort6, HIGH); 
            digitalWrite(ledpoort3, HIGH);
            digitalWrite(ledpoort4, HIGH);
    break;
      
    }
}      


      
      
     

void clearallpins () {
  digitalWrite(ledpoort1, LOW);
  digitalWrite(ledpoort2, LOW);
  digitalWrite(ledpoort3, LOW);  
  digitalWrite(ledpoort4, LOW);  
  digitalWrite(ledpoort5, LOW);
  digitalWrite(ledpoort6, LOW);
  digitalWrite(ledpoort7, LOW);
}


/*
//oud  
//dit stuk is voor de dobbelsteen
  
  if (digitalRead(knopjepoort2) ==HIGH) {
  

}  
    
    
  }
}

  if(timestamp==0 ||(((millis()-timestamp)>(delaytime*1000)) && ((millis()-timestamp)<(delaytime*1000 *2))))  {
    digitalWrite(ledpoort1, HIGH);
  }
 
  if ((millis()-timestamp)>(delaytime*1000*2)){
    digitalWrite(ledpoort1, LOW);
     
    Serial.println(delaytime*1000*2);
    timestamp = millis();
  }
  


}
*/
