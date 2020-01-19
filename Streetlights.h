/**************************************************************************/
/*!
	Streetlights class for the Light library 
	
	handels the main processing and coordinates the other clases acts as hub
	
	works with any light or button classes who implement the light.h or button.h interfaces
*/
/**************************************************************************/



#ifndef _Streetlight_H
#define _Streetlight_H

#include "Arduino.h"
#include <Light.h>
#include <Button.h>
#include <Phase.h>
#include <assert.h>



class Streetlights {
 public:
  
  Streetlights(Button *button, int time, Light *l1,Light *l2= &Light()
  ,Light *l3= &Light() ,Light *l4= &Light(),Light *l5= &Light()); // Constructor, takes button, a base time to initialize all timers(can be changed later), and 1 to 5 lights 

  void flash(uint32_t timer = 0, uint32_t phase = 0,int light = -1); // flashes the chosen lamp/take the timer,flash duration and lightindex to flash
  void setFlashtime(double time = -1); // sets the duration of the flash in seconds(period from on on )
  uint32_t shutoff(bool shutoffBool, uint32_t timer);// shuts the light off after/ takes if it should shutoff/passes the timer through 
  void shutoff(void);// shuts the light off after a intern saved time has passed
  uint32_t light(int mode = -1, uint32_t timer= 0, uint32_t phase= 0, bool stopLight = false);//goes the saved phases through/ takes the actual phase, a timer since the phase started, how long it should last and if the light is stopped at the moment/ or uses intern saved numbers/ returns a timer since the phase started
  void runLight(void); // runs the complett Streetlight programm
  void phaseFlash(int phase);// allows to flash a howle phase, only inverts it, delay or other nesesary
  void setMaxPhase(int max);// sets the number of phases declared
  void setPhase(int time,int num,Light *l1,Light *l2= &Light(),Light *l3= &Light());// sets a specific phase at a specific index
  uint32_t  readButton(void);// reads the button
  bool checkShutoff(void);//checks if the shutoff time has passed and shuts the light off
  void lightOperation(void);// runs ether flash() or light() depending on _idleMode 
  void control(uint32_t timer);// runns the commandblock for the button that is executed after the button is read acording to the length of the input
  void setFlashlight(int light); // sets which light should flash depending on it´s index
  void setButtonDuration(int time = -1); //sets how long the button has to be pressed for a long input in milliseconds
  void setShutoffTime(int time = -1); //sets the time till shutoff in seconds
  uint32_t getLightPhase(int mode); // returns the phasle which is corresponds to the mode index
  void runLightIntern(void);	// a long version of runLight without primary function calls 
 private:
  
 
 	int _numLights;	// number of Lights declared
	int _flashlight;//which l Light is used in the flash
	


 Phase getPhase(int num);	//gets the phase at the given index

 void lowAll(void);			//turns off all Lights
 void highAll(void);		//turns on all Lights
 void invertAll(void);		//inverts all Lights
 
 Light *_l1;
 Light *_l2;
 Light *_l3;
 Light *_l4;
 Light *_l5; 
 
 Button *_button;
	
uint32_t _shutoffTimer;  // Timer for shutoff / lightOperation / flash and the reading of the button
uint32_t _lightTimer;
uint32_t _flashTimer;
uint32_t _interruptTimer;

uint32_t _shutoffTime;  // time till shutoff while the light flashes
uint32_t _interruptTime; // time the button has to be pressed to be conted as a long input
uint32_t _lightPhase;  // time one Phase of the light operation is running till the next
uint32_t _flashPhase; // time it takes to invert the lightstate once during a flash

bool _idleMode;			// if its flashing, just ideling(true) or working(false)
bool _stopLight;		// if the light is paused/stoped on one fase
bool _shutoffBool;		// if the light is shutoff
bool _interruptRunning;	// if the button is pressed ( not in shutoff())/ if the code is interrupded
int _lightMode;			//saves which phase is now active

int _phaseMax;			//how many phases are declared
Phase _Phase1;
Phase _Phase2;
Phase _Phase3;
Phase _Phase4;
Phase _Phase5;


};
/**************************************************************************/

#endif