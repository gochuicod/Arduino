void setup() {
    for(int i = 2; i <= 13; i++){
        pinMode(i,OUTPUT);
    }
}

void loop(){
    for(int i = 0; i <= 15; i++){
        displayDigit(i);
        delay(1000);
        turnOff(2,13);
    }
}

void displayDigit(int digit){
    if(digit == 0) turnOn(0,8);
    else if(digit == 1){
        turnOn(3,4);
        turnOn(10,10);
    }
    else if(digit == 2) {
        turnOn(2,3);
        turnOn(5,6);
        turnOn(9,9);
        turnOn(11,11);
    } else if(digit == 3){
        turnOn(2,5);
        turnOn(9,9);
        turnOn(10,11);
    } else if(digit == 4){
        turnOn(3,4);
        turnOn(7,9);
        turnOn(12,12);
    } else if(digit == 5){
        turnOn(2,2);
        turnOn(4,5);
        turnOn(7,9);
        turnOn(10,10);
        turnOn(12,12);
    } else if(digit == 6){
        turnOn(2,2);
        turnOn(4,9);
        turnOn(11,12);
    } else if(digit == 7){
        turnOn(2,4);
        turnOn(10,12);
    }
    else if(digit == 8){
        turnOn(2,9);
        turnOn(13,13);
    }
    else if(digit == 9){
       turnOn(2,5);
       turnOn(7,9);
       turnOn(10,10);
       turnOn(13,13);
    } else if(digit == 10){
       turnOn(2,4);
       turnOn(6,9);
       turnOn(11,11);
       turnOn(13,13);
    } else if(digit == 11){
       turnOn(4,9);
       turnOn(10,10);
       turnOn(12,13);
    }
    else if(digit == 12){
       turnOn(2,2);
       turnOn(5,8);
       turnOn(10,11);
    } else if(digit == 13){
       turnOn(3,7);
       turnOn(9,9);
       turnOn(10,11);
       turnOn(13,13);
    } else if(digit == 14){
       turnOn(2,2);
       turnOn(5,9);
       turnOn(10,12);
    } else if(digit == 15){
       turnOn(2,2);
       turnOn(6,9);
       turnOn(10,13);
    }
}
void turnOff(int start, int finish){
    for(int i = start; i <= finish; digitalWrite(i,LOW), i++);
}

void turnOn(int start, int finish){
    for(int i = start; i <= finish; digitalWrite(i,HIGH), i++);
}