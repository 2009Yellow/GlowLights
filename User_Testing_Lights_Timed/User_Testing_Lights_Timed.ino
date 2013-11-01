#include "LPD8806.h"
#include "SPI.h"

// Example to control LPD8806-based RGB LED Modules in a strip

/*****************************************************************************/

// Number of RGB LEDs in strand:
int nLEDs = 432;

// Chose 2 pins for output; can be any valid output pins:
int dataPin  = 2;
int clockPin = 3;
int command;

// First parameter is the number of LEDs in the strand.  The LED strips
// are 32 LEDs per meter but you can extend or cut the strip.  Next two
// parameters are SPI data and clock pins:
LPD8806 strip = LPD8806(nLEDs, dataPin, clockPin);

// You can optionally use hardware SPI for faster writes, just leave out
// the data and clock pin parameters.  But this does limit use to very
// specific pins on the Arduino.  For "classic" Arduinos (Uno, Duemilanove,
// etc.), data = pin 11, clock = pin 13.  For Arduino Mega, data = pin 51,
// clock = pin 52.  For 32u4 Breakout Board+ and Teensy, data = pin B2,
// clock = pin B1.  For Leonardo, this can ONLY be done on the ICSP pins.
//LPD8806 strip = LPD8806(nLEDs);

void setup() {
  // Start up the LED strip
  Serial.begin(9600);
  strip.begin();

  // Update the strip, to start they are all 'off'
  strip.show();
}


void loop() {
        if(Serial.available()){
        command = Serial.read();
        switch(command){
          case 1:
            pixelsOff();
            StartPose();       
            delay(5000);
            pixelsOff();
            DownwardDog();
            
            delay(14000);
            pixelsOff();
            Warrior(strip.Color(0,127,127));
            delay(57000);
            pixelsOff();
            DownwardDog();
            delay(4000);
            DownwardDog2Red();
            delay(3000);
            DownwardDog();
            delay(5000);
            pixelsOff();
            Warrior(strip.Color(0,127,127));
            delay(37000);
            Warrior2Red();
            delay(4000);
            Warrior(strip.Color(0,127,127));
            delay(3000);
            pixelsOff();
            DownwardDog();
            delay(16000);
            colorSideEdges(strip.Color(0, 100, 0));
            colorFrontEdges(strip.Color(0, 100, 0));
            delay(5000);
            pixelsOff();
            break;
          case 2:
            pixelsOff();
            break;
            
      }
   }
}


void colorSideEdges(uint32_t c) {
	int i;

	for (i = 0; i < 48; i++) {
		strip.setPixelColor(i, c);
		strip.setPixelColor(431 - i, c);
	}
	strip.show();
}
void colorFrontEdges(uint32_t c){
	strip.setPixelColor(48, c);
	strip.setPixelColor(95, c);
	strip.setPixelColor(96, c);
	strip.setPixelColor(143, c);
	strip.setPixelColor(144, c);
	strip.setPixelColor(191, c);
	strip.setPixelColor(192, c);
	strip.setPixelColor(239, c);
	strip.setPixelColor(240, c);
	strip.setPixelColor(287, c);
	strip.setPixelColor(288, c);
	strip.setPixelColor(335, c);
	strip.setPixelColor(336, c);
	strip.setPixelColor(383, c);
	strip.show();
}
void pixelsOff(){
	for (int i = 0; i < strip.numPixels(); i++) {
		strip.setPixelColor(i, 0); // Erase pixel, but don't refresh!
	}
	strip.show();
}

void DownwardDog(){
	strip.setPixelColor(87, strip.Color(0, 0, 127));
	strip.setPixelColor(89, strip.Color(0, 0, 127));
	strip.setPixelColor(91, strip.Color(0, 0, 127));
	strip.setPixelColor(6, strip.Color(0, 0, 127));
	strip.setPixelColor(102, strip.Color(0, 0,127));

	strip.setPixelColor(375, strip.Color(0, 0, 127));
	strip.setPixelColor(377, strip.Color(0, 0, 127));
	strip.setPixelColor(379, strip.Color(0, 0, 127));
	strip.setPixelColor(390, strip.Color(0, 0, 127));
	strip.setPixelColor(294, strip.Color(0, 0, 127));

	strip.setPixelColor(50, strip.Color(0, 127, 127));
	strip.setPixelColor(52, strip.Color(0, 127, 127));
	strip.setPixelColor(54, strip.Color(0, 127, 127));
	strip.setPixelColor(43, strip.Color(0, 127, 127));
	strip.setPixelColor(139, strip.Color(0, 127, 127));

	strip.setPixelColor(338, strip.Color(0, 127, 127));
	strip.setPixelColor(340, strip.Color(0, 127, 127));
	strip.setPixelColor(342, strip.Color(0, 127, 127));
	strip.setPixelColor(427, strip.Color(0, 127, 127));
	strip.setPixelColor(331, strip.Color(0, 127, 127));
	strip.show();

}

void DownwardDog2Red(){
	strip.setPixelColor(87, strip.Color(127, 0, 0));
	strip.setPixelColor(89, strip.Color(127, 0, 0));
	strip.setPixelColor(91, strip.Color(127, 0, 0));
	strip.setPixelColor(6, strip.Color(127, 0, 0));
	strip.setPixelColor(102, strip.Color(127, 0, 0));

	strip.setPixelColor(375, strip.Color(127, 0, 0));
	strip.setPixelColor(377, strip.Color(127, 0, 0));
	strip.setPixelColor(379, strip.Color(127, 0, 0));
	strip.setPixelColor(390, strip.Color(127, 0, 0));
	strip.setPixelColor(294, strip.Color(127, 0, 0));
	strip.show();
}
void Warrior(uint32_t c){
	strip.setPixelColor(196, c);
	strip.setPixelColor(198, c);
	strip.setPixelColor(200, c);
	strip.setPixelColor(185, c);
	strip.setPixelColor(281, c);

	strip.setPixelColor(233, c);
	strip.setPixelColor(235, c);
	strip.setPixelColor(237, c);
	strip.setPixelColor(148, c);
	strip.setPixelColor(244, c);
	strip.show();
}

void Warrior2Red(){
	strip.setPixelColor(233, strip.Color(127, 0, 0));
	strip.setPixelColor(235, strip.Color(127, 0, 0));
	strip.setPixelColor(237, strip.Color(127, 0, 0));
	strip.setPixelColor(148, strip.Color(127, 0, 0));
	strip.setPixelColor(244, strip.Color(127, 0, 0));
	strip.show();
}

void StartPose(){
	strip.setPixelColor(89, strip.Color(0, 127, 127));
        strip.setPixelColor(100, strip.Color(0, 127, 127));
	strip.setPixelColor(102, strip.Color(0, 127, 127));
        strip.setPixelColor(104, strip.Color(0, 127, 127));
        strip.setPixelColor(185,strip.Color(0, 127, 127));
        
        strip.setPixelColor(292, strip.Color(0, 127, 127));
        strip.setPixelColor(294, strip.Color(0, 127, 127));
        strip.setPixelColor(296, strip.Color(0, 127, 127));
        strip.setPixelColor(281, strip.Color(0, 127, 127));
        strip.setPixelColor(377, strip.Color(0, 127, 127));
        
        strip.show();
        delay(9000);
        strip.setPixelColor(87, strip.Color(0, 0, 127));
	strip.setPixelColor(91, strip.Color(0, 0, 127));
	strip.setPixelColor(6, strip.Color(0, 0, 127));
        //strip.setPixelColor(100, strip.Color(0, 127, 0));

	strip.setPixelColor(375, strip.Color(0, 0, 127));
	strip.setPixelColor(379, strip.Color(0, 0, 127));
	strip.setPixelColor(390, strip.Color(0, 0, 127));
	//strip.setPixelColor(294, strip.Color(0, 127, 0));
        strip.show();
}


