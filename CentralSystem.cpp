#include "CentralSystem.h"




CentralSystem::CentralSystem(void)
{
	factory = new DevicesFactory(this);

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
	client->putline("Identify yourself\r\n");
	string type = client->getline();
	factory->create(type, client);

}


void CentralSystem::notify(string msg, Device* device)
{
	map <Device*, string>::iterator it;
	string type;
	it=factory->devicesList.find(device);
	if( it->second == " 'Termometr")
	{
		for(it = factory->devicesList.begin(); it != factory->devicesList.end(); ++it)
		{
			if( it->second == " 'TxtDisplay") (*it).first->exec(msg);
		}
	}


	//cout << msg <<endl;
}
