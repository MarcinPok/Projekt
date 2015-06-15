#include "Device.h"

Device::Device()
{
	cout<<"Device()"<<endl;
}

Device::Device(ConnectedClient* client, DevicesFactory* factory)
{
	this->client = client;
	cout<<"Device(client)"<<endl;

}


Device::~Device(void)
{
	cout<<"~Device()"<<endl;
}
