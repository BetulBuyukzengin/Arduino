// GAZ SENSORU SAYESINDE ODADAKI GAZ ALGILANINCA ALARMIN ÇALIŞMASI,TELEFONA BİLDİRİMİN GELMESİ  VE PENCERELERIN AÇIMASI 

//Gerekli kütüphanelerın tanımlanması
#include <ESP8266WiFi.h> // nodemcu esp8266 wifi modulu kutuphanesı
#include <BlynkSimpleEsp8266.h> // blynk uygulaması için kütüphane
#define BLYNK_PRINT Serial   
#include<Servo.h> // Servo motor(SG90) kütüphanesi

/*************************************************************************************************************************************/

char auth[] = "wYUB5t1DbhHKflhvzEmR1MezZwCK5vno"; //blynk uygulamasının tokenı 

char ssid[] = "Xiaomi_DA23"; //baglanılan wifi ssid 

char pass[] = "Y3VW7EXWNAFT"; //wifi sifre

/*************************************************************************************************************************************/

BlynkTimer timer;// timer adında bir nesne oluşturuldu.
Servo penceremotor; //penceremotor adındaki nesne pencereyi hareket ettirmek için tanımlandı

int GazSensoru = A0; // GazSensoru degiskeni A0 pinine ayarlandı
int data = 0; //data degiskenine 0 degeri verildi
int gazbuzzer = D0; // gazbuzzer D0 pini olarak ayarlandı 

/*************************************************************************************************************************************/

void getSendData() //getSendData adında fonksiyon olusturuldu veriler okunup uygulamaya gonderiliyor
{
     data = analogRead(GazSensoru); //GazSensoru den okunan deger data ya aktarıldı
     Blynk.virtualWrite(V4, data); //blynk uygulamasında gelen gaz mıktarını ogrenmek ıcın ,ona gore esik degerini ayarlıyoruz 
  
       if (data > 380) //veri 370 dan buyukse if in içine girer 
       {
         Serial.print("gaz var!"); // arduınonun serial port ekranında uyarı gelecek
         Blynk.notify("Dikkat !!! Gaz Çıkışı var !"); // uygulamadan "Dikkat !!! Gaz Çıkışı var !" şeklinde  uyarı mesajı alınacak
         penceremotor.write(90); //180 derecelik açı ile servo hareket edecek ve pencere acılacak
      
         tone(gazbuzzer, 1000, 200);// alarm olarak kullanılan buzzerın ses tonları ayarlandı
       }
       
       else // veri 370 dan buyuk degılse else in içine girecek 
       {
         noTone(gazbuzzer); //alarm çalışmayacak
       }
}

/*************************************************************************************************************************************/

void setup() //setup içine 1 kez girilir.
{
  Serial.begin(9600); //Serial Monitor 9600 bound olarak baslatıldı
  Blynk.begin(auth, ssid, pass); // yukarıda verilen auth ,ssid,pass degerleri sırasıyla gelecek.
  pinMode(gazbuzzer ,OUTPUT); // gazbuzzer cikis pini  yapıldı
  penceremotor.attach(14); // servo motor D5 pini olarak ayarlandı

 timer.setInterval(1000L, getSendData);// Saniyede 1 defa getSendData fonksiyonu çağırılacak

}
 /*************************************************************************************************************************************/

void loop() 
{
  timer.run(); //timer calısacak
  Blynk.run(); // tum etkinlikler blynk uygulaması ile çalısacak 
}
 
