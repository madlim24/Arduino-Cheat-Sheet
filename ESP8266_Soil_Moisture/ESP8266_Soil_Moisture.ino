/* 
 Soil Moisture Sensor  
 modified on 21 Feb 2019 
 by Saeed Hosseini @ Electropeak 
 https://electropeak.com/learn/ 
*/
//#define SensorPin A0 
#include <ESP8266WiFi.h>

#define WIFI_SSID "Aviavatar"
#define WIFI_PASSWORD "qwertyui"

const int sensorPin = 4;
float sensorValue = 0; 
void setup() { 
 Serial.begin(9600); 

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting"); 
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
} 
void loop() { 
 for (int i = 0; i <= 100; i++) 
 { 
   sensorValue = sensorValue + analogRead(sensorPin); 
   delay(1); 
 } 
 sensorValue = sensorValue/100.0; 
 Serial.println(sensorValue); 
 delay(30); 
}
