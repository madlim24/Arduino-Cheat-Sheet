 const int valve = 13;
 void setup() {
pinMode(valve,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(valve,HIGH);
  delay(2000);
  digitalWrite(valve,LOW);
  delay(5000);
}
