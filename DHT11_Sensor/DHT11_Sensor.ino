#include "DHT.h"
#define DHTTYPE DHT11
#define DHTPIN A1

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Humidity & Temperature Sensor \n\n");
  dht.begin();

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
  delay(5000);

}
