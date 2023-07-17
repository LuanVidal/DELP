const mqtt = require('mqtt');
const amqp = require('amqplib');

// Configurações do MQTT Broker
const mqttBrokerUrl = 'mqtt://localhost:1883';
const mqttTopic = 'esp_client';

// Configurações do AMQP Broker
const amqpBrokerUrl = 'amqp://localhost:5672';
const amqpQueue = 'remote';

//const nomeUsuario = 'W4nuCL2HK09PrG8H';
//const senha = '7NXYX2gGYHGxCIBKoN3UtsLfRh';


// Conectando ao MQTT Broker
const mqttClient = mqtt.connect(mqttBrokerUrl);

mqttClient.on('connect', () => {
  console.log('Conectado ao MQTT Broker');

  mqttClient.subscribe(mqttTopic, (err) => {
    if (err) {
      console.error('Erro ao se inscrever no tópico MQTT:', err);
    }
  });
});

mqttClient.on('message', (topic, message) => {
  // Convertendo o payload MQTT para uma string
  const payload = message.toString();

  // Conectando ao AMQP Broker
    // amqpBrokerUrl, { username: nomeUsuario, password: senha }
  amqp.connect(amqpBrokerUrl)
    .then((amqpConnection) => {
      console.log('Conectado ao AMQP Broker');

      // Criando um canal no AMQP Broker
      return amqpConnection.createChannel()
        .then((channel) => {
          // Enviando a mensagem para a fila AMQP
          channel.sendToQueue(amqpQueue, Buffer.from(payload));
          console.log('Mensagem convertida e enviada para a fila AMQP:', payload);

          // Fechando a conexão com o AMQP Broker
          return channel.close();
        })
        .finally(() => {
          // Fechando a conexão com o AMQP Broker
          amqpConnection.close();
        });
    })
    .catch((err) => {
      console.error('Erro ao conectar ao AMQP Broker:', err);
    });
});