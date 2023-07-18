#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <TimeLib.h>

const char* SSID = "TCS_2G";
const char* PASSWORD = "33331999";

WiFiClient wifiClient;
PubSubClient MQTT(wifiClient);

//server ntp configuração
const char* ntpServer = "pool.ntp.org";
unsigned long epochTime; 

const char* BROKER_MQTT = "192.168.0.53";
const int BROKER_PORT = 1883;

bool conectBroker = false;
bool conectWifi = false;

#define ID_MQTT "BCI01"
#define TOPIC_PUBLISH "esp_client"

// Declaração das Funções
void mantemConexoes();
void conectaWiFi();
void conectaMQTT();
void enviaValores(float tensao, float corrente);

unsigned long getTime() {
  time_t now;
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    //Serial.println("Failed to obtain time");
    return(0);
  }
  time(&now);
  return now;
}

void setup() {
  Serial.begin(115200);
  conectaWiFi();
  MQTT.setServer(BROKER_MQTT, BROKER_PORT);
  configTime(0, 0, ntpServer);
}

void loop() {
  mantemConexoes();
  MQTT.loop();

  if (Serial.available()) {
    String mensagem = Serial.readStringUntil('\n');
    if (mensagem.startsWith("Tensao:")) {
      int posicaoInicio = mensagem.indexOf(":") + 1;
      int posicaoFim = mensagem.indexOf("V");
      String tensaoStr = mensagem.substring(posicaoInicio, posicaoFim);
      float tensao = tensaoStr.toFloat();

      posicaoInicio = mensagem.indexOf("Corrente:") + 9;
      posicaoFim = mensagem.indexOf("A");
      String correnteStr = mensagem.substring(posicaoInicio, posicaoFim);
      float corrente = correnteStr.toFloat();

      // Enviar valores para o broker MQTT
      enviaValores(tensao, corrente);
    }
  }
}
 
void mantemConexoes() {
  if (!MQTT.connected()) {
    conectaMQTT();
  }
  conectaWiFi();
}

void conectaWiFi() {
  if (WiFi.status() == WL_CONNECTED) {
    return;
  }
  Serial.print("Conectando-se na rede: ");
  Serial.print(SSID);
  Serial.println("  Aguarde!");
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Conectado com sucesso, na rede: ");
  Serial.print(SSID);
  Serial.println("IP obtido: ");
  Serial.print(WiFi.localIP());
}

void conectaMQTT() {
  while (!MQTT.connected()) {
    Serial.print("Conectando ao Broker MQTT: ");
    Serial.println(BROKER_MQTT);
    if (MQTT.connect(ID_MQTT)) {
      Serial.println("Conectado ao Broker com sucesso!");
    } else {
      Serial.println("Nao foi possivel se conectar ao broker.");
      Serial.println("Nova tentativa de conexao em 5s");
      delay(5000);
    }
  }
}

void enviaValores(float tensao, float corrente) {

  epochTime = getTime();

  char mqttMessageTensao[200];
  sprintf(mqttMessageTensao, "{\"id_variavel\": %d, \"valor\": %.2f, \"data_hora\": %ld}", 29, tensao, epochTime);

  char mqttMessageCorrente[200];
  sprintf(mqttMessageCorrente, "{\"id_variavel\": %d, \"valor\": %.2f, \"data_hora\": %ld}", 28, corrente, epochTime);

  MQTT.publish(TOPIC_PUBLISH, mqttMessageTensao);
  MQTT.publish(TOPIC_PUBLISH, mqttMessageCorrente);
  delay(500);
}