//Blynk ile evin kapısının kontrolü
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h> // nodemcu esp8266 wifi modulu kutuphanesı
#include <BlynkSimpleEsp8266.h> // blynk uygulaması için kütüphane
#include<Servo.h> // Servo motor(SG90) kütüphanesi

Servo kapi; //kapi adında nesne olustu
/*************************************************************************************************************************************/

char auth[] = "***************"; //blynk uygulamasının tokenı 

char ssid[] = "***************"; //baglanılan wifi ssid 

char pass[] = "****************"; //wifi sifre

/*************************************************************************************************************************************/
void setup()

{
  Serial.begin(9600); //Serial Monitor 9600 bound olarak baslatıldı
  Blynk.begin(auth, ssid, pass); // yukarıda verilen auth ,ssid,pass degerleri sırasıyla gelecek.
  kapi.attach(D5);// kapi nesnesi D5 pini olarak ayarlandı

 }

  

void loop()

{
  Blynk.run(); // tum etkinlikler blynk uygulaması ile çalısacak 
}

BLYNK_WRITE(V0)

{

   kapi.write(param.asInt());

}
