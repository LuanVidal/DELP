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

Esperamos que esta documentação seja útil para o desenvolvimento de suas IHMs com o DGUS Software. Se você tiver alguma dúvida ou precisar de mais informações, não hesite em entrar em contato.
