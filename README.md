# Light
 
 
A Arduinolibrary to control trafficlights.  
  
The Library contains four classes, the StreetLight class which controlls the trafficlights and runs the programm included programm tht runs the trafficlights, the Phase class, that is responsible for which lights are on when during the lightcycle and the Light and button class, who are actually comunicating with the hardware, these two are interchangable for other hardware, here they are using Ledlights and push buttons.

The programm itself lets a pre declared Light flash, when the trafficlight gets turned on and after an input startes the lightcycle, where it cycles through all pre declared phases till it eather stops because of a short input or it goes back to the flashing after a long input. When it is stopped another short input lets it continue. While it is flashing, after a certain time the light shutsoff completly and can be reactivated after another input.
All values can be modified during the runtime and phases can be overwritten.

The repository itself is the arduino library and can be used as is.
It also includes a documentation folder whith an example for a hardware circuit that works with all examples and a longer documentation in german.
The libraray naturaly comes with examples, the hardware_test_sketch, which can test the hardware and turns the lights on and of when the button is pressed,the functunal_example_without_library which has the above described behavior working on the example circuit without the extra functionality from the Phase, Button and Light classes and the custumisability from the Streetlight-class.
The last two examples are the setup_example and the support_example.Both actually use the Library. The setup_example shows how to setup the sketch so that the programm can run and what can be futher controlled while the support example is a mix between the previous two, it has the functionality of of the setup_example while having most of the programm inside the sketch to allow further customisability. 