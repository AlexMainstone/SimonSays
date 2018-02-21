/*
 * Author: Alex Mainstone
 * Username: eeuae3
 * Date: 11/02/2018
 */

//This will make my code extendable, allowing for users to add their own switch and LED
const int LED_NUM = 4;
const int leds[LED_NUM] =  {3,4,5,2};
const int switches[LED_NUM] = {8,7,6,9};

int level = 0; //the number of leds in the level
int current = 0; //current place in order
const int MAX_LEVEL = 100; //The maximum level
int order[MAX_LEVEL] = {};

void setup() {
  for(int i = 0; i < LED_NUM; i++){ //Enable all LED's and Buttons
    pinMode(leds[i], OUTPUT);
    pinMode(switches[i], INPUT);
  }
  compTurn();
}

//Flashes the desired LED
void flashLED(int LED) {
  delay(1000);
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
}

//Generates the next member of the sequence
void compTurn() {
  current = 0;
  order[level++] = leds[rand() % LED_NUM];
  for(int i = 0; i < level; i++) {
    flashLED(order[i]); 
  }
}

//Flashes all LEDs
void fail() {
  for(int i = 0; i < LED_NUM; i++) {
    digitalWrite(leds[i], HIGH);
  }
  delay(1000);
  for(int i = 0; i < LED_NUM; i++) {
    digitalWrite(leds[i], LOW);
  }
  level = 0;
  compTurn();
}

void loop() {
  for(int i = 0; i < LED_NUM; i++) {
    int state = digitalRead(switches[i]);
    if(state == HIGH){
      while(state == HIGH) { state = digitalRead(switches[i]); } //Wait until the button is released
      if(order[current] == leds[i]) {
        current++;
        if(current == level){
          compTurn();
        }
      } else {
        fail();
      }
    }
  }
}
