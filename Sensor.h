#pragma once
#include "common.h"
#include "Device.h"

class Sensor : public Device
{
public:
	Sensor();
	virtual ~Sensor();
    //virtual string GetMeasure();
	Sensor* create()=0;
private:
	string type;
	int measure;
}; 
