#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DHT.h>
#define DHTPIN D4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  dht.begin();
  lcd.begin();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  Serial.print("Temp : ");
  Serial.print(temp);
  Serial.print("   Humi : ");
  Serial.println(humi);

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);

  lcd.setCursor(0, 1);
  lcd.print("Humi: ");
  lcd.print(humi);

  delay(1000);
}
