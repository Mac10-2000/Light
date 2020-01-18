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

#ifndef _Button_H
#define _Button_H

#include "Arduino.h"


class Button {
 public:
 Button();
  Button(int pin);
  Button(int pin, bool pullUp);
  
  bool read(void);
  
 private:
    int _pin;
	bool _pullUp;
};
/**************************************************************************/

#endif