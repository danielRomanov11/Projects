
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "duck.h"
using namespace std;

int main()
{
    int numPlayers;
    cout << "Enter number of players: ";
    cin >> numPlayers;

    srand(time(0));
    int gooseIndex = rand() % numPlayers;

    Player **players = new Player *[numPlayers];
    for (int i = 0; i < numPlayers; i++)
    {
        if (i == gooseIndex)
            players[i] = new Goose();
        else
            players[i] = new Duck();
    }

    cout << "Goose is indexed at " << gooseIndex << endl;

    for (int i = 0; i < numPlayers; i++)
    {
        (*players[i]).makeSound();

        if (i == gooseIndex)
        {
            break;
        }
    }

    for (int i = 0; i < numPlayers; i++)
        delete players[i];
    delete[] players;

    return 0;
}
