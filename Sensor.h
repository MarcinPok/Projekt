#pragma once
#include "common.h"
#include "Device.h"

class ConnectedClient;
class Device;
class DevicesFactory;

class Sensor : public Device
{
public:
	Sensor();
	Sensor(ConnectedClient* client,DevicesFactory* factory){};
	virtual ~Sensor();
	virtual Sensor* create(ConnectedClient* client,DevicesFactory* factory)
	{
		return new Sensor(client,factory);
	}
private:
	string type;
	int measure;
}; 
