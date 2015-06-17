#include "TxtDisplay.h"


TxtDisplay::TxtDisplay(void)
{
	cout << "TxtDisplay()" << endl;
}

TxtDisplay::TxtDisplay(ConnectedClient* client, DevicesFactory* factory, CentralSystem* system)
{
	this->system = system;
	cout << "TxtDisplay(client)" << endl;
	this->factory = factory;
	this->client = client;
	pthread_create(&thread_id, NULL, run, (void*)this);
}

TxtDisplay::~TxtDisplay(void)
{
	cout << "~TxtDisplay()" << endl;
	this->client->disconnect();
}

void* TxtDisplay::run(void* arg)
{
	TxtDisplay* thisDisplay = (TxtDisplay*)arg;
	while(thisDisplay->client->is_running())
	{
		string data_in = thisDisplay->client->getline(); //checking still running flag
	}
	thisDisplay->factory->deleteDevice(thisDisplay);
	return NULL;
}

TxtDisplay* TxtDisplay::create(ConnectedClient* client, DevicesFactory* factory, CentralSystem* system )
{
	return new TxtDisplay(client,factory,system);
}

void TxtDisplay::exec(string cmd)
{
	client->putline(cmd);
}
