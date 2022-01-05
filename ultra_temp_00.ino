#include <LiquidCrystal.h>
#include <dht11.h>
#define echoPin 8 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 9 //attach pin D3 Arduino to pin Trig of HC-SR04

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int greenPin = 13;
dht11 sensor;

void take_temp(){
  delay(1000); //wait a sec (recommended for DHT11)
  sensor.read(greenPin);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity = ");
  lcd.print(sensor.humidity);
  lcd.setCursor(0,1);
  lcd.print("Temp = ");
  float celsius = sensor.temperature;
  float fahrenheit = (celsius * 9.0) / 5.0 + 32;
  lcd.print((int)fahrenheit);
}

void setup() {
  lcd.begin(16,2); //16 by 2 character display
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  if(distance < 10){
    take_temp();
    delay(15000);
    }
    
}
