#pragma once
#include "DevicesFactory.h"



DevicesFactory::DevicesFactory(void)
{
	this->RegisterDevice("Termometr", new TemperatureSensor());
	//this->RegisterDevice("Device", new Device());
	cout << "utworzono skurwiala fabryke" << endl;
}


DevicesFactory::~DevicesFactory(void)
{
	
	map <string, Device*>::iterator it;
	for(it = DevicesMap.begin(); it != DevicesMap.end(); ++it)
	{
		delete (*it).second;
	}
	DevicesMap.clear();

	vector <Device*> :: iterator it2;
	for(it2 = DevicesList.begin(); it2 != DevicesList.end(); ++it2)
	{
		delete *it2;
	}
	DevicesList.clear();

	cout << "Fabryka zbankrutowala" << endl;
}

Device * DevicesFactory::create(string type, ConnectedClient* client)
{
	map <string, Device*>::iterator it;
	it = DevicesMap.find(type);
	if (it != DevicesMap.end())
	{
		Device* s = it->second->create();
		DevicesList.push_back(s);
		return s;
	}
	else
		return (Device*)NULL;
}

void DevicesFactory::RegisterDevice(string type, Device* device)
{
	DevicesMap[type]=device;
}


