#include "duck.h"
#include <iostream>
using namespace std;

Goose::Goose() {}
void Goose::makeSound() const
{
    cout << "Goose" << endl;
}

Duck::Duck() {}
void Duck::makeSound() const
{
    cout << "Duck" << endl;
}
