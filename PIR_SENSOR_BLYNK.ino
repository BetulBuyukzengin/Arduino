
//Hırsız alarmı 
#include <Servo.h>    

int pirPin = A0;                   
              
int hareket;                      


void setup() {
    Serial.begin(9600); // See the connection status in Serial Monitor

  pinMode(pirPin, INPUT);         

}

void loop() {
  hareket = digitalRead(pirPin);  
 if (hareket == HIGH) // hareket algılandığında
  {
  Serial.println("hareket algılandı");
  //Blynk.notify("Dikkat !!! Evde hırsız var !"); 

  }
  if (hareket == LOW) // hareket algılanmadığında
  {
  Serial.println("hareket algılanmadı");
  }
}            
