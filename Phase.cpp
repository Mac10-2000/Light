#include <Phase.h>

 static void high(Light light);
 static void low(Light light);
 static void invert(Light light);



Phase::Phase(Light *light1,Light *light2,Light *light3, int time){
_numLights=3;
_light1 = light1;
_light2 = light2;
_light3 = light3;

	_time = time;
	
}

Phase::Phase(Light *light1,Light *light2, int time){
_numLights=2;
_light1 = light1;
_light2 = light2;
	_time = time;
	
}

Phase::Phase(Light *light1, int time){
	_numLights=1;
	_light1 = light1;
	_time = time;
	
}
Phase::Phase( int time){
	_time = time;
	_numLights=0;
}

int Phase::getdurration(void){
	return _time;
}
void Phase::lowAll(void){
		if(_numLights >0 ) 
	{_light1->low();}
	if(_numLights >1 ) 
	{_light2->low();}
	if(_numLights >2 ) 
	{_light3->low();}

}
void Phase::highAll(void){
		if(_numLights >0 ) 
	{_light1->high();}
	if(_numLights >1 ) 
	{_light2->high();}
	if(_numLights >2 ) 
	{_light3->high();}
	
}
void Phase::invertAll(void){
	
	if(_numLights >0 ) 
	{_light1->invert();}
	if(_numLights >1 ) 
	{_light2->invert();}
	if(_numLights >2 ) 
	{_light3->invert();}


}



 static void high(Light light)// inverts the pinstate of the pin used
{
  light.high();
}
 static void low(Light light)// inverts the pinstate of the pin used
{
  light.low();
}
 static void invert(Light light)// inverts the pinstate of the pin used
{
  light.invert();
}