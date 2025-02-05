#include <iostream>
#include <fstream>
#include <unordered_map>

using std::cout;

struct StateInfo
{
    std::string name;
    std::string governor;
    std::string flower;
};

std::unordered_map<std::string, StateInfo> readStateData(std::ifstream& file) 
{
    std::unordered_map<std::string, StateInfo> stateMap;

    std::string abbreviation;
    while (file >> abbreviation)
    {
        std::string name, governor, flower;
        file >> name >> governor >> flower;

        stateMap[abbreviation] = { name, governor, flower };
    }
    
    return stateMap;
}

int main()
{
    std::ifstream file("states.txt");

    if (!file)
    {
        std::cout << "Unable to open file!\n";
        return 1;
    }

    auto stateMap = readStateData(file);

    while (true)
    {

        cout << "Type a state abbreviation to display its information! (-1 to exit)\n";
        std::string abbreviation;
        std::cin >> abbreviation;

        if (abbreviation == "-1")
        {
            cout << "Goodbye!\n";
            return 1;
        }

        if (stateMap.find(abbreviation) == stateMap.end())
        {
            cout << "Unable to find state... try again\n";
            continue;
        }

        StateInfo& info = stateMap[abbreviation];

        cout << "Long Name: " << info.name << '\n';
        cout << "Governor: " << info.governor << '\n';
        cout << "Flower: " << info.flower << '\n';
    }
}

