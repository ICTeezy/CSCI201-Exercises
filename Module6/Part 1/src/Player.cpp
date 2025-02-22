#include "Player.h"

Player::Player(std::string name, int playerID) 
    :m_name(name), m_playerID(playerID)
{
    
}

Player::~Player() 
{
    
}

std::string Player::getName() 
{
    return m_name;
}

int Player::getPlayerID() 
{
    return m_playerID;    
}

std::string Player::getPlayerPosition()
{
    return "";
}

void Player::play()
{

}

std::string Player::toString()
{
    return "Name: " + getName() + " Position: " + getPlayerPosition() + " Number: " + std::to_string(getPlayerID());
}