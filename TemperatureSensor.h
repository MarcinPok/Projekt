#pragma once
#include "Sensor.h"

class ConnectedClient;
class Sensor;

class TemperatureSensor : public Sensor
{
public:
	TemperatureSensor();
	TemperatureSensor(ConnectedClient* client, DevicesFactory* factory, CentralSystem* system);
	virtual ~TemperatureSensor();
	TemperatureSensor* create(ConnectedClient* client, DevicesFactory* factory, CentralSystem* system);
	virtual void exec(string cmd){};
private:
	static void* run(void *);
	pthread_t thread_id;
	DevicesFactory* factory;
	CentralSystem* system;

};

