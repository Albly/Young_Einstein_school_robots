#include <Servo.h>

#define relay 13
#define crabServo 9
#define rightServo 8
#define upServo 7
#define aheadServo 6

#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

const int LONG = 300;
const int MID = 100;
const int SHORT = 50;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

boolean mode =false;

int val1=50;
int val2=80;
int val3=0;
int val4=0;

void setup() {
  Serial.begin(9600);
  
  servo1.attach(6);
  servo2.attach(7);
  servo3.attach(8);
  servo4.attach(9);

  set(servo1,val1);
  set(servo2,val2);
  set(servo3,val3);
  set(servo4,val4); 

  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void loop() {
  servo1.write(val1);
  servo2.write(val2);
  servo3.write(val3);
  servo4.write(val4);
  delay(15);
}

void serialEvent(){
  if(Serial.available()){
    char inChar = Serial.read();
    if(!mode){
      switch(inChar){
        case '1':{val1+=10;control();break;}
        case '2':{val1-=10;control();break;}
        case '3':{val2+=10;control();break;}
        case '4':{val2-=10;control();break;}
        case '5':{val3+=10;control();break;}
        case '6':{val3-=10;control();break;}
        case '7':{val4+=10;control();break;}
        case '8':{val4-=10;control();break;}
        case '9':{mode=!mode; 
        if(mode){digitalWrite(relay,HIGH);}
        else{digitalWrite(relay,LOW);}
        }
      }
    } 
    else{
        switch(inChar){
    case '1':{
       back(LONG);
       break;
     }
     case '2':{
       ahead(LONG);
       break;
     }
     case '3':{
       left(MID);
       break;
     }
     case '4':{
       right(MID);
       break;
     }
     
     case '5':{
      ahead(SHORT);
      break;
      }
     case '6':{
      back(SHORT);
      break;
      } 
     case'7':{
        right(SHORT);
        break;
      }
     case '8':{
        left(SHORT);
        break;
        }
         
      case '9':{mode=!mode; 
        if(mode){digitalWrite(relay,HIGH);}
        else{digitalWrite(relay,LOW);}
        }
      }     
      }
  }
}
void control(){
  if(val1>150){val1=150;}
  if(val1<50){val1=50;}

  if(val2>150){val2=150;}
  if(val2<80){val2=80;}
  
  if(val3>180){val3=180;}
  if(val3<0){val3=0;}
  
  if(val4>30){val4=30;}
  if(val4<0){val4=0;}
  }
  
void set(Servo servo, int angle){
  int i = servo.read();
  
  if(i>angle){
    for(i;i>0;i--){
      servo.write(i);
      delay(20);
    }
  }
  else if(i<angle){
    for(i;i>0;i++){
      servo.write(i);
      delay(20);
    }
  } 
}

void ahead(int duration){
       digitalWrite(IN1,LOW);
       digitalWrite(IN2,HIGH);
       digitalWrite(IN3,HIGH);
       digitalWrite(IN4,LOW);
       delay(duration);
       digitalWrite(IN2,LOW);
       digitalWrite(IN3,LOW);
  }
void back(int duration){
       digitalWrite(IN1,HIGH);
       digitalWrite(IN2,LOW);
       digitalWrite(IN3,LOW);
       digitalWrite(IN4,HIGH);
       delay(duration);
       digitalWrite(IN1,LOW);
       digitalWrite(IN4,LOW);
  }
void right(int duration){
       digitalWrite(IN1,HIGH);
       digitalWrite(IN2,LOW);
       digitalWrite(IN3,HIGH);
       digitalWrite(IN4,LOW);
       delay(duration);
       digitalWrite(IN1,LOW);
       digitalWrite(IN3,LOW);
  }
void left(int duration){
       digitalWrite(IN1,LOW);
       digitalWrite(IN2,HIGH);
       digitalWrite(IN3,LOW);
       digitalWrite(IN4,HIGH);
       delay(duration);
       digitalWrite(IN2,LOW);
       digitalWrite(IN4,LOW);
  } 
