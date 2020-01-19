/**************************************************************************/
/*!
	Button class for the light library
	
	handels the Input 
	
	disignt to be interchangebel with any other Button class that implements read()
*/
/**************************************************************************/



#ifndef _Button_H
#define _Button_H

#include "Arduino.h"


class Button {
 public:
  Button(); // default Constructor 
  Button(int pin); // Constructor for a button with pullupresistor 
  Button(int pin, bool pullUp); // Constructor for a button with ,or without pullupresistor
  
  bool read(void); // reads the button / returns if pressed true
  
 private:
    int _pin;		// saves the pin of the button
	bool _pullUp;	// saves if a pullupresistor is used (true) or a pulldown (false)
};
/**************************************************************************/

#endif