#include "client.hpp"
#include <stdio.h>
#include <stdlib.h>


using namespace std;

int main(int argc, char* argv[])
{
	Client cli = Client("server_socket");
	cli.send(argv[1]);
	//std::cout << "init Client socket OK" << std::endl;
}
