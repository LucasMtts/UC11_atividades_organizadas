Sistema de Monitoramento de Temperatura e Umidade

Este repositório contém o código-fonte para um sistema de monitoramento de temperatura e umidade usando o sensor DHT22 e a plataforma ThingSpeak. O código é desenvolvido em Arduino e é compatível com a placa ESP32.

Pré-requisitos
Antes de executar o código, certifique-se de ter as seguintes bibliotecas instaladas:

DHTesp: Biblioteca para interagir com o sensor DHT22.
WiFi: Biblioteca para se conectar a redes Wi-Fi.
HTTPClient: Biblioteca para realizar solicitações HTTP.

Configuração
Conecte o sensor DHT22 ao pino 13 da placa ESP32.
Defina o nome da rede Wi-Fi e a senha na variável ssid e password, respectivamente.
Substitua a URL da solicitação HTTP na função httpClient.begin() pelo URL fornecido pela plataforma ThingSpeak. Certifique-se de que a URL inclua a chave de API correta e os campos corretos para enviar os dados de temperatura e umidade.

Execução
Carregue o código no ESP32 usando a IDE do Arduino.
Abra o Monitor Serial para visualizar as informações de depuração.
O ESP32 tentará se conectar à rede Wi-Fi especificada. Aguarde até que a conexão seja estabelecida.
Após a conexão bem-sucedida, o ESP32 lerá os dados de temperatura e umidade do sensor DHT22.
Em seguida, ele enviará uma solicitação HTTP para a plataforma ThingSpeak com os valores lidos.
Verifique o Monitor Serial para visualizar o código de status HTTP retornado pela solicitação.
O loop continuará a ser executado a cada 1 segundo, atualizando os dados no ThingSpeak.

Notas adicionais
Certifique-se de que o ESP32 esteja conectado a uma rede Wi-Fi com acesso à Internet para que a solicitação HTTP seja bem-sucedida.
Verifique se a chave de API e a configuração do ThingSpeak estão corretas para que os dados sejam enviados para os campos corretos em sua conta.
Ajuste o tempo de espera delay() no final do loop conforme necessário para alterar a taxa de atualização dos dados enviados.
