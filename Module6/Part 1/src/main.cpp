#include <iostream>
#include <vector>

#include "Player.h"

using std::cout;

class QuarterBack : public Player
{

    public:

    QuarterBack(std::string name, int playerID)
        : Player(name, playerID)
    {

    }

    std::string getPlayerPosition() override
    {
        return "Quarterback";
    }

    void play() override
    {
        cout << "Throws the ball\n";
    }

};

class WideReceiver : public Player
{

    public:

    WideReceiver (std::string name, int playerID)
        : Player(name, playerID)
    {

    }

    std::string getPlayerPosition() override
    {
        return "Wide Receiver";
    }

    void play() override
    {
        cout << "Catches the bal\n";
    }

};

class TightEnd : public Player
{

    public:

    TightEnd(std::string name, int playerID)
        : Player(name, playerID)
    {

    }

    std::string getPlayerPosition() override
    {
        return "Tight End";
    }

    void play() override
    {
        cout << "Blocks and catches the ball\n";
    }

};

class RunningBack : public Player
{

    public:

    RunningBack(std::string name, int playerID)
        : Player(name, playerID)
    {

    }

    std::string getPlayerPosition() override
    {
        return "Running Back";
    }

    void play() override
    {
        cout << "Runs the ball\n";
    }

};

class OffensiveLineman : public Player
{

    public:

    OffensiveLineman(std::string name, int playerID)
        : Player(name, playerID)
    {

    }

    std::string getPlayerPosition() override
    {
        return "Offensive Lineman";
    }

    void play() override
    {
        cout << "Protects the running back and quarterback\n";
    }

};

class DefensiveLineman : public Player
{

    public:

    DefensiveLineman(std::string name, int playerID)
        : Player(name, playerID)
    {

    }

    std::string getPlayerPosition() override
    {
        return "Defensive Lineman";
    }

    void play() override
    {
        cout << "Pressures the quarterback\n";
    }

};

class Linebacker : public Player
{

    public:

    Linebacker(std::string name, int playerID)
        : Player(name, playerID)
    {

    }

    std::string getPlayerPosition() override
    {
        cout << "Defends against running plays\n";
    }

    void play() override
    {

    }

};

class DefensiveBack : public Player
{

    public:

    DefensiveBack(std::string name, int playerID)
        : Player(name, playerID)
    {

    }

    std::string getPlayerPosition() override
    {
        return "Defensive Back";
    }

    void play() override
    {
        cout << "Defends against passing plays\n";
    }

};

class Kicker : public Player
{

    public:

    Kicker(std::string name, int playerID)
        : Player(name, playerID)
    {

    }

    std::string getPlayerPosition() override
    {
        return "Kicker";
    }

    void play() override
    {
        cout << "Kicks field goals\n";
    }

};

class Holder : public Player
{

    public:

    Holder(std::string name, int playerID)
        : Player(name, playerID)
    {

    }

    std::string getPlayerPosition() override
    {
        return "Holder";
    }

    void play() override
    {
        cout << "Holds the ball for the kicker\n";
    }

};

class Punter : public Player
{

    public:

    Punter(std::string name, int playerID)
        : Player(name, playerID)
    {

    }

    std::string getPlayerPosition() override
    {
        return "Punter";
    }

    void play() override
    {
        cout << "Punts the ball\n";
    }

};

class Returner : public Player
{

    public:

    Returner(std::string name, int playerID)
        : Player(name, playerID)
    {

    }

    std::string getPlayerPosition() override
    {
        return "Returner";
    }

    void play() override
    {
        cout << "Returns kick-offs and punts\n";
    }

};

int main()
{
    std::vector<Player> team;

    do 
    {
        cout << "1. Add Player\n";
        cout << "2. View Team\n";
        cout << "3. Exit\n";
        cout << ">> ";

        int choice;
        std::cin >> choice;

        cout << '\n';

        if (choice == 1)
        {
            std::string playerName;
            cout << "What is the name of this player?\n";
            cout << ">> ";

            std::cin >> playerName;

            cout << '\n';

            cout << "What is the player's jersey number?\n";
            cout << ">> ";

            int jerseyNumber;
            std::cin >> jerseyNumber;

            cout << '\n';

            team.emplace_back(playerName, jerseyNumber);
        }
        else if (choice == 2)
        {
            for (Player& player : team )
            {
                cout << player.toString() << '\n';
            }
        }
        else if (choice == 3)
        {
            cout << "Goodbye!";
            break;
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
        }

    } while (true);
}