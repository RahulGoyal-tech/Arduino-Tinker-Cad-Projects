#include <IRremote.h>
int IRpin = 11;
IRrecv IR(IRpin);
decode_results cmd;
int speedPin = 5;//not working on pin3
int dir1 = 2;
int dir2 = 12;
int mspeed = 100;
int inc = 50;
int dec = 50;
//int dir1High = 0;
//int dir2High = 0;

void setup(){
  
  Serial.begin(9600);
  IR.enableIRIn();
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
}

void loop(){
  
    /*Red Button = MOTOR ON FWD FULL SPEED
  	fwd button = dir1
  	backward button = dir2
    vol+ = faster
    vol- = slower
    st = stop*/
  
  
  while(IR.decode(&cmd)==0){
  }
  
  Serial.println(cmd.value, HEX);
  delay(250);
  if (cmd.value == 0xFD00FF){
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    analogWrite(speedPin, 255);
    mspeed = 255;
   //dir1High = 1;
   //dir2High = 0;
  }
  if (cmd.value == 0xFD20DF){
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    analogWrite(speedPin, mspeed);
    //dir1High = 0;
    //dir2High = 1;
  }
  if (cmd.value == 0xFD609F){
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    analogWrite(speedPin, mspeed);
    //dir1High = 1;
    //dir2High = 0;
  }
  if (cmd.value == 0xFD807F){
 	mspeed = mspeed + inc;
    if(mspeed>255){
     mspeed = 255; 
    }
    if(mspeed<100){
      mspeed = 100;
    }
    /*if(dir1High == 1){
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    analogWrite(speedPin, mspeed);
    Serial.println("Loop1");
    }
    if(dir2High == 1){
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    analogWrite(speedPin, mspeed);
    Serial.println("Loop2");
    }*/
    analogWrite(speedPin, mspeed);
  }
  if (cmd.value == 0xFD906F){
 	mspeed = mspeed - dec;
    if(mspeed<100){
     mspeed = 0; 
    }
    if(mspeed==205){
     mspeed = 200; 
    }
    /*if(dir1High == 1){
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    analogWrite(speedPin, mspeed);
    Serial.println("Loop3");
    }
    if(dir2High == 1){
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    analogWrite(speedPin, mspeed);
    Serial.println("Loop4");
    }*/
    analogWrite(speedPin, mspeed);
  }
  if (cmd.value == 0xFD708F){
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    analogWrite(speedPin, 0);
    mspeed = 0;
    //dir1High = 1;
    //dir2High = 0;
  }
  Serial.println(mspeed);
  IR.resume();
}