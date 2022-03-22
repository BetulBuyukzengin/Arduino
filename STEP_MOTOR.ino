//uygulama ıle kontrol edılen klima,vantılator 
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>



char auth[] = "************";

char ssid[] = "************";

char pass[] = "*************";


int motorPin1 = D0;    
int motorPin2 = D1;    
int motorPin3 = D2;    
int motorPin4 = D3;    

int motorSpeed = 1200;  //step hızı
int adim = 0;          // adım sayısı
int adimSayisi = 512; // adımların tam devir deki adım sayısı
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};

void setup() {
  //motor pinlerini çıkış olarak tanimladim
    Blynk.begin(auth, ssid, pass);

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  if(adim < adimSayisi )
    saatyonu();
  else if (adim == adimSayisi * 2)
    adim = 0;
  else
    saatyonuTersi();
  adim++;
}


void saatyonuTersi()
{
  for(int i = 0; i < 8; i++)
  {
    setOutput(i);
    delayMicroseconds(motorSpeed);
  }
}

void saatyonu()
{
  for(int i = 7; i >= 0; i--)
  {
    setOutput(i);
    delayMicroseconds(motorSpeed);
  }
}

void setOutput(int out)
{
  digitalWrite(motorPin1, bitRead(lookup[out], 0));
  digitalWrite(motorPin2, bitRead(lookup[out], 1));
  digitalWrite(motorPin3, bitRead(lookup[out], 2));
  digitalWrite(motorPin4, bitRead(lookup[out], 3));
}
