#include <iostream>
using namespace std;

class Player
{
public:
    virtual void makeSound() const = 0;
    virtual ~Player() {}
};

class Goose : public Player
{
public:
    void makeSound() const;
    Goose();
};

class Duck : public Player
{
public:
    void makeSound() const;
    Duck();
};