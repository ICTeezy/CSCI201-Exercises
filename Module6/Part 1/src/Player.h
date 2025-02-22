#ifndef PLAYER_H
#define PLAYERH

#include <string>

class Player
{

    public:

    Player(std::string name, int playerID);
    virtual ~Player();

    std::string getName();
    int getPlayerID();

    virtual std::string getPlayerPosition();
    virtual void play();
    virtual std::string toString();

    private:

    std::string m_name;
    int         m_playerID;
    
};


#endif