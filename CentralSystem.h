#pragma once
#include "DevicesFactory.h"
#include "common.h"
#include "ConnectedClient.h"
class ConnectedClient;
class DevicesFactory;
class CentralSystem
{
public:
	DevicesFactory * factory;
	CentralSystem(void);
	virtual ~CentralSystem(void);
	void start();
	static void* run(void *);
	bool is_running() {return _is_running;}
	void newClient(ConnectedClient* client);

	void identifyDevice(ConnectedClient* client); // nowe po³¹czenie wywo³uje metodê identyfikacyjn¹ czujnik
private:
	
	pthread_t thread_id;
	bool _is_running;
};

