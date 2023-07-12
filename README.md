# Projeto Conexão ESP Servidor AMQP

## Descrição
O projeto tem como objetivo estabelecer uma conexão entre um dispositivo ESP (como um microcontrolador ESP8266 ou ESP32) e um servidor AMQP (Advanced Message Queuing Protocol). A dificuldade principal reside na necessidade de converter as mensagens recebidas pelo dispositivo ESP, que estão no formato MQTT (Message Queuing Telemetry Transport), para o formato AMQP.

## Tecnologias Utilizadas
- Node.js: Uma plataforma de execução de código JavaScript do lado do servidor.
- ESP8266/ESP32: Microcontroladores populares com suporte a Wi-Fi, amplamente utilizados em projetos IoT.
- MQTT (Message Queuing Telemetry Transport): Protocolo de mensagens leve, projetado para dispositivos com restrições de largura de banda e recursos.
- AMQP (Advanced Message Queuing Protocol): Protocolo de mensagens orientado a fila, amplamente adotado para comunicação em sistemas distribuídos.
- Arduino: Plataforma de desenvolvimento para programação de microcontroladores.

## Solução
Para resolver o desafio de converter as mensagens do formato MQTT para o formato AMQP, utilizaremos um software intermediário escrito em Node.js. O dispositivo ESP enviará mensagens MQTT para o software intermediário, que irá convertê-las e enviá-las para um servidor AMQP. O software intermediário e o código do dispositivo ESP estão fornecidos neste projeto.

## Configuração e Inicialização dos Brokers MQTT e AMQP
Antes de executar o projeto, é necessário configurar e iniciar os brokers MQTT e AMQP. Aqui estão as instruções para iniciar cada um deles:

### Iniciar o Broker MQTT
1. Escolha um broker MQTT para utilizar no projeto, como o Mosquitto, RabbitMQ ou HiveMQ.
2. Instale e configure o broker MQTT de acordo com as instruções específicas do fornecedor.
3. Verifique se o broker MQTT está configurado para usar a porta padrão (1883) ou a porta personalizada especificada no código.
4. Certifique-se de que o broker MQTT esteja em execução e acessível no endereço e porta corretos.

### Iniciar o Broker AMQP
1. Escolha um broker AMQP para utilizar no projeto, como o RabbitMQ, ActiveMQ ou Qpid.
2. Instale e configure o broker AMQP de acordo com as instruções específicas do fornecedor.
3. Verifique se o broker AMQP está configurado para usar a porta padrão (5672) ou a porta personalizada especificada no código.
4. Certifique-se de que o broker AMQP esteja em execução e acessível no endereço e porta corretos.

Certifique-se de que ambos os brokers MQTT e AMQP estejam configurados corretamente e em execução antes de iniciar o software intermediário em Node.js e o código do dispositivo ESP.

## Código e Execução
O projeto é composto por três partes: o software intermediário em Node.js, o código do dispositivo ESP e o código do Arduino. Aqui estão as instruções para executar cada parte:

### Software Intermediário em Node.js
1. Instale o Node.js em seu ambiente de desenvolvimento.
2. Copie o código fornecido do software intermediário em Node.js para um arquivo com extensão `.js`, como `mqtt-to-amqp.js`.
3. Abra um terminal e navegue até o diretório onde o arquivo `.js` está localizado.
4. Execute o comando `npm install mqtt amqplib` para instalar as dependências do projeto.
5. Configure as variáveis `mqttBrokerUrl`, `mqttTopic`, `amqpBrokerUrl` e `amqpQueue` de acordo com suas configurações de brokers MQTT e AMQP.
6. Execute o comando `node mqtt-to-amqp.js` para iniciar o software intermediário.

### Código do Dispositivo ESP
1. Abra o código do dispositivo ESP em uma IDE compatível, como a Arduino IDE.
2. Configure as constantes `SSID`, `PASSWORD`, `BROKER_MQTT`, `BROKER_PORT`, `ID_MQTT` e `TOPIC_PUBLISH` de acordo com suas configurações de rede e brokers MQTT.
3. Faça o upload do código para o dispositivo ESP.

### Código do Arduino
1. Abra o código do Arduino em uma IDE compatível, como a Arduino IDE.
2. Faça qualquer configuração necessária no código, como ajustar a taxa de transmissão serial.
3. Faça o upload do código para o Arduino.

Certifique-se de que todos os dispositivos estejam conectados à mesma rede Wi-Fi e que o software intermediário em Node.js esteja em execução antes de testar a comunicação entre o dispositivo ESP e o servidor AMQP.

## Considerações Finais
Este projeto demonstra uma solução básica para estabelecer a conexão entre um dispositivo ESP e um servidor AMQP, convertendo as mensagens MQTT recebidas. No entanto, é importante considerar as configurações específicas de rede, como SSID, senha, endereços IP e portas, além das permissões de acesso aos brokers MQTT e AMQP.

Lembre-se de consultar a documentação dos brokers MQTT e AMQP escolhidos para obter informações mais detalhadas sobre configuração, segurança e permissões de acesso.

Com esse projeto, você pode explorar diferentes casos de uso e adaptá-lo às suas necessidades específicas. Sinta-se à vontade para experimentar e aprimorar o código e a solução para atender aos requisitos do seu projeto.

Se você tiver alguma dúvida ou precisar de ajuda adicional, não hesite em entrar em contato.
