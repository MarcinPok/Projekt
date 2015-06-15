#pragma once
#include "DevicesFactory.h"
#include "TemperatureSensor.h"



DevicesFactory::DevicesFactory(void)
{
	this->RegisterDevice(" 'Termometr", new TemperatureSensor());
	this->RegisterDevice(" 'Device", new Device());
	cout << "Factory()" << endl;
	
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

	cout << "~Factory"<< endl;
}

Device * DevicesFactory::create(string type, ConnectedClient* client)
{
	map <string, Device*>::iterator it;
	it = DevicesMap.find(type);
	if (it != DevicesMap.end())
	{
		Device* s = it->second->create(client,this);
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

void DevicesFactory::deleteDevice(Device* device)
{


	vector <Device*>::iterator it;
	for (it=DevicesList.begin(); it != DevicesList.end(); ++it)
	{
		if(*it==device)
		{
			DevicesList.erase(it);
			delete device;
			return;
		}
	}

}


