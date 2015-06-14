#pragma once
//#include "Server.h"
#include "ConnectedClient.h"

class ConnectedClient;

class Device
{
public:
	Device();
	virtual ~Device(void);
		Device* create(string type, ConnectedClient* client)
	{
		return new Device();
	}
};

