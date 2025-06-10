class Player
{
public:
    Player();
    int getXCoord() const;
    void setXCoord(int x);
    int getYCoord() const;
    void setYCoord(int y);
    int getCoinCount() const;
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void pickUpCoin();
    void pickUpPowerUp();
    int getPowerUpCount() const;
    void resetPowerUpCount();

private:
    int xCoord;
    int yCoord;
    int coinCount;
    int powerUpCount;
};
