#pragma once
#include "display.h"

class ConnectedClient;
class Sensor;

class TxtDisplay : public Display
{
public:
	TxtDisplay(void);
	TxtDisplay(ConnectedClient* client, DevicesFactory* factory, CentralSystem* system);
	virtual ~TxtDisplay(void);
	TxtDisplay* create(ConnectedClient* client, DevicesFactory* factory, CentralSystem* system);
private:
	static void* run(void *);
};

