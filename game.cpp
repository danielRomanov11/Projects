#include "game.h"
Player::Player()
{
    xCoord = 1;
    yCoord = 1;
    coinCount = 0;
    powerUpCount = 0;
}
// change coord by exponents of 2
void Player::moveUp()
{
    yCoord += (1 << getPowerUpCount());
}
void Player::moveDown()
{
    yCoord -= (1 << getPowerUpCount());
}
void Player::moveLeft()
{
    xCoord -= (1 << getPowerUpCount());
}
void Player::moveRight()
{
    xCoord += (1 << getPowerUpCount());
}
int Player::getXCoord() const
{
    return xCoord;
}
int Player::getYCoord() const
{
    return yCoord;
}
void Player::pickUpCoin()
{
    coinCount++;
}
int Player::getCoinCount() const
{
    return coinCount;
}
// power up pickup
void Player::pickUpPowerUp()
{
    powerUpCount++;
}
// powerup getter
int Player::getPowerUpCount() const
{
    return powerUpCount;
}
void Player::setXCoord(int x)
{
    xCoord = x;
}

void Player::setYCoord(int y)
{
    yCoord = y;
}
// reset powerup count easter egg function
void Player::resetPowerUpCount()
{
    powerUpCount = 0;
}