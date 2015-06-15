#pragma once
#include "Sensor.h"

class ConnectedClient;
class Sensor;

class TemperatureSensor : public Sensor
{
public:
	TemperatureSensor();
	TemperatureSensor(ConnectedClient* client, DevicesFactory* factory);
	virtual ~TemperatureSensor();
	TemperatureSensor* create(ConnectedClient* client, DevicesFactory* factory);

private:
	static void* run(void *);
	long long measure;
	int ID;
	pthread_t thread_id;
	DevicesFactory* factory;

};

