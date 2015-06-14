#pragma once
#include "Sensor.h"

class ConnectedClient;
class Sensor;

class TemperatureSensor : public Sensor
{
public:
	TemperatureSensor();
	virtual ~TemperatureSensor();
	TemperatureSensor* create(string type, ConnectedClient* client);

private:
	long long measure;
	int ID;

};

