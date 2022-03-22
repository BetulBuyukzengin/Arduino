//brandanın uygulamayla kontrolu
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>

#include <Servo.h>



Servo branda;



char auth[] = "wYUB5t1DbhHKflhvzEmR1MezZwCK5vno";

char ssid[] = "Xiaomi_DA23";

char pass[] = "Y3VW7EXWNAFT";



void setup()

{

  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);



  branda.attach(D2);   

 }

  

void loop()

{

  

  Blynk.run();

  

}

BLYNK_WRITE(V0)

{

   branda.write(param.asInt());

}
