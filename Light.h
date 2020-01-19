/**************************************************************************/
/*!
	Light class for the light library
	
	handels the specific Lights 
	
	disignt to be interchangebel with any other Light class that implement invert()
	, low() , high() and empty()
*/
/**************************************************************************/



#ifndef _Light_H
#define _Light_H

#include "Arduino.h"

class Light {
 public:
   Light(); // Constructor for an empty Lightobject, without coresponding physical Light
  Light(int pin1, int pin2 = -1); // Constructor for one or two connected Lights as one object / seperate controll not possible 
  void invert(void);  // inverts the Light
  void low(void);	// shuts off the light
  void high(void);	// turns on the light
  bool empty(void); // returns if the Lightobject is empty
  
 private:
	int _pin1;		// pins for the corresponding physical Lights
	int _pin2;

};
/**************************************************************************/

#endif