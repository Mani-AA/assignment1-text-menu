#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "Text.h"

using ElemType = Text;
using namespace std;

class Menu
{
private:
    Text* option_list;
    int capacity;
    int count;
    Text top_message;
    Text bottom_message;
public:
    Menu();
    virtual ~Menu();
    void toStream(ostream& sout)const;
    int getCapacity() const;
    int size() const;
};

ostream& operator<<(std::ostream& sout, const Menu& menu);

#endif
