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
    void double_capacity();
public:
    Menu();
    Menu(const Menu &mnu);  
    virtual ~Menu();
    void insert(int index, const ElemType &e);
    void push_back(const ElemType &e);
    void remove(int index);
    int size() const;
    int getCapacity() const;
    void pop_back();
    ElemType get(int k) const;
    ElemType toString() const;
    int read_option_number();
    void set_top_message(const ElemType &m);
    void set_bottom_message(const ElemType &m);
    void clear_top_message();
    void clear_bottom_message();
    ElemType get_top_message() const;
    ElemType get_bottom_message() const;
    bool isEmpty();
    void toStream(ostream &sout) const;
    
};

ostream &operator<<(std::ostream &sout, const Menu &menu);

#endif
