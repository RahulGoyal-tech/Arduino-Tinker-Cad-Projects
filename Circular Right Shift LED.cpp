int dataPin = 12;
int latchPin = 11;
int clockPin = 10;
int dt = 1000;
byte led = 0b11100010;
int val;

void setup(){
  Serial.begin(9600);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop(){
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, led);
  digitalWrite(latchPin, HIGH);
  Serial.println(led,DEC);
  val = led - led/2;
  led = led /2;
  if(val==led){ 
  }
  else{
   led = led +128; 
  }
  Serial.println(led,DEC);
  delay(dt);
}