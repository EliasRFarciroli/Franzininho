#include <WiFi.h> //lib para configuração do Wifi
#include <ESPmDNS.h> //lib necessária para comunicação network
#include <WiFiUdp.h> //lib necessária para comunicação network
#include <ArduinoOTA.h> //lib do ArduinoOTA 

/*=========================== Neo pixel lib ===============================*/
#include <Adafruit_NeoPixel.h>
#define LED_PIN 18 //Pino do NeoPixel
#define BRILHO 50

Adafruit_NeoPixel strip(1, LED_PIN, NEO_GRBW + NEO_KHZ800);
//strip.Color(  RED,   GREEN,   BLUE, TRUE WHITE);
uint32_t apagado = strip.Color(  0,   0,   0);
uint32_t vermelho = strip.Color(  255,   0,   0);
uint32_t verde = strip.Color(  0,   255,   0);
uint32_t azul = strip.Color(  0,   0,   255);
uint32_t roxo = strip.Color(  153,   51,   153);
uint32_t LimeGreen = strip.Color( 50, 205, 50);
/*################################## ID e senha da rede ###################################*/

  const char* ssid = "ID da sua rede";
  const char* password = "senha da sua rede";

/*################################## ACIONA LED ##########################################*/
void led_RGB(uint32_t cor) {
  strip.setPixelColor(0, cor);
  strip.show();
}

void apaga_led() {
  strip.setPixelColor(0, apagado);
  strip.show();
}
/*######################################################################################*/

void setup()
{

  strip.begin();           // Inicializa NeoPixel
  strip.show();            // Turn OFF all pixels
  strip.setBrightness(BRILHO);

  //inicia serial com 115200 bits por segundo
  Serial.begin(115200);

  Serial.println("Inicializando");

  //define wifi como station (estação)
  WiFi.mode(WIFI_STA);

  //inicializa wifi
  WiFi.begin(ssid, password);

  //enquanto o wifi não for conectado aguarda
  while (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    //caso falha da conexão, reinicia wifi
    Serial.println("Falha de conexão! Reiniciando...");
    delay(5000);
    ESP.restart();
  }

  // Define o hostname (opcional)
  ArduinoOTA.setHostname("Franzininho Wifi");

  //define o que será executado quando o ArduinoOTA iniciar
  ArduinoOTA.onStart( startOTA ); 

  //define o que será executado quando o ArduinoOTA terminar
  ArduinoOTA.onEnd( endOTA ); 

  //define o que será executado quando o ArduinoOTA estiver gravando
  ArduinoOTA.onProgress( progressOTA ); 

  //define o que será executado quando o ArduinoOTA encontrar um erro
  ArduinoOTA.onError( errorOTA );

  //inicializa ArduinoOTA
  ArduinoOTA.begin();

  //exibe pronto e o ip utilizado pelo ESP

  Serial.println("PRONTO");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());


}

//#######################################################################################
//funções de exibição dos estágios de upload (start, progress, end e error) do ArduinoOTA
void startOTA()
{
  String type;

  
  if (ArduinoOTA.getCommand() == U_FLASH)
    type = "flash";
  else  
    type = "filesystem"; // U_SPIFFS

  
  Serial.println("Iniciar Atualização " + type);

  led_RGB(LimeGreen);
  delay(300);
  apaga_led();
  delay(300);
  led_RGB(LimeGreen);
  delay(300);
  apaga_led();
}

//exibe mensagem
void endOTA()
{
  Serial.println("\nEnd");
}

//exibe progresso em porcentagem
void progressOTA(unsigned int progress, unsigned int total)
{
  Serial.printf("Progresso: %u%%\r", (progress / (total / 100)));
}

//caso aconteça algum erro, exibe especificamente o tipo do erro
void errorOTA(ota_error_t error)
{
  Serial.printf("Erro[%u]: ", error);

  if (error == OTA_AUTH_ERROR)
    Serial.println("Auth Failed");
  else if (error == OTA_BEGIN_ERROR)
    Serial.println("Falha nop começo");
  else if (error == OTA_CONNECT_ERROR)
    Serial.println("Falha de conexão");
  else if (error == OTA_RECEIVE_ERROR)
    Serial.println("Falha de recebimento");
  else if (error == OTA_END_ERROR)
    Serial.println("Falha no final");
}
//############################## Exemplo com o neopixel ##################################
void teste_led() {
  led_RGB(vermelho);
  delay(300);
  apaga_led();
  delay(300);
  led_RGB(verde);
  delay(300);
  apaga_led();
  delay(300);
  led_RGB(azul);
  delay(300);
  apaga_led();
  delay(300);
  led_RGB(roxo);
  delay(300);
  apaga_led();
  delay(300);
}

//#######################################################################################
void loop()
{
  //Handle é descritor que referencia variáveis no bloco de memória
  //Ele é usado como um "guia" para que o ESP possa se comunicar com o computador pela rede
  ArduinoOTA.handle();

  teste_led();

}
