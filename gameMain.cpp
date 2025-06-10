#include "game.h"
#include <iostream>
#include <ctime>
using namespace std;
int main()
{

    Player player1;
    srand(time(0));
    // sets random coordinates for coin and powerups
    int x_coin = rand() % 9 + 1, y_coin = rand() % 9 + 1;
    // two unique powerups
    int x_powerUp = rand() % 9 + 1, y_powerUp = rand() % 9 + 1;
    int x_powerUp2 = rand() % 9 + 1, y_powerUp2 = rand() % 9 + 1;
    bool powerUp1Active = true, powerUp2Active = true;
    int oldX, oldY;
    cout << "Welcome to the Coin Game!" << endl         // welcome message
         << "Collect 10 coins to win the game." << endl // instructions
         << "Collecting a powerup doubles your movement distance." << endl
         << "You are at (1, 1), the maximum coordinate is (10, 10)." << endl; // initial coordinates and instructions
    // do while loop to keep game going until 10 coins are collected
    do
    {
        int minBound = 1, maxBound = 10;
        cout << "You are at (" << player1.getXCoord() << ", " << player1.getYCoord() << "); Coins : " << player1.getCoinCount() << endl;
        cout << "There is a coin at (" << x_coin << ", " << y_coin << ")" << endl;

        // Only show active power-ups
        if (powerUp1Active || powerUp2Active)
        {
            cout << "Power-ups at: ";
            if (powerUp1Active)
                cout << "(" << x_powerUp << ", " << y_powerUp << ") ";
            if (powerUp1Active && powerUp2Active)
                cout << "and ";
            if (powerUp2Active)
                cout << "(" << x_powerUp2 << ", " << y_powerUp2 << ")";
            cout << endl;
        }

        cout << "Choose a move:" << endl;
        cout << "W. Move Up" << endl;
        cout << "A. Move Left" << endl;
        cout << "S. Move Down" << endl;
        cout << "D. Move Right" << endl;

        char choice;
        cin >> choice;
        // get player coordinates before movement
        oldX = player1.getXCoord();
        oldY = player1.getYCoord();
        // switch statement to move player, with lower and upper bound checking
        switch (choice)
        {
        case 'A':
        case 'a':
            player1.moveLeft();
            if (player1.getXCoord() < minBound)
                player1.setXCoord(minBound);
            break;
        case 'W':
        case 'w':
            player1.moveUp();
            if (player1.getYCoord() > maxBound)
                player1.setYCoord(maxBound);
            break;
        case 'S':
        case 's':
            player1.moveDown();
            if (player1.getYCoord() < minBound)
                player1.setYCoord(minBound);
            break;
        case 'D':
        case 'd':
            player1.moveRight();
            if (player1.getXCoord() > maxBound)
                player1.setXCoord(maxBound);
            break;
        // reset powerup count, no break statement on purpose for it to be inconspicuous
        case 'R':
            player1.resetPowerUpCount();
        default:
            cout << "Sorry, I don't understand" << endl;
        } // check coin collection along the path using old coordinate and new coordinate range comparison
        if (((oldX <= x_coin && x_coin <= player1.getXCoord()) || (player1.getXCoord() <= x_coin && x_coin <= oldX)) &&
            ((oldY <= y_coin && y_coin <= player1.getYCoord()) || (player1.getYCoord() <= y_coin && y_coin <= oldY)))
        {
            player1.pickUpCoin();
            x_coin = rand() % 9 + 1;
            y_coin = rand() % 9 + 1;
        }

        // Check first power-up collection along the path
        if (powerUp1Active &&
            ((oldX <= x_powerUp && x_powerUp <= player1.getXCoord()) || (player1.getXCoord() <= x_powerUp && x_powerUp <= oldX)) &&
            ((oldY <= y_powerUp && y_powerUp <= player1.getYCoord()) || (player1.getYCoord() <= y_powerUp && y_powerUp <= oldY)))
        {
            player1.pickUpPowerUp();
            powerUp1Active = false; // Remove from board
        } // Check second power-up collection along the path
        if (powerUp2Active &&
            ((oldX <= x_powerUp2 && x_powerUp2 <= player1.getXCoord()) || (player1.getXCoord() <= x_powerUp2 && x_powerUp2 <= oldX)) &&
            ((oldY <= y_powerUp2 && y_powerUp2 <= player1.getYCoord()) || (player1.getYCoord() <= y_powerUp2 && y_powerUp2 <= oldY)))
        {
            player1.pickUpPowerUp();
            powerUp2Active = false; // Remove from board
        }
    } while (player1.getCoinCount() < 10);

    cout << "You win!" << endl;
    return 0;
}
