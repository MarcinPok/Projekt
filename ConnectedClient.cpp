#include "ConnectedClient.h"

ConnectedClient::ConnectedClient(TCPServer* server, int connected_socket, uint32_t ip, uint16_t port)
{
    this->server = server;
    this->connected_socket = connected_socket;
    this->ip = ip;
    this->port = port;
	this->start();
}



void ConnectedClient::putline(string str)
{
    send(connected_socket, str.c_str(), str.length(), 0);
}

ConnectedClient::~ConnectedClient()
{
	cout<<"~Client"<<endl;
    disconnect();
}

void ConnectedClient::disconnect()
{
    shutdown(connected_socket, SHUT_RDWR);
}

string ConnectedClient::getline(bool asterisks)
{
    string line("");
    char c;
    size_t rxbytes;
    do {
        rxbytes = recv(connected_socket, &c, 1, 0);
        if(rxbytes == 1 && c>=32)
        {
            line += c;
        }
		if (rxbytes == 0) { this->stop();}
    } while (rxbytes==1 && c!='\r');
    return line;
}
