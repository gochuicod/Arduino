void setup() {
  for(int i = 2; i <= 4; pinMode(i,OUTPUT),i++);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop(){
  int value = analogRead(A0);
  
  for(int i = 2; i <= 4; digitalWrite(i,LOW), i++);
  
  if(value < 200) digitalWrite(2,HIGH);
  else if(value > 200 && value < 400) digitalWrite(3,HIGH);
  else digitalWrite(4,HIGH);
  
  Serial.print("\nCurrent Value: ");
  Serial.print(value);
  delay(1000);
}
