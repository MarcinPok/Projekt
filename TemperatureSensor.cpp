#include "TemperatureSensor.h"


TemperatureSensor::TemperatureSensor()
{
	//this->ID = ID;
	cout << "TemperatureSensor()" << endl;
}


TemperatureSensor::~TemperatureSensor()
{
	cout << "~TemperatureSensor()" << endl;
}

TemperatureSensor* TemperatureSensor::create(string type, ConnectedClient* client)
{
	return new TemperatureSensor();
}

/*
string TemperatureSensor::GetMeasure()
{
	srand(time(NULL));
	this -> measure = rand() % 100;
	return "Temperatura" + std::to_string(measure);
	//cout << "ID: " << ID << "Temperatura: " << measure << endl;
	//return to_string(measure);
	//return "lol";
}*/

