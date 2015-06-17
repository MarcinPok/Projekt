#pragma once
#include "common.h"
#include "Device.h"
#include <map>
#include "Server.h"

class ConnectedClient;
class Device;

class DevicesFactory
{
public:
	friend class CentralSystem;
	DevicesFactory(CentralSystem* system);
	DevicesFactory();
	~DevicesFactory();
	virtual void RegisterDevice(string type, Device* device);
	virtual void deleteDevice(Device* device);

private:
	virtual Device* create(string type, ConnectedClient* client);
	map <string, Device*> devicesMap;
	map <Device*, string> devicesList;
	CentralSystem* system;

};