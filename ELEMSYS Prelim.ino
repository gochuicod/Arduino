void setup(){
  for(int i = 0; i <= 3; pinMode(i,OUTPUT), i++);
  for(int i = 4; i <= 10; pinMode(i,INPUT), i++);
}

void loop(){
  if(digitalRead(0) == HIGH){
    for(int i = 0; i < 5; i++){
      turnOn(4,10,100,true);
      delay(1000);
    	turnOff(4,10,100,true);
    }
  }
  if(digitalRead(1) == HIGH){
    for(int i = 0; i < 5; i++){
    	turnOn(4,10,100,false);
     	delay(1000);
      turnOff(4,10,100,false);
    }
  }  
  if(digitalRead(2) == HIGH){
    for(int i = 0; i < 5; i++){
      for(int i = 5; i <= 10; digitalWrite(i,HIGH), delay(50), i+=2);
        for(int i = 5; i <= 10; digitalWrite(i,LOW), delay(50), i+=2);
        for(int i = 4; i <= 10; digitalWrite(i,HIGH), delay(50), i+=2);
        for(int i = 4; i <= 10; digitalWrite(i,LOW), delay(50), i+=2);
    }
  }
  if(digitalRead(3) == HIGH){
    for(int i = 0; i < 5; i++){
 	    for(int j = 4, k = 10; j <= 7 && k >= 7; digitalWrite(j,HIGH), digitalWrite(k,HIGH), delay(100), j++, k--);
	    for(int j = 4, k = 10; j <= 7 && k >= 7; digitalWrite(j,LOW), digitalWrite(k,LOW), delay(100), j++, k--);
		  for(int j = 7, k = 7; j >= 4 && k <= 10; digitalWrite(j,HIGH), digitalWrite(k,HIGH), delay(100), j--, k++);
    	for(int j = 7, k = 7; j >= 4 && k <= 10; digitalWrite(j,LOW), digitalWrite(k,LOW), delay(100), j--, k++);
    }
  }
}
        
void turnOn(int start, int finish, int interval, bool startingPoint){
 	if(!startingPoint) for(int i = finish; i >= start; digitalWrite(i,HIGH), delay(interval), i--);
  for(int i = start; i <= finish; digitalWrite(i,HIGH), delay(interval), i++);
}
        
void turnOff(int start, int finish, int interval, bool startingPoint){
  if(!startingPoint) for(int i = finish; i >= start; digitalWrite(i,LOW), delay(interval), i--);
	for(int i = start; i <= finish; digitalWrite(i,LOW), delay(interval), i++);
}
