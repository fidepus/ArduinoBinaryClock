int second=0;
int minute=0;
int sunit=0;
int munit=0;

void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
static unsigned long Tick = 0;

  if (millis() - Tick >= 1000) 
  {
    Tick = millis();
    second++;
  }
  
  if (second >= 60)
  {
    minute++;
    second = 0;
  }
  
  sunit = second%10;
  sunit = minute%10;

 //second units
  if(sunit == 1 || sunit == 3 || sunit == 5 || sunit == 7 || sunit == 9) {  digitalWrite(1, LOW);} else {  digitalWrite(1, HIGH);}
  if(sunit == 2 || sunit == 3 || sunit == 6 || sunit == 7) {digitalWrite(2, LOW);} else {digitalWrite(2,HIGH);}
  if(sunit == 4 || sunit == 5 || sunit == 6 || sunit == 7) {digitalWrite(3, LOW);} else {digitalWrite(3,HIGH);}
  if(sunit == 8 || sunit == 9) {digitalWrite(4, LOW);} else {digitalWrite(4,HIGH);}

  //seconds 
  if((second >= 10 && second < 20) || (second >= 30 && second < 40) || (second >= 50 && second < 60))  {digitalWrite(5, LOW);} else {digitalWrite(5,HIGH);}
  if(second >= 20 && second < 40)  {digitalWrite(6, LOW);} else {digitalWrite(6,HIGH);}
  if(second >= 40 && second < 60) {digitalWrite(7, LOW);} else {digitalWrite(7,HIGH);}

  
}
