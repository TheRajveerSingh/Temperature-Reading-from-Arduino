#define BLYNK_TEMPLATE_ID "TMPL3zeB2UBik"
#define BLYNK_TEMPLATE_NAME "DHT Iot Sensor"
#define BLYNK_AUTH_TOKEN "2vZaI3gLm2XSgCamHKpFTw5MHrMIaRa2"

#include <DHT.h>
#include <BlynkSimpleEsp8266.h>

#define DHTPIN 4
#define DHTTYPE DHT11

char auth[] = "2vZaI3gLm2XSgCamHKpFTw5MHrMIaRa2";
char ssid[] = "Galaxy M012243";
char pass[] = "zrfc7857";

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT Test Sucessful!");
  Blynk.begin(auth, ssid, pass);
  Serial.println("Blynk connected successfully");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println("Something is not working as intended");
    return;
  }
  Serial.println("Humidity: ");
  Serial.print(h);
  Serial.println("Temperature");
  Serial.print(t);
  Serial.print("degrees celsius.");
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  delay(1000);
}
