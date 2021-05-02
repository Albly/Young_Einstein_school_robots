#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4
#define LED 13

bool ledState = false;
const int LONG = 300;
const int MID = 100;
const int SHORT = 50;

void setup()
{
    Serial.begin(9600);
    pinMode(IN1,OUTPUT);
    pinMode(IN2,OUTPUT);
    pinMode(IN3,OUTPUT);
    pinMode(IN4,OUTPUT);
}

void loop()
{
  if(ledState) digitalWrite(LED,HIGH);
  else digitalWrite(LED,LOW);

}

void serialEvent(){
  if(Serial.available()){
    char inChar = Serial.read();
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

        
     case '9':{
       ledState=!ledState;
       break;
     }
    }
  }}

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
