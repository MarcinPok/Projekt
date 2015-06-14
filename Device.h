#pragma once
//#include "Server.h"
//#include "ConnectedClient.h"

class Device
{
public:
	Device();
	virtual ~Device(void);
	virtual Device* create()=0;
};

