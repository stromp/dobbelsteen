
int ledpoort1 = 2;
int knopjepoort2 = 3;


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(ledpoort1, OUTPUT);
pinMode(knopjepoort2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

if (digitalRead(knopjepoort2) ==HIGH) {
  Serial.println("hoi");
}
for(int i=1;i<6;i++){

digitalWrite(ledpoort1, HIGH);
Serial.println(i*1000);
delay(i*1000);
digitalWrite(ledpoort1, LOW);
delay(i*1000);
}
}

