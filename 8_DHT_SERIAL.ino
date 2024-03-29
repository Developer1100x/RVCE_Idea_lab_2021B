#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE    DHT11

DHT_Unified dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  Serial.print("Temperature: ");
  Serial.print(event.temperature);
  Serial.println("°C");
  dht.humidity().getEvent(&event);
  Serial.print("Relative Humidity: ");
  Serial.print(event.relative_humidity);
  Serial.println("%");
  delay(1000);
}
