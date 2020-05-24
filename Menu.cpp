#include <iostream>
#include "Menu.h"
#include <cstring>

using namespace std;

Menu::Menu()
{

    this->option_list = nullptr;
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
