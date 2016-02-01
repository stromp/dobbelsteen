
int poort1 = 2;


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(poort1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=1;i<6;i++){

digitalWrite(poort1, HIGH);
Serial.println(i*1000);
delay(i*1000);
digitalWrite(poort1, LOW);
delay(i*1000);
}
}

