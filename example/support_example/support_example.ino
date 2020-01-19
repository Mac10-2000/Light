/**
 *  Support example sketch
 *  
 *  Most work is being done by the sketch itself for more controll
 *  Library acts only as support
 */


#include <Streetlights.h>


//declares button and lights
Button button(2);  
Light red(3);
Light yellow(4);
Light green(5);

// declare Timer
uint32_t shutoffTimer = millis();  //tImer for shutoff
uint32_t lightTimer = 0;   // timer for lightphases
uint32_t flashTimer = 0;  // timer for flashcycle
uint32_t interruptTimer = 0; // timer for the length of the input

uint32_t shutoffTime = 15  * 1000;  // time till shuoff in idlemode(flashing)
uint32_t lightPhase = 1000;   // default duration for the Phases
uint32_t flashPhase = 500;    // time for one statuschange during flash (on-off/off-on)

bool idleMode = true;   // (flashing or working)
bool stopLight = false;     // Not stopped(true) or stopped(false)
bool shutoffBool = false;   // shutoff or turned on
int lightMode = 1;          // which lightphase is currently executed




Streetlights street(&button,lightPhase,&red,&yellow,&green);  // setup for a Streetlight object


void setup() {
  street.setPhase(2000,1,&red);  // setup for the phases
  street.setPhase(1000,2,&red,&yellow);
  street.setPhase(2000,3,&green);
  street.setPhase(1000,4,&yellow);
  street.setMaxPhase(4);
  street.setFlashlight(2);// sets which light flashes (red =1, yellow = 2, green = 3)
}

void loop() {
if ((button.read())) {   //reads the button
    if (!shutoffBool) {
      interruptTimer = millis();
    }

    while ((button.read())) {
      delay(100);                   // measures how long it´s pressed
    }

    if (!shutoffBool && interruptTimer != 0) {    // checks if off
      if (millis() - interruptTimer > 2000) {   // long input : revert to flash
        idleMode = true;
        lightMode = 1;
        stopLight = false;
      } else {
        idleMode = false;                         // short input : start/stops lightcycle
        stopLight =  !stopLight;
        
      }
    } else {
      stopLight = false;                    // turns the light back on
      idleMode = true;
    }
    interruptTimer = 0;                     // register that the button was pressed, resets timer
    shutoffBool = false;
    shutoffTimer = millis();
    lightTimer = millis();
    flashTimer = millis();
}  
  if (idleMode) {
   if (millis() - flashTimer > flashPhase) {        // eather flases or executes the lightcycle
      street.flash();
      flashTimer=millis();
   }
  } else {
     if (millis() - lightTimer > lightPhase) {
      lightMode = street.light(lightMode,lightTimer,lightPhase,stopLight);
      lightPhase = street.getLightPhase(lightMode);
      lightTimer = millis();
      shutoffTimer=millis();
     }

  }
  if (millis() - shutoffTimer > shutoffTime) {   // checks for shutoff
    shutoffBool = true;
  }


    shutoffTimer=street.shutoff(shutoffBool,shutoffTimer); // shutsoff if nexessary
    shutoffBool=false;                                      // shutoffBoll should only be true inside of shutoff()
  
}
