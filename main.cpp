#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include "DevicesFactory.h"
#include "Server.h"

using namespace std;

int main ()
{
	TCPServer server;
    server.start(1666);
    while(server.is_running()) 
	{ 
		Common::sleep(1); 
	}
	return 0;
}












