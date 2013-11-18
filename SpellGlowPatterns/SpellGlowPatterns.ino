#include "LPD8806.h"
#include "SPI.h"

int nLEDs = 572;

// Chose 2 pins for output; can be any valid output pins:
int dataPin  = 6;
int clockPin = 7;
int columns[] = {52, 104, 156, 208, 260, 312, 364, 416, 468, 520, 572};
int letters[] = {108, 203, 212, 307, 316, 411, 420, 409, 320, 405, 428, 403, 324, 299, 220, 195, 116, 123, 190, 224, 295, 328, 398, 435, 437, 392, 336, 287, 232, 184, 125, 442, 444, 446, 448, 383, 344, 279, 240, 175, 136, 348, 349, 350, 378, 455, 457, 372, 356, 267, 252, 164, 145, 143, 170};

void setup() {
  // Start up the LED strip
  strip.begin();

  // Update the strip, to start they are all 'off'
  strip.show();
}

//rainbow "GLOW" that slowly changes colors
void DynamicGlow(){
    for (int j=0; j < 384; j++) {     // 3 cycles of all 384 colors in the wheel
    for (int i=0; i < 55; i++) {
      strip.setPixelColor(letters[i], Wheel( (i + j) % 384));
    }  
    strip.show();   // write all the pixels out
    delay(0);
  }
}

//spell yellow "GLOW"
void YellowGlow(){
  for(int i = 0; i < 55; i ++){
    strip.setPixelColor(letters[i], strip.Color(127, 127, 0));
  }
  strip.show();
}

//rainbow "GLOW"
void RainbowGlow(){
  for (int j=0; j < 384 * 5; j++) {     // 5 cycles of all 384 colors in the wheel
    for (int i=0; i < 55; i++) {
      strip.setPixelColor(letters[i], Wheel( ((i * 384 / 55) + j) % 384) );
    }  
    strip.show();   
    delay(5);
  }
}

uint32_t Wheel(uint16_t WheelPos)
{
  byte r, g, b;
  switch(WheelPos / 128)
  {
    case 0:
      r = 127 - WheelPos % 128;   //Red down
      g = WheelPos % 128;      // Green up
      b = 0;                  //blue off
      break; 
    case 1:
      g = 127 - WheelPos % 128;  //green down
      b = WheelPos % 128;      //blue up
      r = 0;                  //red off
      break; 
    case 2:
      b = 127 - WheelPos % 128;  //blue down 
      r = WheelPos % 128;      //red up
      g = 0;                  //green off
      break; 
  }
  return(strip.Color(r,g,b));
}
