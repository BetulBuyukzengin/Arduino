//hırsız alarmı 
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
//  Blynk.notify("Dikkat !!! Evde hırsız var !"); // uygulamadan "Dikkat !!! Gaz Çıkışı var !" şeklinde  uyarı mesajı alınacak

  }
  if (hareket == LOW) // hareket algılanmadığında
  {
  Serial.println("hareket algılanmadı");
  }
}            
/*
int pirPin = 8;                   
int servoPin = 9;                 
int hareket;                      
Servo motor;                      


void setup() {
  motor.attach(servoPin);         
  pinMode(pirPin, INPUT);         

}

void loop() {
  hareket = digitalRead(pirPin);  
  
  if(hareket == HIGH){            
    motor.write(150);
    delay(250);
    motor.write(30);
    delay(250);
    motor.write(150);
    delay(250);
    motor.write(30);
    delay(250);
    motor.write(150);
    delay(250);
    motor.write(30);
    delay(250);
    motor.write(90);
  }
  else{                          
    motor.write(90);
    
  }
}*/
