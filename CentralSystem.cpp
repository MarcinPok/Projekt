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
	//map <string, Device*>::iterator it;
	//for (it = factory->DevicesMap.begin(); it != factory->DevicesMap.end(); ++it )
   // if (it->second == device) 
		//string type=it->first;

	vector <Device*>::iterator it;
		for (it=factory->DevicesList.begin(); it != factory->DevicesList.end(); ++it)
			cout << ((TemperatureSensor*)(*it))->myType() << endl;

}

void CentralSystem::updateDevices(string msg, string type)
{

	if (type == " 'Termometr")
	{
		vector <Device*>::iterator it;
		for (it=factory->DevicesList.begin(); it != factory->DevicesList.end(); ++it)
			if ( (*it)->myType() == " 'Display") string a = ((TemperatureSensor*)(*it))->myType();

	}
				
	 
}
