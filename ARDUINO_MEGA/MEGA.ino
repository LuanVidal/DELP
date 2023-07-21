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

  float tensaoMapeada =  tensao * 0.0488758553274682; // 0 a 50 - 0.0488758553274682
  float correnteMapeada = corrente * 0.2932551319648094; // 0 a 300 - 0.2932551319648094

  // Envia os dados para o ESP8266 via comunicação serial
  Serial3.print("Tensao:");
  Serial3.print(tensaoMapeada);
  Serial3.print("V | Corrente:");
  Serial3.print(correnteMapeada);
  Serial3.println("A");

  /*
    int acao = 1;
    String matricula = "tcs";
    String mac = "123-456";
    int ordemProducao = 1;
    int atividade = 1;
    int material = 1;

    String mensagem = "Ação: " + String(acao) + ", \"matricula\": \"" + matricula + "\", \"mac\": \"" + mac + "\", \"ordemProducao\": " + String(ordemProducao) + ", \"atividade\": " + String(atividade) + ", \"material\": " + String(material);
    Serial3.println(mensagem);
  
  */
 
  delay(500); // Intervalo de envio dos dados para o ESP8266
}