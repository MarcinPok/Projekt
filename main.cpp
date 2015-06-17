#include "common.h"
#include "CentralSystem.h"

using namespace std;

int main ()
{
	CentralSystem system;
	system.start();
	while(system.is_running())
	{
		Common::sleep(1);
	}

	return 0;
}












