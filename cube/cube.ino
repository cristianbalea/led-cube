volatile int state;
volatile int btn1 = 21;
//volatile int btn2 = 20;
//volatile int btn3 = 19;
//volatile int btn4 = 18;

void setup() {
  state = 0;

  for (int i = 0; i < 11; i++) {
    pinMode(i, OUTPUT);       // PINS0-10 are set as output
  }

  pinMode(A0, OUTPUT);        // PIN A0 set as output
  pinMode(A1, OUTPUT);        // PIN A1 set as output
  pinMode(A2, OUTPUT);        // PIN A2 set as output

  digitalWrite(A0, HIGH);     // pull up the A0 pin
  digitalWrite(A1, HIGH);     // pull up the A1 pin
  digitalWrite(A2, HIGH);     // pull up the A2 pin

  pinMode(btn1, INPUT);
//  pinMode(btn2, INPUT);
//  pinMode(btn3, INPUT);
//  pinMode(btn4, INPUT);

  attachInterrupt(digitalPinToInterrupt(btn1), a1, RISING);
//  attachInterrupt(digitalPinToInterrupt(btn2), a2, RISING);
//  attachInterrupt(digitalPinToInterrupt(btn3), a3, RISING);
//  attachInterrupt(digitalPinToInterrupt(btn4), a4, RISING);
}

void miniBlink(int led, int time) {
  digitalWrite(led + 1, HIGH);
  delay(time);
  digitalWrite(led + 1, LOW);
}

void miniBlinkArr(int leds[], int nrOfLeds, int time) {
  for (int i = 0; i < nrOfLeds; i++) {
    digitalWrite(leds[i] + 1, HIGH);
  }

  delay(time);

  for (int i = 0; i < nrOfLeds; i++) {
    digitalWrite(leds[i] + 1, LOW);
  }
}

void activateAll() {
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
}

void deactivateAll() {
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
}

void blink(int leds[], int nrOfLeds, int level, int time) {
  int lvl;

  switch (level) {
    case 1 : lvl = A0; break;
    case 2 : lvl = A1; break;
    case 3 : lvl = A2; break;
  }

  digitalWrite(lvl, LOW);
  for (int i = 0; i < nrOfLeds; i++) {
    digitalWrite(leds[i] + 1, HIGH);
  }
  delay(time);
  for (int i = 0; i < nrOfLeds; i++) {
    digitalWrite(leds[i] + 1, LOW);
  }
  digitalWrite(lvl, HIGH);
}

void loop() {
  if (state == 0) {
    /** Animatia #1 **/
    anim1();
  }
  else if (state == 1) {
    /** Animatia #4 **/
    anim4();
  }
  else if (state == 2) {
    /** Animatia #2 **/
    anim2();
  }
  else if (state == 3) {
    /** Animatia #1 **/
    for (int i = 0; i < 20; i++) {
      if (state != 3) break;
      anim1();
    }

    /** Animatia #2 **/
    for (int i = 0; i < 20; i++) {
      if (state != 3) break;
      anim2();
    }

    /** Animatia #3 **/
    for (int k = 0; k < 20; k++) {
      if (state != 3) break;
      anim3();
    }

    /** Animatia #4 **/
    for (int k = 0; k < 20; k++) {
      if (state != 3) break;
      anim4();
    }

    /** Animatia #5 **/
    for (int k = 0; k < 20; k++) {
      if (state != 3) break;
      anim5();
    }

    /** Animatia #6 **/
    for (int k = 0; k < 20; k++) {
      if (state != 3) break;
      anim6();
    }

    /** Animatia #7  **/
    for (int k = 0; k < 20; k++) {
      if (state != 3) break;
      anim7();
    }
    
  }
}


void a1() {
  state = (state + 1) % 4;
}

//void a2() {
//  state = 1;
//}
//
//void a3() {
//  state = 2;
//}
//
//void a4() {
//  state = 3;
//}

void anim1() {
  int v1[] = {1, 2, 3};
  int v2[] = {4, 5, 6};
  int v3[] = {7, 8, 9};
  activateAll();
  miniBlinkArr(v1, 3, 200);
  miniBlinkArr(v2, 3, 200);
  miniBlinkArr(v3, 3, 200);
  deactivateAll();
}

void anim2() {
  int corner[] = {1, 3, 7, 9};
  int center[] = {2, 4, 5, 6, 8};
  activateAll();
  miniBlinkArr(corner, 4, 200);
  miniBlinkArr(center, 5, 200);
  deactivateAll();
}

void anim3() {
  int up[] = {1, 2, 3};
  int left[] = {1, 4, 7};
  int down[] = {7, 8, 9};
  int right[] = {3, 6, 9};
  activateAll();

  miniBlinkArr(up, 3, 100);
  miniBlinkArr(left, 3, 100);
  miniBlinkArr(down, 3, 100);
  miniBlinkArr(right, 3, 100);

  deactivateAll();
}

void anim4() {
  int all[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  blink(all, 9, 1, 200);
  blink(all, 9, 2, 200);
  blink(all, 9, 3, 200);
  blink(all, 9, 3, 200);
  blink(all, 9, 2, 200);
  blink(all, 9, 1, 200);
}

void anim5() {
  activateAll();

  digitalWrite(6, HIGH);  // led 5

  miniBlink(1, 100);
  miniBlink(2, 100);
  miniBlink(3, 100);
  miniBlink(6, 100);
  miniBlink(9, 100);
  miniBlink(8, 100);
  miniBlink(7, 100);
  miniBlink(4, 100);

  digitalWrite(6, LOW);

  deactivateAll();
}

void anim6() {
  activateAll();

  miniBlink(1, 50);
  miniBlink(2, 50);
  miniBlink(3, 50);
  miniBlink(6, 50);
  miniBlink(9, 50);
  miniBlink(8, 50);
  miniBlink(7, 50);
  miniBlink(4, 50);
  miniBlink(5, 50);

  delay(200);

  deactivateAll();
}
void anim7() {
  activateAll();
  int all[] = {1,2,3,4,5,6,7,8,9};
  miniBlinkArr(all, 9, 200);
  deactivateAll();
}
