const int LED_NUM = 1;
int leds[LED_NUM] =  {5};

int switches[LED_NUM] = {6};

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < LED_NUM; i++){
    pinMode(leds[i], OUTPUT);
    pinMode(switches[i], INPUT);
  }
}

void loop() {
  
  for(int i = 0; i < LED_NUM; i++) {
    int state = digitalRead(switches[i]);
    Serial.print(state);
    if(state == HIGH) {
      
      digitalWrite(leds[i], LOW); 
    } else {
      digitalWrite(leds[i], HIGH);
    }
  }
}
