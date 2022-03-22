#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<HCSR04.h>
#define trig D6
#define echo D7
HCSR04 hc(trig,echo);


char auth[] = "wYUB5t1DbhHKflhvzEmR1MezZwCK5vno";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Xiaomi_DA23";
char pass[] = "Y3VW7EXWNAFT";
 

BlynkTimer timer;

void sendSensor()
{
  int c = hc.dist();
  if ( c == 0 ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
 
  Blynk.virtualWrite(V5, c);  // select virtual pin (v5) in blynk app
  
 
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();    }
