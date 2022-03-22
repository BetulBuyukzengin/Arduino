// DHT11 kullanarak odanın sıcaklığı ve neminin ölçülmesi
#define BLYNK_PRINT Serial    
#include <SPI.h>
#include <ESP8266WiFi.h>// nodemcu esp8266 wifi modulu kutuphanesı
#include <BlynkSimpleEsp8266.h>// blynk uygulaması için kütüphane
#include <DHT.h> //DHT kutuphanesı
#define DHTPIN D3 // DHT nin Digital pin D3 olarak ayarlandı
#define DHTTYPE DHT11 // DHT ın tipi DHT11 tanımlandı
DHT dht(DHTPIN, DHTTYPE);

/*************************************************************************************************************************************/

char auth[] = "wYUB5t1DbhHKflhvzEmR1MezZwCK5vno"; //blynk uygulamasının tokenı 

char ssid[] = "Xiaomi_DA23"; //baglanılan wifi ssid 

char pass[] = "Y3VW7EXWNAFT"; //wifi sifre
/*************************************************************************************************************************************/


void sendSensor()
{
  float nem = dht.readHumidity();
  float sicaklik = dht.readTemperature(); 

  if (isnan(nem) || isnan(sicaklik)) {
    return;
  }
  
  Blynk.virtualWrite(V3, nem);  //V3 nem için
  Blynk.virtualWrite(V2, sicaklik);  //V2 sicaklik için
}
/*************************************************************************************************************************************/

void setup()
{
  Serial.begin(9600); //Serial Monitor 9600 bound olarak baslatıldı
  Blynk.begin(auth, ssid, pass);// yukarıda verilen auth ,ssid,pass degerleri sırasıyla gelecek.

  dht.begin();

}
/*************************************************************************************************************************************/

void loop()
{
  Blynk.run();//tum etkinlikler blynk uygulaması ile çalısacak
}
