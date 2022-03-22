//Keypad ile şifeli kapı kontrolü 
#include <Keypad.h>  // keypad kütüphanesi, kendimiz import ediyoruz.
#include <Servo.h>   // servo kütüphanesi


const byte numRows= 4;  // keypadin satır sayısı
const byte numCols= 4;  // keypadin sütün sayısı
int control = 0;
int counter = 0;
String enter_password;     // girilen şifreyi tutar
String password = "*1234"; // kendimizin belirlediği şifre

Servo myservomotor;

// keypad tuş yapısı olustu
char keymap[numRows][numCols]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

// Bağlanacakları pinler
byte rowPins[numRows] = {16,5,4,0}; //D0,D1,D2,D3
byte colPins[numCols]= {2,14,12,13}; //D4,D5,D6,D7

// keypad  set edildi
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup()
{
  Serial.begin(9600); //Serial Monitor 9600 bound olarak baslatıldı
  myservomotor.attach(15);      // D8 servo çıkışı
  myservomotor.write(0);        // ilk etapta açısı 0 olarak set edildi
   
}

void loop()
{
  char keypressed = myKeypad.getKey();  // keypade girilen değer
  if (keypressed != NO_KEY) {
    Serial.print(keypressed);
    // # tuşuna basıldı ise control 1 olur password kontrole geçer
    if(keypressed == '#') {  
      control = 1;
    }
    // kapı açıldı
    if(keypressed == 'A') { 
      for(int value = 0; value < 180; value++) {
        myservomotor.write(value);
      }
    }
   
    // # tuşu ile kontroller
    if(control == 1){
      enter_password = enter_password + keypressed;
      counter++;
      Serial.print("sifre " + enter_password );
      // password doğru ise
      if(enter_password == password) {
        Serial.print("kapı açıldı");
        for(int value = 0; value < 180; value--) {
          myservomotor.write(value);
        }
        delay(2000);  // gecikme
        enter_password = "";
        control = 0;
        counter = 0;
      }
      
}}}
