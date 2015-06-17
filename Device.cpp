#include "Device.h"

Device::Device()
{
	cout<<"Device()"<<endl;
	client = NULL;
}

Device::Device(ConnectedClient* client, DevicesFactory* factory, CentralSystem* system)
{

}


Device::~Device(void)
{
	cout<<"~Device()"<<endl;
}
