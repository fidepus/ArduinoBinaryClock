#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;
DateTime now;

int secs=0;
int mins=0;
int hours=0;
int sunit=0;
int munit=0;
int hunit=0;
long previousMillis = 0;
long interval = 1000;

void setup() {
  // Second pins
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
    // Minute pins
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
    // Hour pins
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);
  
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
    // rtc.adjust(DateTime(2015, 2, 4, 13, 38, 6));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}

void loop() {
  now = rtc.now();
  
  secs = now.second();
  mins = now.minute();
  hours = now.hour();
  
  sunit = secs%10;
  munit = mins%10;
  hunit = hours%10;
  
  // Test output of date and time
//  Serial.print(now.year(), DEC);
//  Serial.print('/');
//  Serial.print(now.month(), DEC);
//  Serial.print('/');
//  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
Serial.println();

   //secs units
  if(sunit == 1 || sunit == 3 || sunit == 5 || sunit == 7 || sunit == 9) {  digitalWrite(2, LOW);} else {  digitalWrite(2, HIGH);}
  if(sunit == 2 || sunit == 3 || sunit == 6 || sunit == 7) {digitalWrite(3, LOW);} else {digitalWrite(3,HIGH);}
  if(sunit == 4 || sunit == 5 || sunit == 6 || sunit == 7) {digitalWrite(4, LOW);} else {digitalWrite(4,HIGH);}
  if(sunit == 8 || sunit == 9) {digitalWrite(5, LOW);} else {digitalWrite(5,HIGH);}

  //secs 
  if((secs >= 10 && secs < 20) || (secs >= 30 && secs < 40) || (secs >= 50 && secs < 60))  {digitalWrite(6, LOW);} else {digitalWrite(6,HIGH);}
  if(secs >= 20 && secs < 40)  {digitalWrite(7, LOW);} else {digitalWrite(7,HIGH);}
  if(secs >= 40 && secs < 60) {digitalWrite(8, LOW);} else {digitalWrite(8,HIGH);}
  
   //mins units
  if(munit == 1 || munit == 3 || munit == 5 || munit == 7 || munit == 9) {  digitalWrite(9, LOW);} else {  digitalWrite(9, HIGH);}
  if(munit == 2 || munit == 3 || munit == 6 || munit == 7) {digitalWrite(10, LOW);} else {digitalWrite(10,HIGH);}
  if(munit == 4 || munit == 5 || munit == 6 || munit == 7) {digitalWrite(11, LOW);} else {digitalWrite(11,HIGH);}
  if(munit == 8 || munit == 9) {digitalWrite(12, LOW);} else {digitalWrite(12,HIGH);}

  //mins 
  if((mins >= 10 && mins < 20) || (mins >= 30 && mins < 40) || (mins >= 50 && mins < 60))  {digitalWrite(13, LOW);} else {digitalWrite(13,HIGH);}
  if(mins >= 20 && mins < 40)  {digitalWrite(22, LOW);} else {digitalWrite(22,HIGH);}
  if(mins >= 40 && mins < 60) {digitalWrite(23, LOW);} else {digitalWrite(23,HIGH);}

   //hours units
  if(hunit == 1 || hunit == 3 || hunit == 5 || hunit == 7 || hunit == 9) {  digitalWrite(24, LOW);} else {  digitalWrite(24, HIGH);}
  if(hunit == 2 || hunit == 3 || hunit == 6 || hunit == 7) {digitalWrite(25, LOW);} else {digitalWrite(25,HIGH);}
  if(hunit == 4 || hunit == 5 || hunit == 6 || hunit == 7) {digitalWrite(26, LOW);} else {digitalWrite(26,HIGH);}
  if(hunit == 8 || hunit == 9) {digitalWrite(27, LOW);} else {digitalWrite(27,HIGH);}

  //hours 
  if((hours >= 10 && hours < 20) || (hours >= 30 && hours < 40) || (hours >= 50 && hours < 60))  {digitalWrite(28, LOW);} else {digitalWrite(28,HIGH);}
  if(hours >= 20 && hours < 24)  {digitalWrite(29, LOW);} else {digitalWrite(29,HIGH);}
  
}
