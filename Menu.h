#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "Text.h"

using ElemType = Text;
using namespace std;

class Menu
{
private:
    ElemType *option_list;
    int capacity;
    int count;
    ElemType top_message;
    ElemType bottom_message;

public:
    Menu();
    virtual ~Menu();
    void toStream(ostream &sout) const;
    int getCapacity() const;
    int size() const;
    int read_option_number();
    void push_back(const ElemType &e);
    void double_capacity();
};

ostream &operator<<(std::ostream &sout, const Menu &menu);

#endif
