
int ledpoort1 = 2;
int knopjepoort2 = 3;
unsigned long timestamp;
int delaytime = 3;


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(ledpoort1, OUTPUT);
pinMode(knopjepoort2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(knopjepoort2) ==HIGH) {
    Serial.println(random(1, 6));
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

