#include <iostream>
#include "Menu.h"
#include <cstring>

using namespace std;

Menu::Menu()
{
    this->capacity = 1;
    this->count = 0;
    this->option_list = new ElemType[this->capacity];
}

Menu::~ Menu()
{ 
    delete[] option_list;
}

int Menu::getCapacity() const
{
    return this->capacity;
}

int Menu::size() const 
{
    return count;
}

void Menu::toStream(ostream& sout) const
{
    sout << "??";
}

ostream& operator<<(ostream& sout, const Menu& menu)
{
    menu.toStream(sout);
    return sout;
}
