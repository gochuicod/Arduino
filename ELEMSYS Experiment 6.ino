void setup() {
    for(int i = 2; i <= 13; pinMode(i,OUTPUT), i++);
}

void loop(){
    int counter = 5;

    while(counter != 0){

      turnOn(2,11);
      
      for(int i = 11; i >= 2; i--){
          digitalWrite(i,LOW);
          delay(100);
      }
      
      counter--;
    }

    turnOff(2,11);

    counter = 5;
    
    while(counter != 0){
      for(int j = 2; j <= 11; j++){
          digitalWrite(j,HIGH);
          delay(100);
          digitalWrite(j,LOW);
          delay(100);
      }
      counter--;
    }

    turnOff(2,11);

    for(int k = 2; k <= 5; digitalWrite(k,HIGH), k++);
    delay(100);
    for(int k = 8; k <= 11; digitalWrite(k,HIGH), k++);

    turnOff(2,11);


    for(int l = 0; l <= 5; l++){
        digitalWrite(rand() % 12, HIGH);
        delay(100);
    }

    for(int p = 2; p <= 11; digitalWrite(p,LOW), p++);

    delay(100);
    digitalWrite(2,HIGH);
    digitalWrite(11,HIGH);
    delay(100);
    
    for(int m = 2, n = 10; m <= 6 && n >= 6; m++, n--){
        digitalWrite(m, HIGH);
        delay(100);
        digitalWrite(n, HIGH);
        delay(100);
    }
}

void turnOff(int start, int finish){
    for(int i = start; i <= finish; digitalWrite(i,LOW), delay(100), i++);
}

void turnOn(int start, int finish){
    for(int i = start; i <= finish; digitalWrite(i,HIGH), delay(100), i++);
}