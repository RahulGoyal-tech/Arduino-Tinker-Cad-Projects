#include<IRremote.h>
int redPin = 5;
int greenPin = 10;
int bluePin = 9;
int IRpin = 6;
IRrecv IR(IRpin);
decode_results cmd;
int divr = 1;
int divg = 1;
int divb = 1;
int redVal;
int blueVal;
int greenVal;

void setup(){
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  IR.enableIRIn();
  Serial.begin(9600);
}

void loop(){
  
  while(IR.decode(&cmd)==0){
  }
  Serial.println(cmd.value, HEX);
  delay(250);
  if(cmd.value==0xFD00FF){
    redVal = 255;
    greenVal = 255;
    blueVal = 255;
    
  }
  if(cmd.value==0xFD40BF){
    
    redVal = 0;
    greenVal = 0;
    blueVal = 0;
  }
  if(cmd.value == 0xFD30CF){
    //0
    redVal = 255;
    greenVal = 255;
    blueVal = 255;
  }
  if(cmd.value == 0xFD08F7){
    //1
    redVal = 255;
    greenVal = 0;
    blueVal = 0;
  }
  if(cmd.value == 0xFD8877){
    //2
    redVal = 0;
    greenVal = 255;
    blueVal = 0;
  }
  if(cmd.value == 0xFD48B7){
    //3
    redVal = 0;
    greenVal = 0;
    blueVal = 255;
  }
  if(cmd.value == 0xFD28D7){
    //4
    redVal = 0;
    greenVal = 255;
    blueVal = 255;
  }
  if(cmd.value == 0xFDA857){
    //5
    redVal = 255;
    greenVal = 0;
    blueVal = 255;
  }
  if(cmd.value == 0xFD6897){
    //6
    redVal = 255;
    greenVal = 255;
    blueVal = 0;
  }
  if(cmd.value == 0xFD10EF){
    
   divr = divr*2;
   divg = divg*2;
   divb = divb*2;
  }
  if(cmd.value == 0xFD50AF){
    if(divr == 1){
   divr = 1;
   divg = 1;
   divb = 1;
    }
    else{
   divr = divr/2;
   divg = divg/2;
   divb = divb/2;
    }
  }
  
  analogWrite(redPin, redVal/divr);
  analogWrite(greenPin, greenVal/divg);
  analogWrite(bluePin, blueVal/divb);
  Serial.println(divr);
  Serial.println(redVal);
  Serial.println(greenVal);
  Serial.println(blueVal);
  IR.resume();
  
}