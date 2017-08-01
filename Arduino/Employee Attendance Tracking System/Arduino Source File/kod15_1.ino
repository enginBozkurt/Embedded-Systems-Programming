/*
#####################################################################################

 #
 #
 #   Autor:              Marcelo Moraes'inhttp://arduinobymyself.blogspot.com.br/ adresindeki örnek kodlarından yararlanılmıştır.
 #   Data:               27/05/13
 #   Local:              Sorocaba - SP
 #

 */

// kütüphaneler koda dahil ediliyor
#include <SPI.h>
#include <RFID.h>
#include <Servo.h>
#include "pitches.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// rfId kart okuyucu bağlantıları
RFID rfid(53,5);

 
// I2c lcd ekran kurulumu yapılıyor.
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
byte serNum[5];
byte data[5];

// kart geçişleri için notalar tanımlanıyor.
int access_melody[] = {
  NOTE_G4,0,NOTE_A4,0, NOTE_B4,0,NOTE_A4,0,NOTE_B4,0, NOTE_C5,0};
int access_noteDurations[] = {
  8,8,8,8,8,4,8,8,8,8,8,4};
int fail_melody[] = {
  NOTE_G2,0,NOTE_F2,0,NOTE_D2,0};
int fail_noteDurations[] = {
  8,8,8,8,8,4};

// servo motor ve buzzer pinleri tanımlanıyor.
int LED_basarili = 2;
int LED_gecersiz = 3;
int buzzer_pin = 8;
int servoPin = 9;

// servo motor nesnesi yaratılıyor.
Servo doorLock;


void setup(){
  doorLock.attach(servoPin); // servo pin parametre olarak veriliyor.
  Serial.begin(9600); //
  lcd.begin(20,4); //
  lcd.backlight();

  lcd.clear();//
  SPI.begin(); //
  rfid.init(); //

  delay(500);
  pinMode(LED_basarili,OUTPUT);
  pinMode(LED_gecersiz,OUTPUT);
  pinMode(buzzer_pin,OUTPUT);
  pinMode(servoPin,OUTPUT);
}
 
void loop(){
  
  
  char veri;
  if(rfid.isCard()){

    if (rfid.readCardSerial()){ //
      data[0] = rfid.serNum[0]; //
      data[1] = rfid.serNum[1];
      data[2] = rfid.serNum[2];
      data[3] = rfid.serNum[3];
      data[4] = rfid.serNum[4];
      delay(1000);
    }

    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("Kart ID'si");

    lcd.setCursor(0,1);
    lcd.print("     ");
    if(data[0]>0)
    {
      for(int i=0;i<5;i++)
      {

        Serial.print(data[i]);
        lcd.print(data[i]);

      }
      Serial.println();
    }
    else
    {
      lcd.backlight();
      lcd.println("kart Okunmadı");
    }
   

    for(int i=0;i<5;i++)
    {
      data[i]=0;

    }

  rfid.halt();
  }
   while(Serial.available()>0 )
    {
      veri=Serial.read();
      
      if(veri=='A')
      {
        lcd.clear();
        lcd.setCursor(0,2);
          lcd.print("GIRIS BASARILI");

        for (int i = 0; i < 12; i++){
          int access_noteDuration = 1000/access_noteDurations[i];
          tone(buzzer_pin, access_melody[i],access_noteDuration);
          int access_pauseBetweenNotes = access_noteDuration * 1.30;
          delay(access_pauseBetweenNotes);
          noTone(buzzer_pin);
        }
        lcd.setCursor(0,3);
        lcd.print("KAPI ACILIYOR");
        digitalWrite(LED_basarili,HIGH);
        doorLock.write(180); 
        delay(3000); 
        doorLock.write(0); 
        digitalWrite(LED_basarili,LOW); 
        lcd.print("KAPI KAPANDI");


      }
      else if(veri=='K')
      {
         lcd.clear();
        lcd.setCursor(0,2);
        lcd.print(" GECERSIZ KART");
        digitalWrite(LED_gecersiz, HIGH);
        for (int i = 0; i < 6; i++){
          int fail_noteDuration = 1000/fail_noteDurations[i];
          tone(buzzer_pin, fail_melody[i],fail_noteDuration);
          int fail_pauseBetweenNotes = fail_noteDuration * 1.30;
          delay(fail_pauseBetweenNotes);
          noTone(buzzer_pin);
        }
      }
   
    }
}



