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

#ifndef _Phase_H
#define _Phase_H

#include "Arduino.h"
#include <Light.h>
#include <Button.h>

class Phase {
	public :
	Phase(Light *light1,Light *light2, int time);
	Phase(Light *light1, int time);
	Phase(Light **lights,int numLights, int time);
	Phase(Light *light1,Light *light2,Light *light3, int time);
	Phase( int time);
	void lowAll(void);
	void highAll(void);
	void invertAll(void);
	int getdurration(void);
	
	private:
	
	
	int _numLights;

	Light * _light1;
	Light * _light2;
	Light * _light3;
	int _time;

};
/**************************************************************************/

#endif