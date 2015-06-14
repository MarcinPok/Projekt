#include "Device.h"

Device::Device()
{
}

Device::Device(ConnectedClient* client)
{
	this->client = client;
	cout<<"Device()"<<endl;

}


Device::~Device(void)
{
	cout<<"~Device()"<<endl;
}
