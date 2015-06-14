#pragma once
#include "common.h"
#include "Device.h"

class ConnectedClient;
class Device;

class Sensor : public Device
{
public:
	Sensor();
	virtual ~Sensor();
    //virtual string GetMeasure();
	Sensor* create(string type, ConnectedClient* client)
	{
		return new Sensor();
	}
private:
	string type;
	int measure;
}; 
