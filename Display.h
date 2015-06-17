#pragma once
#include "device.h"

class Display : public Device
{
public:
	Display(void){cout<<"Display()"<<endl;};
	virtual ~Display(void){cout<<"~Display()"<<endl;};
	void exec(string cmd);
};

