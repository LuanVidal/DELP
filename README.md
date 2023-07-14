# | DELP |

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


# ------------------------------------------------------------



# Documentação do DGUS Software - Interface Homem-Máquina (IHM)

## Introdução
O DGUS Software é uma ferramenta poderosa e versátil para o desenvolvimento de Interfaces Homem-Máquina (IHMs). Com o DGUS, é possível criar interfaces gráficas interativas e intuitivas para controlar e monitorar dispositivos eletrônicos, como microcontroladores, placas de desenvolvimento ou sistemas embarcados.

Esta documentação fornece instruções detalhadas sobre como utilizar o DGUS Software para criar projetos de IHM. Ela inclui informações sobre a criação de projetos, configuração de telas, adição de elementos gráficos, definição de ações e geração de arquivos para transferência para o hardware de destino.

## Recursos Principais do DGUS Software
O DGUS Software oferece uma ampla gama de recursos para o desenvolvimento de IHMs avançadas. Alguns dos recursos principais incluem:

- Editor Gráfico: O DGUS possui um editor gráfico intuitivo, que permite criar telas personalizadas, botões, gráficos, medidores, caixas de texto e outros elementos de interface.
- Biblioteca de Objetos: O software fornece uma biblioteca de objetos pré-definidos, como botões, indicadores LED, barras de progresso e medidores, que podem ser facilmente arrastados e soltos nas telas da IHM.
- Suporte a Imagens e Fontes Personalizadas: É possível importar imagens e fontes personalizadas para personalizar a aparência da IHM e fornecer uma experiência visual atraente.
- Comandos e Ações: O DGUS permite atribuir comandos e ações a diferentes elementos da interface, possibilitando a execução de ações como acionar pinos de GPIO, enviar dados por comunicação serial, exibir informações dinâmicas, entre outros.
- Simulação de Projeto: O software possui recursos de simulação que permitem visualizar e testar a IHM antes de transferi-la para o hardware real.

## Processo de Desenvolvimento da IHM

O desenvolvimento de uma IHM com o DGUS Software segue um processo geral que envolve as seguintes etapas:

1. **Criação do Projeto**: Inicie um novo projeto no DGUS Software, selecionando a resolução da tela e as configurações iniciais.
2. **Design da Interface**: Utilize o editor gráfico para criar as telas da IHM, adicionar elementos gráficos, como botões, medidores e caixas de texto, e configurar suas propriedades, como tamanho, posição e comportamento.
3. **Definição de Ações**: Associe comandos e ações a elementos da interface para responder a eventos, como cliques em botões ou alterações de valores. Por exemplo, você pode configurar um botão para acionar um pino de saída ou enviar dados por uma interface de comunicação.
4. **Teste e Depuração**: Utilize a simulação de projeto para testar e depurar a IHM, verificando o funcionamento dos elementos gráficos e das ações atribuídas.
5. **Transferência para o Hardware**: Após concluir o desenvolvimento e teste da IHM, gere os arquivos necessários para transferir o projeto para o hardware de destino. Esses arquivos incluem as configurações da IHM, imagens, fontes e scripts de execução.

## Configuração do Projeto

Antes de iniciar o desenvolvimento da IHM, é necessário configurar o projeto adequadamente no DGUS Software. Siga as etapas abaixo para configurar seu projeto:

1. **Criação do Projeto**: Crie um novo projeto dentro do aplicativo DGUS Dwin, escolhendo a resolução da tela que será utilizada.
2. **Modificação das Configurações**: Após criar o projeto, vá para a página "Welcome Config Generator" e modifique as configurações necessárias para o bom funcionamento da IHM. Recomenda-se alterar o campo "Variable Changes Update" para "Auto", o "ICL Address" para 32 e o "Baud Rate" para 9600.
3. **Geração do Arquivo CFG**: Gere o arquivo de configuração CFG e salve-o com o nome "T5LCFG.CFG".
4. **Organização dos Arquivos**: Mova o arquivo CFG para a pasta do projeto, dentro da pasta "DWIN_SET". As telas do DGUS alocam memória com base na nomenclatura dos arquivos.

## Adição de Elementos Gráficos

Após configurar o projeto, é possível adicionar elementos gráficos à IHM para criar uma interface interativa e informativa. Siga as etapas abaixo para adicionar elementos gráficos ao seu projeto:

1. **Conversão e Adição de Imagens**: Utilize a função "Picture Conversion" para converter as imagens que serão utilizadas na IHM para o formato .bmp. Em seguida, adicione as imagens convertidas utilizando a função "Image Conversion". Certifique-se de que as imagens sigam a nomenclatura adequada, como "00.bmp", "01.bmp", "02.bmp" e assim por diante.
2. **Adição de Imagens no Projeto**: Abra o projeto no DGUS Software e acesse a seção "Image View". Clique no símbolo "+" e adicione as imagens convertidas em .bmp. Essas imagens poderão ser trabalhadas e configuradas conforme necessário.
3. **Definição de Funcionalidades**: Atribua ações e comandos aos elementos gráficos da IHM para torná-los interativos. Por exemplo, configure um botão para acionar um pino de GPIO quando pressionado ou atualizar um valor dinâmico na tela.

# Geração do Arquivo ICL

1. Acesse a página "Welcome" e abra o "DWIN ICL Generator".
2. Selecione as telas já convertidas para o formato .bmp.
3. Clique em "Gerar ICL" e nomeie o arquivo como "32.ICL".
4. Salve o arquivo ICL na pasta "DWIN_SET", dentro da pasta do projeto.

## Adição de Fontes Personalizadas

O DGUS Software permite adicionar fontes personalizadas para personalizar a aparência da IHM. Siga as etapas abaixo para adicionar fontes personalizadas ao seu projeto:

1. **Escolha da Fonte**: Acesse a função "0# Word Bank Generating" no DGUS Software.
2. **Configuração das Propriedades da Fonte**: Escolha a fonte desejada e defina suas propriedades, como tamanho, estilo e alinhamento.
3. **Geração do Arquivo HZK**: Gere o arquivo "0_DWIN_ASC.HZK" e salve-o na pasta "DWIN_SET" dentro da pasta do projeto. Esse arquivo conterá as informações da fonte personalizada.

## Finalização do Projeto e Visualização na Tela

Após concluir o desenvolvimento da IHM, é necessário preparar os arquivos para visualização na tela de destino. Siga as etapas abaixo para finalizar o projeto e visualizá-lo na tela:

1. **Geração dos Arquivos Necessários**: Verifique todas as configurações e elementos gráficos do projeto. Em seguida, vá para a seção "Common" e selecione a opção "Generate". Isso irá gerar todos os arquivos necessários para a IHM.
2. **Transferência para o Hardware**: Para visualizar a IHM na tela, será necessário um cartão microSD com capacidade inferior a 32GB. Copie a pasta "DWIN_SET", gerada na etapa anterior, para o cartão microSD. Insira o cartão microSD na entrada correspondente na tela, com a tela desligada.
3. **Inicialização e Verificação**: Ligue a tela e aguarde o processo de upload, que será indicado por uma tela azul. Após o upload, desligue a energia da tela, remova o cartão microSD e ligue novamente. Seu projeto estará disponível para visualização na tela.

Certifique-se de seguir as etapas descritas acima para criar e visualizar corretamente seu projeto no DGUS Software. Caso precise de mais assistência, consulte a documentação oficial do DGUS Software ou entre em contato com o suporte técnico do fabricante.

Lembre-se de que este documento fornece apenas um guia geral para a criação do projeto e pode ser necessário adaptar as instruções de acordo com as versões específicas do software e do hardware utilizados.

Se você tiver alguma dúvida ou precisar de mais informações, não hesite em entrar em contato.

# Luan Vidal - TCX
