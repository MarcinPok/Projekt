#pragma once
#include "common.h"
#include "ConnectedClient.h"
#include "DevicesFactory.h"
#include "CentralSystem.h"

class ConnectedClient;
class DevicesFactory;
class CentralSystem;

class TCPServer
{
public:
    TCPServer(CentralSystem* system);
    virtual ~TCPServer();
    virtual void start(uint16_t port);
    virtual void stop();
	virtual bool is_running();
	vector<ConnectedClient*> listClients();
	ConnectedClient* findClient(string client_name);
	//void send_msg_to_client(string remote);
	

protected:	
	friend class ConnectedClient;
    virtual void addClient(ConnectedClient * client);
    virtual void removeClient(ConnectedClient * client);    
	static void* run(void *); 

private:
    int my_socket;
	volatile bool _is_running;
    uint16_t port;
    pthread_t thread_id;
    vector<ConnectedClient*> clients;
	CentralSystem* system;
	
};

