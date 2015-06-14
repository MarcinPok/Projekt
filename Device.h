#pragma once
//#include "Server.h"
#include "ConnectedClient.h"

class ConnectedClient;

class Device
{
public:
	Device();
	Device(ConnectedClient* client);
	virtual ~Device(void);
	virtual Device* create(string type, ConnectedClient* client)
	{
		return new Device(client);
	}
private:
	ConnectedClient* client;
};

