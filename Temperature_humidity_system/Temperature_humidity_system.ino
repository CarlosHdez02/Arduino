#include <LiquidCrystal.h>
#include <DHT.h>
#include <DHT_U.h>
//Sensor dht11
int sensor=6;
int temperatura_met;
int humedad_met;
int button_temp =5;
int button_humidity=4;
//Initialize sensor and display in respective pins
DHT dht(sensor, DHT11); 
LiquidCrystal lcd(12,11,10,9,8,7);
void setup() {
pinMode(button_temp, INPUT);
pinMode(button_humidity, INPUT);
dht.begin();
lcd.begin(16,2);
}

void loop() {
 
 temp();
 humidity();
 
 
}

void temp(){
 temperatura_met = dht.readTemperature();
 int is_temp = digitalRead(button_temp);
 lcd.clear();
    if(is_temp == 1){
      lcd.print("temperature:");
      lcd.setCursor(0,1);
      lcd.print(temperatura_met);
      delay(2000); 
}
}
void humidity(){
humedad_met = dht.readHumidity();
int is_humidity = digitalRead(button_humidity);
lcd.clear();
    if(is_humidity == 1){
      lcd.print("humidity:");
      lcd.setCursor(0,1);
      lcd.print(humedad_met);
      delay(2000);
}
}
