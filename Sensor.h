#pragma once

#include "Device.h"

class ConnectedClient;
class Device;
class DevicesFactory;

class Sensor : public Device
{
public:
	Sensor();
	Sensor(ConnectedClient* client,DevicesFactory* factory, CentralSystem* system){};
	virtual ~Sensor();
	virtual Sensor* create(ConnectedClient* client,DevicesFactory* factory, CentralSystem* system)
	{
		return new Sensor(client,factory, system);
	}
private:
	string type;
	int measure;
}; 
