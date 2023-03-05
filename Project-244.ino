#define buzzer 26

const int VALUE_THRESHOLD = 26;

int TOUCH_Pin_1_VALUE;
int TOUCH_Pin_2_VALUE;
int TOUCH_Pin_3_VALUE;

void setup(){
  
  pinMode(buzzer, OUTPUT);
  Serial.begin(115200);
  delay(1000); 
  
  digitalWrite(buzzer, LOW);
}

void loop(){
  
  TOUCH_Pin_1_VALUE = touchRead(T5);
  TOUCH_Pin_2_VALUE = touchRead(T6);
  TOUCH_Pin_3_VALUE = touchRead(T7);
  
  Serial.print("TOUCH Pin_1 VALUE 1:");
  Serial.print(TOUCH_Pin_1_VALUE);
  Serial.print("  ");
  Serial.print("TOUCH Pin_2 VALUE:");
  Serial.print(TOUCH_Pin_2_VALUE);
  Serial.print("  ");
  Serial.print("TOUCH Pin_3 VALUE:");
  Serial.print(TOUCH_Pin_3_VALUE);
  Serial.print(" ");
  delay(500);
  
  if(TOUCH_Pin_1_VALUE < VALUE_THRESHOLD){
    for(int i=0; i<2; i++){
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(100);
    }
  }
  if(TOUCH_Pin_2_VALUE < VALUE_THRESHOLD){
     for(int i=0; i<5; i++){
      digitalWrite(buzzer, HIGH);
      delay(50);
      digitalWrite(buzzer, LOW);
      delay(50);
    }
  }
  if(TOUCH_Pin_3_VALUE < VALUE_THRESHOLD){
    for(int i=0; i<8; i++){
      digitalWrite(buzzer, HIGH);
      delay(25);
      digitalWrite(buzzer, LOW);
      delay(25);
    }
  }
  else{
    digitalWrite(2, LOW);
  }
  
}
