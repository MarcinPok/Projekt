#pragma once
#include "DevicesFactory.h"
#include "TemperatureSensor.h"
#include "TxtDisplay.h"


DevicesFactory::DevicesFactory(CentralSystem* system)
{
	this->RegisterDevice(" 'Termometr", new TemperatureSensor);
	this->RegisterDevice(" 'TxtDisplay", new TxtDisplay);
	cout << "Factory()" << endl;
	this->system=system;
	
}


DevicesFactory::~DevicesFactory(void)
{
	
	map <string, Device*>::iterator it;
	for(it = devicesMap.begin(); it != devicesMap.end(); ++it)
	{
		delete (*it).second;
	}
	devicesMap.clear();

	map <Device*, string>::iterator it2;
	for(it2 = devicesList.begin(); it2 != devicesList.end(); ++it2)
	{
		delete (*it2).first;
	}
	devicesList.clear();

	cout << "~Factory"<< endl;
}

Device * DevicesFactory::create(string type, ConnectedClient* client)
{
	map <string, Device*>::iterator it;
	it = devicesMap.find(type);
	if (it != devicesMap.end())
	{
		Device* s = it->second->create(client,this, system);
		devicesList[s]= type;
		return s;
	}
	else
		return (Device*)NULL;
}

void DevicesFactory::RegisterDevice(string type, Device* device)
{
	devicesMap[type]=device;
}

void DevicesFactory::deleteDevice(Device* device)
{

	map <Device*, string>::iterator it;
	it = devicesList.find(device);

	if (it != devicesList.end())
		devicesList.erase(device);
	delete device;

}

