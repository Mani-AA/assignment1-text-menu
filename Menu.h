#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "Text.h"

using namespace std;

class Menu
{
private:
    Text* option_list;
public:
    Menu();
    void toStream(ostream& sout)const;
};

ostream& operator<<(std::ostream& sout, const Menu& menu);

#endif
