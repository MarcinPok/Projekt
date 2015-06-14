#pragma once
#include "common.h"
#include "Device.h"
#include <map>
#include "Server.h"

class ConnectedClient;
class Device;

using namespace std;

class DevicesFactory
{
public:
	DevicesFactory();
	~DevicesFactory();
	void RegisterDevice(string type, Device* device);
	Device* create(string type, ConnectedClient* client);
protected:
	map <string, Device*> DevicesMap;
	vector <Device*> DevicesList;

};