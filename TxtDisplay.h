#pragma once
#include "display.h"

class ConnectedClient;
class Sensor;

class TxtDisplay :
	public Display
{
public:
	TxtDisplay(void);
	TxtDisplay(ConnectedClient* client, DevicesFactory* factory, CentralSystem* system);
	virtual ~TxtDisplay(void);
	TxtDisplay* create(ConnectedClient* client, DevicesFactory* factory, CentralSystem* system);
	virtual void exec(string cmd);

private:
	static void* run(void *);
	pthread_t thread_id;
	DevicesFactory* factory;
	CentralSystem* system;
};

