
#define SensorPin A0 
const int valve = 13;
float sensorValue = 0; 
void setup() { 
 Serial.begin(9600); 
 pinMode(valve,OUTPUT);
} 
void loop() { 
 for (int i = 0; i <= 100; i++) 
 { 
   sensorValue = sensorValue + analogRead(SensorPin); 
   delay(1); 
 } 
 sensorValue = sensorValue/100.0; 
 Serial.println(sensorValue); 
 if( sensorValue >300 ) {
  digitalWrite(valve,LOW);
  delay(2000);
 }
 else
  digitalWrite(valve,HIGH);
 delay(30); 
}
