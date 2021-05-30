#include "DHT.h"
#define DHTTYPE DHT11
#define DHTPIN 7

//Soil Moisture
#define SensorPin A0 
float sensorValue = 0; 

//Ultrasonic sensor
int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long duration, cm, inches;

//Relay
 const int valve = 13;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Humidity & Temperature Sensor \n\n");
  dht.begin();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(valve,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

    if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  Serial.print("Current humidity :" );
  Serial.print(h);
  Serial.print(" % "  );
  Serial.print("Temperature");
  Serial.print(t);
  Serial.println(" C ") ;

  /////////////////////Soil Moisture///////////////////////
   for (int i = 0; i <= 100; i++) 
 { 
   sensorValue = sensorValue + analogRead(SensorPin); 
   delay(1); 
 } 
 sensorValue = sensorValue/100.0; 
 Serial.print("Soil Moisture Value "); 
 Serial.println(sensorValue); 
 if(sensorValue >600) {
 digitalWrite(valve,LOW);
  delay(1000);
 }
 digitalWrite(valve,HIGH);
 delay(2000); 

 ///////////////////////////////////////////////////////////////

 ///////////////////Ultrasonic Sensor/////////////////////////
 // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135

  Serial.print("Water Level Value");
  Serial.print(inches);
  Serial.print("inch, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  

  /*//////////////////////////Relay////////////////////////////////////////////////
  digitalWrite(valve,HIGH);
  delay(2000);
  digitalWrite(valve,LOW);
  delay(5000);*/
  
}
