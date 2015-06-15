#pragma once
#include "common.h"
#include "Device.h"

class ConnectedClient;
class Device;

class Sensor : public Device
{
public:
	Sensor();
	Sensor(ConnectedClient* client);
	virtual ~Sensor();
	virtual Sensor* create(ConnectedClient* client)
	{
		return new Sensor();
	}
private:
	string type;
	int measure;
}; 
