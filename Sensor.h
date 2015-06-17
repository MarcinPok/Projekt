#pragma once
#include "common.h"
#include "Device.h"

class ConnectedClient;
class Device;
class DevicesFactory;

class Sensor : public Device
{
public:
	Sensor();
	virtual ~Sensor();
	void exec(string cmd){};
}; 
