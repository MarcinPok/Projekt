#include "ConnectedClient.h"

ConnectedClient::ConnectedClient(TCPServer* server, int connected_socket, uint32_t ip, uint16_t port)
{
    this->server = server;
    this->connected_socket = connected_socket;
    this->ip = ip;
    this->port = port;
	this->start();
    pthread_create(&thread_id, NULL, run, (void*)this);
}



void ConnectedClient::putline(string str)
{
    send(connected_socket, str.c_str(), str.length(), 0);
}

ConnectedClient::~ConnectedClient()
{
    disconnect();
}

void ConnectedClient::disconnect()
{
    shutdown(connected_socket, SHUT_RDWR);
}

string ConnectedClient::getline(bool asterisks)
{
    string line;
    char c;
    size_t rxbytes;
    do {
        rxbytes = recv(connected_socket, &c, 1, 0);
        if(rxbytes == 1 && c>=32)
        {
            line += c;
            send(connected_socket, &c, 1, 0); //echo
        }
		if (rxbytes == -1) { this->stop(); throw exception("client disconnected"); }
    } while (rxbytes==1 && c!='\r');
    return line;
}



void* ConnectedClient::run(void* arg)
{
    ConnectedClient * client = (ConnectedClient*)arg;

    client->putline("Identify yourself");
	string type = client->getline(false);
	client->server->system->factory->create(type,client);



   // string c("");
    do 
	{
      Common::sleep(1); 
    } while(client->is_running());

    client->disconnect();
    client->server->removeClient(client);
    return NULL;
}
