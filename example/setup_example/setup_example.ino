/*
 * 
 * Setup example, shows all setup options of the library and which are necessary, which not
 * makes use of the runLight() methode to run the programm, easy if you just want start it
 * or the four submethods if you want more controll about what is happening between the steps
 * 
 */




#include <Streetlights.h>



Button button(2);
Light red(3);
Light yellow(4);
Light green(5);



Streetlights street(&button,1000,&red,&yellow,&green);


void setup() {
  street.setPhase(2000,1,&red); // declare phases
  street.setPhase(1000,2,&red,&yellow);
  street.setPhase(2000,3,&green);
  street.setPhase(1000,4,&yellow);
  street.setMaxPhase(4); // sets the number of phases declared UNDECLARED BEHAVIOR POSSIBLE
 /* NOT NECESSAEY  default 2*/street.setFlashlight(2);  // sets which light flashes (red =1, yellow = 2, green = 3)
 /* NOT NECESSAEY  default 1*/street.setFlashtime(1);  // sets the intervall for one flash
 /* NOT NECESSAEY  default 15*/street.setShutoffTime(15);  //  sets the period after which the light changes from flashing to off
 /* NOT NECESSAEY  default 2000*/street.setButtonDuration(2000);// sets the duration nascasary for a long input

}

void loop() {

 street.runLight();  // runs the Lightprogramm

 /*
  street.control(street.readButton()); // processing the button
  street.lightOperation();            // executes ether the light cycle or the flashing
  street.checkShutoff();              // checks if the light should be shut off and does so if necessary
  */

}
