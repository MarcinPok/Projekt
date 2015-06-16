#pragma once
#include "DevicesFactory.h"
#include "common.h"
#include "ConnectedClient.h"
#include "Device.h"
#include <vector>
#include "TemperatureSensor.h"

class ConnectedClient;
class DevicesFactory;
class Device;

class CentralSystem
{
public:
	DevicesFactory * factory;
	CentralSystem(void);
	virtual ~CentralSystem(void);
	void notify(string msg, Device* device);
	void start();
	static void* run(void *);
	bool is_running() {return _is_running;}
	void identifyDevice(ConnectedClient* client); // nowe po³¹czenie wywo³uje metodê identyfikacyjn¹ czujnik
private:
	void updateDevices(string msg, string type);
	pthread_t thread_id;
	bool _is_running;
};

