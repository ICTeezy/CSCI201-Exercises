#include <iostream>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <map>

#include <string>
#include <sstream>
#include <cstring>
#include <fstream>

#define PORT 25565

std::map<std::string, std::string> fetchStateLookupMap()
{
    std::map<std::string, std::string> lookupMap;

    lookupMap["AL"] = "Alabama";
    lookupMap["AK"] = "Alaska";
    lookupMap["AZ"] = "Arizona";
    lookupMap["AR"] = "Arkansas";
    lookupMap["CA"] = "California";
    lookupMap["CO"] = "Colorado";
    lookupMap["CT"] = "Connecticut";
    lookupMap["DE"] = "Deleware";
    lookupMap["DC"] = "District of Columbia";
    lookupMap["FL"] = "Florida";
    lookupMap["GA"] = "Georgia";
    lookupMap["HI"] = "Hawaii";
    lookupMap["ID"] = "Idaho";
    lookupMap["IL"] = "Illinois";
    lookupMap["IN"] = "Indiana";
    lookupMap["KS"] = "Kansas";
    lookupMap["KY"] = "Kentucky";
    lookupMap["LA"] = "Louisiana";
    lookupMap["ME"] = "Maine";
    lookupMap["MD"] = "Maryland";
    lookupMap["MA"] = "Massachusetts";
    lookupMap["MI"] = "Michigan";
    lookupMap["MN"] = "Minnesota";
    lookupMap["MS"] = "Mississippi";
    lookupMap["MO"] = "Missouri";
    lookupMap["MT"] = "Montana";
    lookupMap["NE"] = "Nebraska";
    lookupMap["NV"] = "Nevada";
    lookupMap["NH"] = "New Hampshire";
    lookupMap["NJ"] = "New Jersey";
    lookupMap["NM"] = "New Mexico";
    lookupMap["NY"] = "New York";
    lookupMap["NC"] = "North Carolina";
    lookupMap["OH"] = "Ohio";
    lookupMap["OK"] = "Oklahoma";
    lookupMap["OR"] = "Oregon";
    lookupMap["PA"] = "Pennsylvania";
    lookupMap["RI"] = "Rhode Island";
    lookupMap["SC"] = "South Carolina";
    lookupMap["SD"] = "South Dakota";
    lookupMap["TN"] = "Tennessee";
    lookupMap["TX"] = "Texas";
    lookupMap["UT"] = "Utah";
    lookupMap["VT"] = "Vermont";
    lookupMap["VA"] = "Virginia";
    lookupMap["WA"] = "Washington";
    lookupMap["WV"] = "West Virginia";
    lookupMap["WI"] = "Wisconsin";
    lookupMap["WY"] = "Wyoming";

    return lookupMap;
}

int main()
{

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket == -1)
    {
        std::cout << "Failed to create socket.\n";
        return -1;
    }

    //Bind the server socket
    sockaddr_in address;
    inet_pton(AF_INET, "127.0.0.1", &address.sin_addr.s_addr);
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);

    int bindResult = bind(serverSocket, (sockaddr*) &address, sizeof(sockaddr));

    if (bindResult == -1)
    {
        std::cout << "Failed to bind on port " << PORT << '\n';
        return -1;
    }

    std::cout << "Server bound to port " << PORT << '\n';

    //Set the socket to listen
    int listenResult = listen(serverSocket, 3);

    if (listenResult == -1)
    {
        std::cout << "Failed to start listening on port " << PORT << '\n';
        return -1;
    }

    std::cout << "Server listening on port " << PORT << '\n';

    //std::ifstream stateLookupFile("../resources/state_translations.tsv");
    //auto lookupMap = fetchStateLookupMap(stateLookupFile);

    std::cout << "Waiting for connection...\n";

    //Accept connection
    int clientSocket = accept(serverSocket, nullptr, nullptr);

    if (clientSocket == -1)
    {
        std::cout << "Failed to accept connection\n";
        return -1;
    }

    std::cout << "Accepted connection.\n";

    auto lookupMap = fetchStateLookupMap();

    do
    {
        char abbreviation[3] = {};
        int bytesReceived = recv(clientSocket, abbreviation, sizeof(abbreviation), 0);

        if (bytesReceived == -1)
        {
            std::cout << "Connection closed.\n";
            break;
        }

        if (bytesReceived < 2)
        {
            char message[] = "Error: Didn't receieve enough bytes.\n";
            send(clientSocket, message, strlen(message), 0);
            continue;
        }

        if (abbreviation == "-1")
        {
            std::cout << "Received shutdown command.\n";
            break;
        }

        std::cout << "Fetching lookup for: `" << abbreviation << "`\n";
        if (lookupMap.count(abbreviation) == 0)
        { 
            char message[] = "Error: Invalid abbreviation.\n";
            send(clientSocket, message, strlen(message), 0);
        }
        else
        {
            std::cout << "Sending translation for: `" << abbreviation << "`.\n";

            std::string stateName = lookupMap[abbreviation];
            std::string fullMessage = stateName + "\n";

            send(clientSocket, fullMessage.c_str(), strlen(fullMessage.c_str()), 0);
        }
    } while (true);

    close(clientSocket);
    close(serverSocket);
}