#include "CentralSystem.h"

CentralSystem::CentralSystem(void)
{
	factory = new DevicesFactory(this);
}

CentralSystem::~CentralSystem(void)
{
	delete this->factory;
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
	string type;
	while(1){
		client->putline("Identify yourself\r\n");
		type = client->getline();
		map <string, Device*>::iterator it;
		it=factory->devicesMap.find(type);
		if (it != factory->devicesMap.end()) 
			break;	
	}
	factory->create(type, client);
}

void CentralSystem::notify(string msg, Device* device)
{
	map <Device*, string>::iterator it;
	it=factory->devicesList.find(device);
	if( it->second == " 'TempSensor")
		this->update(msg);
	
		
	
}

void CentralSystem::update(string msg)
{
	map <Device*, string>::iterator it;
	for(it = factory->devicesList.begin(); it != factory->devicesList.end(); ++it)
			if( it->second == " 'TxtDisplay") (*it).first->exec(msg);
}
