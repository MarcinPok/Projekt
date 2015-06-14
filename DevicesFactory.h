#pragma once
#include "common.h"
#include "TemperatureSensor.h"
#include <map>
//#include "Server.h"
#include "ConnectedClient.h"
#include "Device.h"


using namespace std;

class DevicesFactory
{
public:
	DevicesFactory();
	~DevicesFactory();
	void RegisterDevice(string type, Device* device);
	Device* create(string type,ConnectedClient* client);
protected:
	map <string, Device*> DevicesMap;
	vector <Device*> DevicesList;

};