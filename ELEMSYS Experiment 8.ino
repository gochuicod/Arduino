void setup() {
  Serial.begin(9600);
  for(int i = 2; i <= 3; pinMode(i,OUTPUT), i++);
  pinMode(A0,INPUT);
}

void loop(){
  int temperature = analogRead(A0)*0.48828125;
  if(temperature <= 28){
    digitalWrite(3,LOW);
    Serial.print("\nNormal: ");
    Serial.print(temperature);
    digitalWrite(2,HIGH);
    delay(1000);
  } else {
    digitalWrite(2,LOW);
    Serial.print("\nToo Hot: ");
    Serial.print(temperature);
    digitalWrite(3,HIGH);
    digitalWrite(3,LOW);
    delay(1000);
  }
}