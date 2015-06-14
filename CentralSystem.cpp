#include "CentralSystem.h"



CentralSystem::CentralSystem(void)
{
	factory = new DevicesFactory;

}


CentralSystem::~CentralSystem(void)
{
	delete factory;
}

void CentralSystem::start()
{
    pthread_create(&thread_id, NULL, run, (void*)this);
	_is_running = true;
}

void* CentralSystem::run(void *arg)
{
	TCPServer server((CentralSystem *)arg);
    server.start(1666);
	
	
    while(server.is_running()) 
	{ 
		Common::sleep(1); 
	}
	return NULL;
}

void CentralSystem::identifyDevice(ConnectedClient * client)
{
	client->putline("Identify yourself");
	string type = client->getline();
	factory->create(type, client);

}
