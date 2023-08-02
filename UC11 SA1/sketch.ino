



#include <LiquidCrystal_I2C.h> // Biblioteca para controle de display LCD I2CA
#include <DHTesp.h> // Biblioteca para leitura do sensor DHT22

int pinoLed = 14; // Pino do LED vermelho
int LedVerde = 12; // Pino do LED verde
int cont = 0; // Variável de contador
const int pinoSensor = 13; // Pino do sensor DHT22

DHTesp sensor; // Objeto do tipo DHTesp para controlar o sensor DHT22

LiquidCrystal_I2C display(0X27, 20, 4); // Objeto para controle do display LCD

void setup() {
  // Inicialização do programa
  Serial.begin(115200); // Inicializa a comunicação serial a 115200 bps

  pinMode(pinoLed, OUTPUT); // Define o pino do LED vermelho como saída
  pinMode(LedVerde, OUTPUT); // Define o pino do LED verde como saída

  sensor.setup(pinoSensor, DHTesp::DHT22); // Inicializa o sensor DHT22

  display.init(); // Inicializa o display LCD
}

void loop() {
  // Código principal, executado repetidamente

  delay(10); // Atraso de 10 milissegundos

  int temp = sensor.getTemperature(); // Lê a temperatura do sensor DHT22
  int humi = sensor.getHumidity(); // Lê a umidade do sensor DHT22

  // Exibe a temperatura no display LCD
  display.setCursor(0, 0);
  display.print("TEMPERATURA:");
  display.setCursor(13, 0);
  display.print(temp);
  display.setCursor(15, 0);
  display.print("C");
  display.setCursor(0, 1);
  display.print("INFO:");

  // Exibe a umidade no display LCD
  display.setCursor(0, 2);
  display.print("UMIDADE:");
  display.setCursor(13, 2);
  display.print(humi);
  display.setCursor(15, 2);
  display.print("%");
  display.setCursor(0, 3);
  display.print("INFO:");

  // Verifica se a umidade está acima de 70% ou a temperatura está acima de 35 graus Celsius
  if(humi > 70 or temp > 35){
    digitalWrite(pinoLed, HIGH); // Acende o LED vermelho
    digitalWrite(LedVerde, LOW); // Desliga o LED verde
  }else{
    digitalWrite(pinoLed, LOW); // Desliga o LED vermelho
    digitalWrite(LedVerde, HIGH); // Acende o LED verde
  }

  // Exibe "CRITICO" ou "NORMAL" no display LCD dependendo da temperatura
  if(temp > 35){
    display.setCursor(12, 1);
    display.print("CRITICO");
  }else{
    display.setCursor(12, 1);
    display.print("NORMAL ");
  }

  // Exibe "CRITICO" ou "NORMAL" no display LCD dependendo da umidade
  if(humi > 70){
    display.setCursor(12, 3);
    display.print("CRITICO");
  }else{
    display.setCursor(12, 3);
    display.print("NORMAL ");
  }
}
