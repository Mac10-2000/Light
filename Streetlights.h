/**************************************************************************/
/*!
  @file Adafruit_GPS.h

  This is the Adafruit GPS library - the ultimate GPS library
  for the ultimate GPS module!

  Tested and works great with the Adafruit Ultimate GPS module
  using MTK33x9 chipset
      ------> http://www.adafruit.com/products/746
  Pick one up today at the Adafruit electronics shop
  and help support open source hardware & software! -ada

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada  for Adafruit Industries.
  BSD license, check license.txt for more information
  All text above must be included in any redistribution
*/
/**************************************************************************/

// Fllybob added lines 34,35 and 40,41 to add 100mHz logging capability

#ifndef _Streetlight_H
#define _Streetlight_H

#include "Arduino.h"
#include <Light.h>
#include <Button.h>
#include <Phase.h>
#include <assert.h>



class Streetlights {
 public:
  
  Streetlights(Button *button, int time, Light *l1,Light *l2= &Light(),Light *l3= &Light() ,Light *l4= &Light(),Light *l5= &Light()); // Constructor 
  void invertRed(void);
  void invertYellow(void);
  void invertGreen(void);
  void flash(int light = -1);
  void shutoff(bool shutoffBool);
  void shutoff(void);
  void light(void);
  void runLight(void);
  void phase(int phase);
  void setMaxPhase(int max);
  void setPhase(int time,int num,Light *l1,Light *l2= &Light(),Light *l3= &Light());
  uint32_t  readButton(void);
  void shutoffAfter(uint32_t shutoff );
  bool checkShutoff(void);
  void lightOperation(void);
  void control(uint32_t timer);
  void setFlashlight(int light);
  
 private:
 	int _numLights;
	int _flashlight;
 
 Light *_l1;
 Light *_l2;
 Light *_l3;
  Light *_l4;
   Light *_l5;
 
 
 Phase getPhase(int num);
 
 //void init(Light *red,Light *yellow,Light *green, Button *button);
	
 void lowAll(void);
 void highAll(void);
 void invertAll(void);
 


int _phaseMax;
 
 Button *_button;
	
uint32_t _shutoffTimer;
uint32_t _lightTimer;
uint32_t _flashTimer;
uint32_t _interruptTimer;

uint32_t _shutoffTime;
uint32_t _lightPhase;
uint32_t _flashPhase;

bool _idleMode;
bool _stopLight;
bool _shutoffBool;
bool _interruptRunning;
int _lightMode;

Phase _Phase1;
Phase _Phase2;
Phase _Phase3;
Phase _Phase4;
Phase _Phase5;


};
/**************************************************************************/

#endif