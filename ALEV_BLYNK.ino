// ALEV SENSORU İLE ODADAKI ALEV ALGILANINCA ALARMIN ÇALIŞMASI,TELEFONA BİLDİRİMİN GELMESİ 

//Gerekli kütüphanelerın tanımlanması
#include <ESP8266WiFi.h> // nodemcu esp8266 wifi modulu kutuphanesı
#include <BlynkSimpleEsp8266.h> // blynk uygulaması için kütüphane
#define BLYNK_PRINT Serial  
/*************************************************************************************************************************************/

char auth[] = "*****************"; //blynk uygulamasının tokenı 

char ssid[] = "******************"; //baglanılan wifi ssid 

char pass[] = "******************"; //wifi sifre
/*************************************************************************************************************************************/

int sensorPin = D2; // sensorPin degiskeni D2 pinine ayarlandı
int sensorDeger;
int alevbuzzer = D3; //alevbuzzer D3 pini olarak ayarlandı 
bool bildirim = true; //bool turudeki bildirim degiskeni true olarak ayarlandı
BlynkTimer timer;// timer adında bir nesne oluşturuldu.

/*************************************************************************************************************************************/

//Sensörün verdiği değerleri okuyup verileri uygulamaya gönderiyor.
void sensorOku()
{
  sensorDeger = analogRead(sensorPin); // sensorPin den okunan deger sensorDeger e atanıyor.

  //Sensör verisi 300 ün altına düştüğünde ve bildirim değişkeni true oldugunda döngü çalışır.
  if (sensorDeger < 300 && bildirim) {
    Blynk.notify("DİKKAT! YANGIN VAR! "); //uygulamadan "DİKKAT! YANGIN VAR! " şeklinde  uyarı mesajı alınacak

    //for döngüsünde D3 pinine bağlı buzzerın 5 kere uyarı vermesİ saglanıyor.
    for (int i = 0; i < 5; i++) {
      digitalWrite(alevbuzzer, HIGH);
      delay(300);
      digitalWrite(alevbuzzer, LOW);
      delay(300);
    }
    bildirim = false;
  }

  //sensorDeger 700 ün üzerinde çıktığında döngü çalışır.
  if (sensorDeger > 700) {
    bildirim = true;
  }
}

 /*************************************************************************************************************************************/

void setup()//setup içine 1 kez girilir.
{
  Serial.begin(9600);////Serial Monitor 9600 bound olarak baslatıldı
  Blynk.begin(auth, ssid, pass);// yukarıda verilen auth ,ssid,pass degerleri sırasıyla gelecek.
  Blynk.notify("Cihaz Açıldı"); // Başlangıçta Cihaz Açıldı bildirimi gonderılıyor.
  pinMode(alevbuzzer, OUTPUT); // alevbuzzer pini cıkıs olarak ayarlandı
 
  timer.setInterval(1000L, sensorOku); // Saniyede 1 defa sensorOku fonksiyonu çağırılacak
}
 /*************************************************************************************************************************************/

void loop()
{
  timer.run(); //timer calısacak
  Blynk.run(); // tum etkinlikler blynk uygulaması ile çalısacak 
}
