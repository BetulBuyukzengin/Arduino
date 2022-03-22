// Yagmur algılanınca brandanın acılması
#include <Servo.h>

Servo myservo;  // nesne olustu
 int yagmur = 0;               // "yagmur" adındaki değişkene başlangıç için 0 değeri verdik.
int sensor = A0;              // Yağmur sensörü Analog A0 pinine tanımlandı.

// int myservoPin=D0;   pini bu sekilde de tanımlayabiliriz. attach içine 0 yerine myservoPin yazarız.

int derece=0;
void setup() {
   pinMode(sensor, INPUT);     // sensor giriş pini olarak tanımlandı
 Serial.begin(9600);         // Serial monitör aktifleştirilfi
 Serial.println("Yağış Durumu:");
 Serial.println("-------------");
  myservo.attach(13);  // D0=16 , D1=5 , D2=4 , D3=0 , D4=2 , D5=14 , D6=12 , D7=13 , D8=15
  delay(200); // 200 ms bekle
}

void loop() {

yagmur = analogRead(A0);      // A0 pin değerini "yagmur" degiskenine atandı

if(yagmur > 301 && yagmur <= 900){ //yagmur > 301 && yagmur <= 900
Serial.println("Yagmur yagiyor!");
for(derece=0;derece<=180;derece+=1) // 0 dereceden  180 dereceye kadar ileri 
 {
    myservo.write(derece);
    delay(15); // 15 ms bekle
  }
         if (yagmur > 901) {              
      Serial.println("Yagmur yok!");
      for(derece=180;derece>=0;derece-=1) // 180 dereceden 0 dereceye kadar geriye 
        {
          myservo.write(derece);
          delay(15); // 15 ms bekle
          }

delay(1000); // 1000 ms bekle

}
}
 
 
}

  
