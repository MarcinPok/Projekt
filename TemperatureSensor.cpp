#include "TemperatureSensor.h"


TemperatureSensor::TemperatureSensor()
{
	cout << "TemperatureSensor()" << endl;
}

TemperatureSensor::TemperatureSensor(ConnectedClient* client)
{
	cout << "TemperatureSensor(client)" << endl;
	this->client = client;
	pthread_create(&thread_id, NULL, run, (void*)this);
}

void* TemperatureSensor::run(void* arg)
{
	TemperatureSensor* sensor = (TemperatureSensor*)arg;
	do
	{
		cout << sensor->client->getline() << endl;
	}while(sensor->client->is_running());
	cout<<"coœ"<<endl; // tutaj usuñ czujnik
	return NULL;
}

TemperatureSensor::~TemperatureSensor()
{
	cout << "~TemperatureSensor()" << endl;
}

TemperatureSensor* TemperatureSensor::create(ConnectedClient* client)
{
	return new TemperatureSensor(client);
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

