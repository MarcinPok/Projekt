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
private:
	static void* run(void *);
};

