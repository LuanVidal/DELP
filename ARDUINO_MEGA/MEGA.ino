void setup() {
  Serial.begin(115200);
  Serial3.begin(115200);
}

void loop() {

  if (Serial3.available()) {
    //Leitura de um byte.
    char data = Serial3.read();
    //Imprima o mesmo dado pela porta usb.
    Serial.print(data);
    //Acrescente o caractere recebido a string de mensagem.
    delay(10);
  }

  float tensao = analogRead(A0);
  float corrente = analogRead(A1);

  float tensaoMapeada =  tensao * 0.0048875855327468;
  float correnteMapeada = corrente * 0.0048875855327468;

  // Envia os dados para o ESP8266 via comunicação serial
  Serial3.print("Tensao:");
  Serial3.print(tensaoMapeada);
  Serial3.print("V | Corrente:");
  Serial3.print(correnteMapeada);
  Serial3.println("A");
 
  delay(500); // Intervalo de envio dos dados para o ESP8266
}