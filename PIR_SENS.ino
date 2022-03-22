//hareket algılanınca led yanıyor ,koridorlara döşenen otomatık aydınlatma
const int led = D8;
const int pirPin = A0;
int pirDeger;

void setup() {
pinMode(pirPin, INPUT);
pinMode(led, OUTPUT);
Serial.begin(9600);

}

void loop() {

pirDeger = digitalRead(pirPin);
if (pirDeger == HIGH) // hareket algılandığında
{
digitalWrite(led, HIGH);
Serial.println(" algılandı");
}
if (pirDeger == LOW) // hareket algılanmadığında
{
digitalWrite(led, LOW);
Serial.println("hareket algılanmadı");
}
}
