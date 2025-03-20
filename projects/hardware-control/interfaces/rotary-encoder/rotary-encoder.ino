#define LEFT 2
#define RIGHT 3

int ticker = 0;
int delta;

uint8_t lrmem = 3;
int lrsum = 0;
int rotary() {
  static int8_t TRANS[] = {0, -1, 1, 14, 1, 0, 14, -1, -1, 14, 0, 1, 14, 1, -1, 0};
  int8_t l, r;

  l = digitalRead(LEFT);
  r = digitalRead(RIGHT);

  lrmem = ((lrmem & 0x03) << 2) + 2 * l + r;
  lrsum = lrsum + TRANS[lrmem];

  if (lrsum % 2 != 0) { //change 2 to 4 if encoder double counts
    return (0);
  }

  if (lrsum == 2) { //change 2 to 4 if encoder double counts
    lrsum = 0;
    return (1);
  }
  if (lrsum == -2) { //change 2 to 4 if encoder double counts
    lrsum = 0;
    return (-1);
  }
  /* lrsum > 0 if the impossible transition */
  lrsum = 0;
  return (0);
}

void setup() {
  //3 pin side of rotary encoder
  pinMode(LEFT, INPUT_PULLUP); //outer pin to microcontroller
  pinMode(RIGHT, INPUT_PULLUP); //outer pin to microcontroller
  //central pin connects to ground

  //2 pin side of rotary encoder
  //initialize push switch pin as INPUT_PULLUP
  //connect the other pin to ground

}

void loop() {
  delta = rotary();
  ticker += delta;
  
  if(delta != 0) { //delta will automatically reset to 0 next time rotary() is called
    Serial.println(ticker); 
  }

}
