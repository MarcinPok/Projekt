#pragma once
#include "ConnectedClient.h"
#include "DevicesFactory.h"

class DevicesFactory;
class ConnectedClient;

class Device
{
public:
	Device();
	Device(ConnectedClient* client, DevicesFactory* factory);
	virtual ~Device(void);
	virtual Device* create(ConnectedClient* client,DevicesFactory* factory)
	{
		return new Device(client,factory);
	}
protected:
	ConnectedClient* client;
};

