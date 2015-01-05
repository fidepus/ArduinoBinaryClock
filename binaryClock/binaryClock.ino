#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;
DateTime now;

int secs=0;
int mins=0;
int sunit=0;
int munit=0;
long previousMillis = 0;
long interval = 1000;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  
  Serial.begin(57600);
#ifdef AVR
  Wire.begin();
#else
  Wire1.begin(); // Shield I2C pins connect to alt I2C bus on Arduino Due
#endif
  rtc.begin();

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}

void loop() {
  now = rtc.now();
  
  secs = now.second();
  mins = now.minute();
  
  sunit = secs%10;
  munit = mins%10;
  
  // Test output of date and time
//  Serial.print(now.year(), DEC);
//  Serial.print('/');
//  Serial.print(now.month(), DEC);
//  Serial.print('/');
//  Serial.print(now.day(), DEC);
//  Serial.print(' ');
//  Serial.print(now.hour(), DEC);
//  Serial.print(':');
//  Serial.print(now.minute(), DEC);
//  Serial.print(':');
//  Serial.print(now.second(), DEC);
//  Serial.println();

 //secs units
  if(sunit == 1 || sunit == 3 || sunit == 5 || sunit == 7 || sunit == 9) {  digitalWrite(2, LOW);} else {  digitalWrite(2, HIGH);}
  if(sunit == 2 || sunit == 3 || sunit == 6 || sunit == 7) {digitalWrite(3, LOW);} else {digitalWrite(3,HIGH);}
  if(sunit == 4 || sunit == 5 || sunit == 6 || sunit == 7) {digitalWrite(4, LOW);} else {digitalWrite(4,HIGH);}
  if(sunit == 8 || sunit == 9) {digitalWrite(5, LOW);} else {digitalWrite(5,HIGH);}

  //secss 
  if((secs >= 10 && secs < 20) || (secs >= 30 && secs < 40) || (secs >= 50 && secs < 60))  {digitalWrite(6, LOW);} else {digitalWrite(6,HIGH);}
  if(secs >= 20 && secs < 40)  {digitalWrite(7, LOW);} else {digitalWrite(7,HIGH);}
  if(secs >= 40 && secs < 60) {digitalWrite(8, LOW);} else {digitalWrite(8,HIGH);}

  
}
