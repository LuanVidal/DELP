#include <ESP8266WiFi.h> 
#include <PubSubClient.h>


const char* SSID = "SSID-DA-SUA-REDE";                
const char* PASSWORD = "SENHA-DA-SUA-REDE";
WiFiClient wifiClient;                        
 

const char* BROKER_MQTT = "IP-BROKER-MQTT";
int BROKER_PORT = 1883;                      

#define ID_MQTT  "BCI01"           
#define TOPIC_PUBLISH "esp_client"    
PubSubClient MQTT(wifiClient);       

//Declaração das Funções
void mantemConexoes();  
void conectaWiFi();    
void enviaPacote();    

void conectaMQTT() { 
    while (!MQTT.connected()) {
        Serial.print("Conectando ao Broker MQTT: ");
        Serial.println(BROKER_MQTT);
        if (MQTT.connect(ID_MQTT)) {
            Serial.println("Conectado ao Broker com sucesso!");
        } 
        else {
            Serial.println("Nao foi possivel se conectar ao broker.");
            Serial.println("Nova tentatica de conexao em 5s");
            delay(5000);
        }
    }
}

void enviaValores() {
  float tensao = random(100, 200) / 10.0; 
  float corrente = random(5, 20) / 10.0;

  char mqttMessage[200];
  sprintf(mqttMessage, "Tensao:%.2fV | Corrente:%.2fA", tensao, corrente);
  
  MQTT.publish(TOPIC_PUBLISH, mqttMessage);
  delay(10000);
}


void conectaWiFi() {

  if (WiFi.status() == WL_CONNECTED) {
     return;
  }
        
  Serial.print("Conectando-se na rede: ");
  Serial.print(SSID);
  Serial.println("  Aguarde!");

  WiFi.begin(SSID, PASSWORD); // Conecta na rede WI-FI  
  while (WiFi.status() != WL_CONNECTED) {
      delay(100);
      Serial.print(".");
  }
  
  Serial.println();
  Serial.print("Conectado com sucesso, na rede: ");
  Serial.print(SSID);  
  Serial.print("  IP obtido: ");
  Serial.println(WiFi.localIP()); 
}

void mantemConexoes() {
    if (!MQTT.connected()) {
       conectaMQTT(); 
    }
    
    conectaWiFi(); //se não há conexão com o WiFI, a conexão é refeita
}


void setup() {
       
  Serial.begin(115200);

  conectaWiFi();
  MQTT.setServer(BROKER_MQTT, BROKER_PORT);   
}

void loop() {
  mantemConexoes();
  enviaValores();
  MQTT.loop();
}




