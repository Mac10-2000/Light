/**************************************************************************/
/*!
Phase class for the Light Library

takes specific lights and makes them act in unison,also saves the duration of the phase

*/
/**************************************************************************/


#ifndef _Phase_H
#define _Phase_H

#include "Arduino.h"
#include <Light.h>
#include <Button.h>

class Phase {
	public :
	Phase( int time);//Constructor for zero Lights
	Phase(Light *light1, int time);//Constructor for 1 Lights
	Phase(Light *light1,Light *light2, int time);//Constructor for 2 Lights
	Phase(Light *light1,Light *light2,Light *light3, int time);//Constructor for 3 Lights
	void lowAll(void); // function to shutoff all Lights in the phase
	void highAll(void);// function to turn on all Lights in the phase
	void invertAll(void);// function toinvert all Lights in the phase
	int getdurration(void); // getter for the _time variable
	
	private:
	
	
	int _numLights; //saves the number of Lights in the phase

	Light * _light1;  
	Light * _light2;
	Light * _light3;
	int _time;  // saves the duration of the phase

};
/**************************************************************************/

#endif