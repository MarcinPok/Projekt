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
	virtual Device* create(ConnectedClient* client,DevicesFactory* factory, CentralSystem* system)=0;
	virtual void exec(string cmd)=0;
protected:
	ConnectedClient* client;
	pthread_t thread_id;
	DevicesFactory* factory;
	CentralSystem* system;
private:

};

