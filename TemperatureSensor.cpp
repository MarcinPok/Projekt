#include "TemperatureSensor.h"


TemperatureSensor::TemperatureSensor()
{
	//this->ID = ID;
	cout << "utworzyl sie temperaturowy skurwiel o chujowym identyfikatorze:" << endl;
}


TemperatureSensor::~TemperatureSensor()
{
	cout << "Termometr sie spierdolil" << endl;
	//cout << "Termometr sie spierdolil" << endl;
}

string TemperatureSensor::GetMeasure()
{
	srand(time(NULL));
	this -> measure = rand() % 100;
	return "Temperatura" + std::to_string(measure);
	//cout << "ID: " << ID << "Temperatura: " << measure << endl;
	//return to_string(measure);
	//return "lol";
}
