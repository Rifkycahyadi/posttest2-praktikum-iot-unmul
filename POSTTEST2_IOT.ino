
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#define BLYNK_AUTH_TOKEN "c72bZbd0_x-JjGaE3IwxEEwF2NNQQE7N"


char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Universitas Mulawarman";  // type your wifi name
char pass[] = "";  // type your wifi password

#define LEDPIN D8 //Kaki anoda dari LED terhubung ke pin D8 NodeMCU


// Untuk kontroling LED
BLYNK_WRITE(V0) { // V2 adalah pin LED yang sudah kita atur pada Blynk
  digitalWrite(LEDPIN, param.asInt()); // Mengubah nilai LED dari Blynk
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  analogWrite(LEDPIN, pinValue);
  Serial.print("V0 Slider value is: ");
  Serial.println(pinValue);
}

void setup(){
  Serial.begin(115200);
  // Mengatur pin LED
  pinMode(LEDPIN, OUTPUT);
  // Setup Blynk
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

}

void loop(){
  Blynk.run();
}
