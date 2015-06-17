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
	Sensor(ConnectedClient* client,DevicesFactory* factory, CentralSystem* system){};
	virtual ~Sensor();
	virtual Sensor* create(ConnectedClient* client,DevicesFactory* factory, CentralSystem* system)=0;
	/*{
		return new Sensor(client,factory, system);
	}*/
private:
	string type;
	int measure;
}; 
