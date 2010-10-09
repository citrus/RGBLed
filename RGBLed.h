/**
* RGBLed Library
*
* Copyright 2010 Spencer Steffen, spencer@citrusme.com / http://citrusme.com
*/

#ifndef RGBLed_h
#define RGBLed_h

#define OFF      -1 
#define RED       0
#define GREEN     1
#define BLUE      2
#define YELLOW    3
#define PURPLE    4
#define TURQUOISE 5
#define ANIMATE   6

#include "WProgram.h"

class RGBLed {
  public:
    RGBLed(int red, int green, int blue);
    void on(int color);
    void mix(int color1, int color2);
    void off();
    void red();
    void green();
    void blue();
    void yellow();
    void purple();
    void turquoise();
    void animate();
    void next();
    int  mode;
  private:
    int _pins[3];
    int _values[3];
    int _last;
    int _cur;
    int _pinOn;
};

#endif
