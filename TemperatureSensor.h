#pragma once
#include "Sensor.h"

class ConnectedClient;
class Sensor;

class TemperatureSensor : public Sensor
{
public:
	TemperatureSensor();
	virtual ~TemperatureSensor();
	string GetMeasure();
	//TemperatureSensor* create(string type, ConnectedClient* client);
	TemperatureSensor* create(string type, ConnectedClient* client)
	{
		return new TemperatureSensor();
	}
private:
	long long measure;
	int ID;

};

