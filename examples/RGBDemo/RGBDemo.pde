#include <RGBLed.h>

#define BTN_PIN A4
#define POT_PIN A5

int _btnDown;
int _value;
int _delay;

RGBLed led = RGBLed(9,10,11);


void setup() {
  pinMode(BTN_PIN, INPUT);
  pinMode(POT_PIN, INPUT);
  Serial.begin(115200);
}

void loop() {

  Serial.print("MODE: ");
  Serial.println(led.mode);
  
  _btnDown = digitalRead(BTN_PIN);
  if (_btnDown == 1) {
    led.next();
    delay(250);
    return;
  }

  if (led.mode < ANIMATE) return;  
  led.animate();
  
  _value = analogRead(POT_PIN);
  _delay = map(_value, 0, 1023, 2, 99);
  delay(_delay);
}

