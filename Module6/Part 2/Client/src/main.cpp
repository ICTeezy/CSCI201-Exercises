#include <iostream>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#define PORT 25565

int main()
{

    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (clientSocket == -1)
    {
        std::cerr << "Failed to create socket.\n";
        return -1;
    }

    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &address.sin_addr.s_addr);

    int connectionResult = connect(clientSocket, (sockaddr*) &address, sizeof(sockaddr));

    if (connectionResult == -1)
    {
        std::cerr << "Unable to connect to localhost on port " << PORT << "\n";
        return -1;
    }

    std::cout << "Connected to server...\n";
    do 
    {
        std::cout << "Enter abbreviation to lookup (-1 to exit): ";
        std::string abbreviation;   
        std::cin >> abbreviation;

        if (abbreviation == "-1")
        {
            std::cout << "Closing connection...\n";
            break;
        }

        if (abbreviation.length() != 2)
        {
            std::cout << "State abbreviations must be 2 characters long! Try again.\n";
            continue;
        }

        send(clientSocket, abbreviation.c_str(), strlen(abbreviation.c_str()), 0);

        char serverMessage[256] = {};
        int bytesReceived = recv(clientSocket, serverMessage, sizeof(serverMessage), 0);

        if (bytesReceived <= 0)
        {
            std::cout << "Server force closed connection.\n";
            break;
        }

        std::cout << "Server: " << serverMessage << "\n";
    } while (true);

    close(clientSocket);
}