#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST"; 
const char* password = ""; 
const char* mqtt_server = "mqtt-dashboard.com"; 
const int port = 1883;

WiFiClient espClient;       
PubSubClient client(espClient); 

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Conectando");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Conectado à rede Wi-Fi com sucesso! IP local: ");
  Serial.println(WiFi.localIP());
  client.setServer(mqtt_server, port);
  while (!client.connected()){
    String clientId = "EspClient-";
    clientId += String(random(0xffff), HEX);
    client.connect(clientId.c_str());
   }
}

void loop() {
  delay(1000);
  client.publish("topicodeteste10","exemplo");
}

