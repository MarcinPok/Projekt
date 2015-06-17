#pragma once
#include "common.h"
#include "Device.h"
#include <map>
#include "Server.h"
//#include "CentralSystem.h"

class ConnectedClient;
class Device;

using namespace std;

class DevicesFactory
{
public:
	friend class CentralSystem;
	DevicesFactory(CentralSystem* system);
	DevicesFactory();
	~DevicesFactory();
	void RegisterDevice(string type, Device* device);
	Device* create(string type, ConnectedClient* client);
	void deleteDevice(Device* device);

protected:
	map <string, Device*> devicesMap;
	map <Device*, string> devicesList;
	CentralSystem* system;

};