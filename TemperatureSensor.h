#pragma once
#include "sensor.h"

class TemperatureSensor : public Sensor
{
public:
	TemperatureSensor();
	//TemperatureSensor(ConnectedClient* client);
	virtual ~TemperatureSensor();
	string GetMeasure();
	TemperatureSensor* create()
	{
		return new TemperatureSensor();
	}
private:
	long long measure;
	int ID;

};

