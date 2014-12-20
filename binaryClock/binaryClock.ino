int second=0;
int minute=0;
int sunit=0;
int munit=0;
long previousMillis = 0;
long interval = 1000;

void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval) 
  {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   
    second++;
  }
  
  if (second >= 60)
  {
    minute++;
    second = 0;
  }
  
  sunit = second%10;
  munit = minute%10;

 //second units
  if(sunit == 1 || sunit == 3 || sunit == 5 || sunit == 7 || sunit == 9) {  digitalWrite(1, LOW);} else {  digitalWrite(1, HIGH);}
  if(sunit == 2 || sunit == 3 || sunit == 6 || sunit == 7) {digitalWrite(3, LOW);} else {digitalWrite(3,HIGH);}
  if(sunit == 4 || sunit == 5 || sunit == 6 || sunit == 7) {digitalWrite(5, LOW);} else {digitalWrite(5,HIGH);}
  if(sunit == 8 || sunit == 9) {digitalWrite(7, LOW);} else {digitalWrite(7,HIGH);}

  //seconds 
  if((second >= 10 && second < 20) || (second >= 30 && second < 40) || (second >= 50 && second < 60))  {digitalWrite(9, LOW);} else {digitalWrite(9,HIGH);}
  if(second >= 20 && second < 40)  {digitalWrite(11, LOW);} else {digitalWrite(11,HIGH);}
  if(second >= 40 && second < 60) {digitalWrite(13, LOW);} else {digitalWrite(13,HIGH);}

  
}
