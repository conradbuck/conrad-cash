#define PUSH 5 //button pin, GPIO

#define LONG_PRESS 700 //long press length in ms (best 700-1200)

unsigned long difference;
bool longPress = false;


void setup() {
  pinMode(PUSH, INPUT_PULLUP);
  //connect other button pin to ground
  
  difference = millis();
}

void loop() {
  if(!digitalRead(PUSH)) {
    difference = millis();
    longPress = false;
    while(!digitalRead(PUSH)) {
      if(millis() - difference > LONG_PRESS) {
        longPress = true;
        //put code that activates when a long press is detected here
        while(!digitalRead); //ensures that longPress code only runs once
      }
    }
    if(!longPress) {
      //put short press code here
    }
    delay(20); //simple delay to ingore switch rebounce
  }

}
