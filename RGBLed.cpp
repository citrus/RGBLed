/**
* RGBLed Library
*
* Copyright 2010 Spencer Steffen, spencer@citrusme.com / http://citrusme.com
*/

#include "WProgram.h"
#include "RGBLed.h"

RGBLed::RGBLed(int red, int green, int blue) {
  _pins[RED]   = red;
  _pins[GREEN] = green;
  _pins[BLUE]  = blue;
  
  _values[BLUE]  = 1;
  _values[GREEN] = 0;
  _values[BLUE]  = 0;

  mode   = OFF;
  _pinOn = -1;
  _last  = -1;
  _cur   = 0;
  
  for (int i = 0; i < 3; i++) {
    pinMode(_pins[i], OUTPUT);
  }  
}

void RGBLed::animate() {
  int v = _values[_cur];
  if (0 <= _last) {
    _values[_last] -= 1;
    analogWrite(_pins[_last], _values[_last]);
  }
  v += 1;
  _values[_cur] = v;
  analogWrite(_pins[_cur], v);
  if (v == 255) {
     _last = _cur;
     _cur++;
  }
  if (_cur == 3) _cur = 0;
}

void RGBLed::red() {
  on(RED);
}
void RGBLed::green() {
  on(GREEN);
}
void RGBLed::blue() {
  on(BLUE);
}


void RGBLed::yellow() {
  if (_pinOn == YELLOW) return;
  off();
  mix(RED, GREEN);
  _pinOn = YELLOW;
}
void RGBLed::purple() {
  if (_pinOn == PURPLE) return;
  off();
  mix(RED, BLUE);
  _pinOn = PURPLE;  
}
void RGBLed::turquoise() {
  if (_pinOn == TURQUOISE) return;
  off();
  mix(GREEN, BLUE);
  _pinOn = TURQUOISE;  
}



void RGBLed::on(int color) {
  if (_pinOn == color) return;
  off();
  digitalWrite(_pins[color], HIGH);
  _pinOn = color;
}
void RGBLed::mix(int color1, int color2) {
  analogWrite(_pins[color1], 100);
  analogWrite(_pins[color2], 100);
}


void RGBLed::off() {
  if (_pinOn == -1) return;
  for (int i = 0; i < 3; i++) digitalWrite(_pins[i], LOW);
  _pinOn = -1;
  delayMicroseconds(10);
}

void RGBLed::next() {
  mode++;
  if (ANIMATE < mode) mode = OFF;
  switch(mode) {
    case RED:
      red();
      break;
    case GREEN:
      green();
      break;
    case BLUE:
      blue();
      break;
    case YELLOW:
      yellow();
      break;
    case PURPLE:
      purple();
      break;
    case TURQUOISE:
      turquoise();
      break;
    case OFF:
      off();
      break;
  }
}
