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
}