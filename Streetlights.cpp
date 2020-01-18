#include <Streetlights.h>

 static void high(Light light);
 static void low(Light light);
 static void invert(Light light);





Streetlights::Streetlights( Button *button, int time,Light *l1,Light *l2,Light *l3 ,Light *l4,Light *l5):	
  _Phase1(time),_Phase2(time),_Phase3(time),_Phase4(time),_Phase5(time)
{
	_l1=l1;
	_l2=l2;
	_l3=l3;
	_l4=l4;
	_l5=l5;
	_button = button;
	
	if(_l2->empty()){
	_numLights = 1;}
	else if(_l3->empty()){
	_numLights = 2;}
	else if(_l4->empty()){
	_numLights = 3;}
	else if(_l5->empty()){
	_numLights = 4;}
	else{
	_numLights = 5;}

	_shutoffTimer = millis();
	_lightTimer = 0;
	_flashTimer = 0;
	_interruptTimer = 0;

	_shutoffTime = 15  * 1000;
	_lightPhase = 1000;
	_flashPhase = 500;

	_idleMode = true;
	_stopLight = false;
	_shutoffBool = false;
	_interruptRunning = false;
	_lightMode = 0;
	

	
	_flashlight=2;

	
	_phaseMax=0;

}
void Streetlights::setMaxPhase(int max){
	assert(max<=5);
	_phaseMax=max;
}
void Streetlights::setFlashlight(int light){
	if(light>0&&light<=_numLights){
	_flashlight=light;}
}

void Streetlights::setPhase(int time,int num,Light *l1,Light *l2,Light *l3 ) {



	Phase phase = l3->empty() ? 
								l2->empty() ? Phase(l1,time)
								:Phase(l1,l2,time)
				:Phase(l1,l2,l3,time);
	
	
	switch (num){
		case 1 :
			 _Phase1= phase;
			break;
		case 2 :
			 _Phase2= phase;
			break;
					case 3 :
			 _Phase3= phase;
			break;
					case 4 :
			 _Phase4= phase;
			break;
			case 5 :
			 _Phase5= phase;
			break;
	}

	//_phaseMax=5;
}

void Streetlights::lowAll(void){
Serial.print("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
	_l1->low();
	if(_numLights>1){
	_l2->low();
	}
	if(_numLights>2){
	_l3->low();
	}
	if(_numLights>3){
	_l4->low();
	}
	if(_numLights>4){
	_l5->low();
	}
	
	
}
void Streetlights::highAll(void){
	_l1->high();	 Serial.print("////////////////////////////////////////////");
	 if(_numLights>1){
	_l2->high();
	}
	if(_numLights>2){
	_l3->high();
	}
	if(_numLights>3){
	_l4->high();
	}
	if(_numLights>4){
	_l5->high();
	}
	
}
void Streetlights::invertAll(void){
	_l1->invert();
	 if(_numLights>1){
	_l2->invert();
	}
	if(_numLights>2){
	_l3->invert();
	}
	if(_numLights>3){
	_l4->invert();
	}
	if(_numLights>4){
	_l5->invert();
	}
	
}
void Streetlights::phase(int phase){
	getPhase(phase).invertAll();
}

void Streetlights::light(void) {	 Serial.print("++++++++++++++++++++++++++++++++");
	
  if (_stopLight) {
	//  if(true){
	lowAll();
  //high(phases[_lightMode]);

    //_l1->low();
  // _l2->low();
   // _l3->low();
   /* switch (_lightMode) {

      case 0 :
        _l1->high();
        _lightMode++;
        break;
      case 1 :
         _l1->high();
        _l2->high();
        _lightMode++;
        break;
      case 2 :
      case 3:
        _l3->high();
        _lightMode++;
        break;
      case 4 :
        _l2->high();
        _lightMode++;
        break;
      case 5 :
         _l1->high();
        _lightMode++;
        break;
      default :
         _l1->high();
        _lightMode = 0;
 
        break;
    }*/
    
	getPhase(_lightMode).highAll();

	_lightPhase=  getPhase(_lightMode).getdurration();Serial.print(_lightMode);
	_lightMode++;
	
	Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	if(_phaseMax<_lightMode)
	{
		_lightMode=1;
	}
	_shutoffTimer = millis();
    _lightTimer = millis();
  }
}

void Streetlights::flash(int light) {	 Serial.print("--------------------------------------");
	if(light<0){
		light=_flashlight;
	}else{
		setFlashlight(light);
	}
	
	if(light==1){
	_l1->invert();}
	else{_l1->low();}
	
	if(_numLights>1){
	if(light==2){
	_l2->invert();}
	else{_l2->low();}
	}
	
	if(_numLights>2){
	if(light==3){
	_l3->invert();}
	else{_l3->low();}
	}
	
	if(_numLights>3){
	if(light==4){
	_l4->invert();}
	else{_l4->low();}
	}
	
	if(_numLights>4){
	if(light==5){
	_l5->invert();}
	else{_l5->low();}
	}


  _flashTimer = millis();
}

void Streetlights::shutoff(bool shutoffBool ) {
	  _shutoffBool = shutoffBool;
	  lowAll();
 while (_shutoffBool && !(_button->read())) {
    delay(100);
  }
  while((_button->read())) {
    delay(100);
  }
  _shutoffBool = false;
  _shutoffTimer = millis();
}
void Streetlights::shutoff(void ) {

	  lowAll();
 while (_shutoffBool && !(_button->read())) {
    delay(100);
  }
  while((_button->read())) {
    delay(100);
  }
  _shutoffBool = false;
  _shutoffTimer = millis();
}
uint32_t Streetlights::readButton(void){
	uint32_t buttonTimer = 0;
	if ((_button->read())) {
    if (!_shutoffBool) {
      buttonTimer = millis();
    }

    while ((_button->read())) {
      delay(100);
    }
	}
	 _interruptTimer=buttonTimer;
	return buttonTimer;
}
void Streetlights::control(uint32_t timer){
	_interruptTimer = timer;
	if (!_shutoffBool && _interruptTimer != 0) {
      if (millis() - _interruptTimer > 2000) {
        _idleMode = true;
        _lightMode = 0;
        _stopLight = false;
      } else {
        _idleMode = false;
        _stopLight =  !_stopLight;
        
      }
    } else {
      _stopLight = false;
      _idleMode = true;
    }
    _interruptTimer = 0;
    _shutoffBool = false;
    _shutoffTimer = millis();
    _lightTimer = millis();
    _flashTimer = millis();
}

void Streetlights::runLight(void){
	
	if ((_button->read())) {
    if (!_shutoffBool) {
      _interruptTimer = millis();
    }

    while ((_button->read())) {
      delay(100);
    }

    if (!_shutoffBool && _interruptTimer != 0) {
      if (millis() - _interruptTimer > 2000) {
        _idleMode = true;
        _lightMode = 0;
        _stopLight = false;
      } else {
        _idleMode = false;
        _stopLight =  !_stopLight;
        
      }
    } else {
      _stopLight = false;
      _idleMode = true;
    }
    _interruptTimer = 0;
    _shutoffBool = false;
    _shutoffTimer = millis();
    _lightTimer = millis();
    _flashTimer = millis();
}  
  if (_idleMode) {
    if (millis() - _flashTimer > _flashPhase) {
      flash();
    }
  } else {
    if (millis() - _lightTimer > _lightPhase) {
      light();
    }

  }
  if (millis() - _shutoffTimer > _shutoffTime) {
    _shutoffBool = true;
  }

  if (_shutoffBool) {
    shutoff();
  }
}
void Streetlights::lightOperation(void){
	  if (_idleMode) {
    if (millis() - _flashTimer > _flashPhase) {
      flash();
    }
  } else {
    if (millis() - _lightTimer > _lightPhase) {
      light();
    }

  }
}

bool Streetlights::checkShutoff(void){
	if (millis() - _shutoffTimer > _shutoffTime) {
    _shutoffBool = true;
  }
  return _shutoffBool;
}

void Streetlights::shutoffAfter(uint32_t shutoff = 15){
	 _shutoffTime = shutoff * 1000;
}

Phase Streetlights::getPhase(int num)
{
	switch (num){
		case 1 :
		
			return _Phase1;
			break;
		case 2 :if(_phaseMax>1){
		return _Phase2;}
			break;
					case 3 :if(_phaseMax>2){
					return _Phase3;}
			break;
					case 4 :if(_phaseMax>3){
					return _Phase4;}
			break;
			case 5 :if(_phaseMax>4){
			return _Phase5;}
			break;
	}
	return _Phase1;
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