#pragma once
#include "ConnectedClient.h"
#include "DevicesFactory.h"
#include "CentralSystem.h"

class DevicesFactory;
class ConnectedClient;

class Device
{
public:
	Device();
	Device(ConnectedClient* client, DevicesFactory* factory, CentralSystem* system);
	virtual ~Device(void);
	virtual Device* create(ConnectedClient* client,DevicesFactory* factory, CentralSystem* system)
	{
		return new Device(client,factory, system);
	}
	virtual string myType(){return " 'Device";};
protected:
	ConnectedClient* client;

};

