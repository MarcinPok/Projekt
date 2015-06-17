#pragma once
#include "DevicesFactory.h"
#include "common.h"
#include "ConnectedClient.h"
#include "Device.h"

class ConnectedClient;
class DevicesFactory;
class Device;
class TCPServer;

class CentralSystem
{
public:
	DevicesFactory * factory;
	CentralSystem(void);
	virtual ~CentralSystem(void);
	virtual void notify(string msg, Device* device);
	virtual void start();
	virtual bool is_running() {return _is_running;}
	virtual void identifyDevice(ConnectedClient* client); 
	TCPServer* server;
private:
	pthread_t thread_id;
	bool _is_running;
	static void* run(void *);
	void update(string msg);
};

