#include <DS3231.h>
#include "DHT.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <driver/adc.h>

Adafruit_SSD1306 dsp(-1);//cria o objeto do display para i2c


/*                                               Variaveis                                               */

DS3231 relogio;
RTCDateTime dt;
int Hora, Minuto, Segundo , Dia, Mes, Ano;
int t, h;
int Sen1, Sen2, media;
boolean statusBoia;
/*=======================================================================================================*/
/*                                               Pinos                                                   */

#define DHTPIN 6     // Digital pin connected to the DHT sensor
#define Boia 7
#define Bomba 4
const int Sensor1 = 1;
const int Sensor2 = 2;
// SDA  8
// SCL  9
/*=======================================================================================================*/
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

/*                                               Funções                                                 */
void escreveHora() {

  dsp.clearDisplay();
  dsp.setCursor(0, 0);
  dsp.print(F("Data: "));
  dsp.print(dt.day);
  dsp.print(F("-"));
  dsp.print(dt.month);
  dsp.print(F("-"));
  dsp.println(dt.year);

  dsp.print(F("Hora: "));
  dsp.print(dt.hour);
  dsp.print(F(":"));
  dsp.print(dt.minute);
  dsp.print(F(":"));
  dsp.println(dt.second);
  dsp.print(F("Boia: "));
  dsp.println(statusBoia);
  dsp.display();
  delay(1000);
}

void escreveTemp() {
  dsp.setTextColor(WHITE);//define o texto para branco (no display ficara azul)
  dsp.setTextSize(1);
  dsp.clearDisplay();
  dsp.setCursor(0, 0);
  dsp.print(F("Umidade: "));
  dsp.print(h);
  Serial.println("h" + String(h));
  dsp.println(F("% "));
  dsp.print(F("Temp: "));
  dsp.print(t);
  Serial.println("t" + String(t));
  dsp.println(F(" C "));
  dsp.print(F("S1: "));

  int sen1 = analogRead(Sensor1);
 
  Serial.println("sa" + String(sen1));
  dsp.println(sen1);
  delay(300);
  dsp.print(F("S2: "));
  
  int sen2 = analogRead(Sensor2);
  Serial.println("sb" + String(sen2));
  dsp.println(sen2);

  dsp.display();//mostra as alteracoes no display, sem isso nao ira mostrar nada!!
  delay(1000);
}

void escreve()
{

  if (isnan(h) || isnan(t) ) {
    // Serial.println(F("Failed to read from DHT sensor!"));

  }

  escreveTemp();
  escreveHora();

}

void irrigar() {
  h = dht.readHumidity();
  t = dht.readTemperature();
  Sen1 = analogRead(Sensor1);
  delay(300);
  Sen2 = analogRead(Sensor2);
  dt = relogio.getDateTime();
  Hora = dt.hour;
  Minuto = dt.minute;
  Segundo = dt.second;
  Dia = dt.day;
  Mes = dt.month;
  Ano = dt.year;
  statusBoia = digitalRead(Boia);
  escreve();
  media = (Sen1 + Sen2) / 2;

  if ( ((t <= 28) && (Hora >= 5) && (Hora <= 11) && (media >= 600)) || ((Hora >= 17) && (Hora <= 19) && (media >= 600)) ) {
    if (statusBoia == false) {
      digitalWrite(Bomba, HIGH);
    }
  }
  else {
    digitalWrite(Bomba, LOW);
  }
  escreve();
}

/*=======================================================================================================*/
void setup() {
  Serial.begin(9600);
  relogio.begin();
  // relogio.setDateTime(__DATE__, __TIME__); //atualiza hora e data de acordo com o momento de compilação
 relogio.setDateTime(2021, 12, 31, 6, 59, 30); //(ANO), (MÊS), (DIA), (HORA), (MINUTOS), (SEGUNDOS)
  analogReadResolution ( 10 ); // resolução de 10 bits necessario para a leitura analogica.
  analogSetPinAttenuation (Sensor1, ADC_11db); // Atenuação de 6db no pino
  analogSetPinAttenuation (Sensor2, ADC_11db); // Atenuação de 6db no pino


  dht.begin();
  dsp.begin(SSD1306_SWITCHCAPVCC, 0x3C);//inicia o display com endereco padrao
  dsp.clearDisplay();//limpa a tela

  pinMode(Boia, INPUT);
  pinMode(Bomba, OUTPUT);


}

void loop() {
  // Wait a few seconds between measurements.

  irrigar();


}
