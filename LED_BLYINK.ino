//uygulama ıle oda aydınlatma 
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>



char auth[] = "wYUB5t1DbhHKflhvzEmR1MezZwCK5vno";

char ssid[] = "Xiaomi_DA23";

char pass[] = "Y3VW7EXWNAFT";



void setup()

{

  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
 }

  

void loop()
 
{

  

  Blynk.run();

  

}
