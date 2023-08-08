const int led_1 = 10;    //LED row 1
const int led_2 = 9;     //LED row 2    
const int led_3 = 8;     //LED row 3
const int led_4 = 7;     //LED row 4
const int switchIn = 6;
const int delayT = 175;
const int ground = 2;	//ground for switch
const int supply = 1;	//supply for switch

bool buttonState = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchIn, INPUT);
  pinMode(ground, OUTPUT);
  pinMode(supply, OUTPUT);
}

void loop() {
  buttonState = digitalRead(switchIn);

  if (buttonState == HIGH) {
    for (int led = 0; led <12; led++) {
      chooseLed(led);
      } 
    }
  else {
    int led = random(12);
    chooseLed(led);
  }
}

void chooseLed(int led) {
    switch (led) {
      case 0: l(led_1); h(led_2); z(led_3); z(led_4); break; //1
      case 1: h(led_1); l(led_2); z(led_3); z(led_4); break; //2
      case 2: z(led_1); l(led_2); h(led_3); z(led_4); break; //3
      case 3: z(led_1); h(led_2); l(led_3); z(led_4); break; //4
      case 4: h(led_1); z(led_2); l(led_3); z(led_4); break; //5
      case 5: l(led_1); z(led_2); h(led_3); z(led_4); break; //6
      case 6: z(led_1); z(led_2); l(led_3); h(led_4); break; //7
      case 7: z(led_1); z(led_2); h(led_3); l(led_4); break; //8
      case 8: z(led_1); l(led_2); z(led_3); h(led_4); break; //9
      case 9: z(led_1); h(led_2); z(led_3); l(led_4); break; //10
      case 10: l(led_1); z(led_2); z(led_3); h(led_4); break; //11
      case 11: h(led_1); z(led_2); z(led_3); l(led_4); break; //12
      }
  delay(delayT);
}

// logic tri-state
void z(int led) {
  pinMode(led, INPUT);
  digitalWrite(led, LOW);
}

//logic high
void h(int led) {
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
}

//logic low
void l(int led) {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}
