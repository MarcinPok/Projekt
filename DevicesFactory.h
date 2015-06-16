#pragma once
#include "common.h"

#include <map>
#include "Server.h"
#include "CentralSystem.h"
#include "TemperatureSensor.h"



class ConnectedClient;
class Device;

using namespace std;

class DevicesFactory
{
public:
	friend class CentralSystem;
	DevicesFactory(CentralSystem* system);
	~DevicesFactory();
	void RegisterDevice(string type, Device* device);
	Device* create(string type, ConnectedClient* client);
	void deleteDevice(Device* device);

protected:
	map <string, Device*> DevicesMap;
	vector <Device*> DevicesList;
	CentralSystem* system;

};