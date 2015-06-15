#include "TemperatureSensor.h"


TemperatureSensor::TemperatureSensor()
{
	cout << "TemperatureSensor()" << endl;
}

TemperatureSensor::TemperatureSensor(ConnectedClient* client, DevicesFactory* factory)
{
	cout << "TemperatureSensor(client)" << endl;
	this->factory = factory;
	this->client = client;
	pthread_create(&thread_id, NULL, run, (void*)this);
}

TemperatureSensor::~TemperatureSensor()
{
	cout << "~TemperatureSensor()" << endl;
	this->client->disconnect();
}

void* TemperatureSensor::run(void* arg)
{
	TemperatureSensor* thisSensor = (TemperatureSensor*)arg;
	do
	{
		cout << thisSensor->client->getline() << endl;
	}while(thisSensor->client->is_running());
	thisSensor->factory->deleteDevice(thisSensor);
	return NULL;
}



TemperatureSensor* TemperatureSensor::create(ConnectedClient* client, DevicesFactory* factory)
{
	return new TemperatureSensor(client,factory);
}

/*
string TemperatureSensor::GetMeasurement()
{
	srand(time(NULL));
	this -> measure = rand() % 100;
	return "Temperatura" + std::to_string(measure);
	//cout << "ID: " << ID << "Temperatura: " << measure << endl;
	//return to_string(measure);
	//return "lol";
}*/

