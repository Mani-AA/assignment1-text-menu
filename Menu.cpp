#include <iostream>
#include "Menu.h"
#include <cstring>

using namespace std;

Menu::Menu()
{
    this->capacity = 1;
    this->count = 0;
    this->top_message = "";
    this->bottom_message = "";
    this->option_list = new ElemType[this->capacity];
}

Menu::~Menu()
{
    delete[] option_list;
}

int Menu::read_option_number()
{
    int choice;
    cin >> choice;
    return choice;
}

void Menu::double_capacity()
{
    int newCapicity = 2 * this->getCapacity();
    ElemType *new_option_list = new ElemType[newCapicity];

    for (int i = 0; i < this->getCapacity(); i++)
    {
        new_option_list[i] = this->option_list[i];
    }

    delete[] this->option_list;

    this->option_list = new_option_list;
    this->capacity = newCapicity;
}

void Menu::push_back(const ElemType &e)
{
    if (this->size() == this->getCapacity())
    {
        double_capacity();
    }
    this->option_list[count] = e;
    this->count++;
}

void Menu::insert(int index, const ElemType &e)
{
    if (this->size() == this->getCapacity())
    {
        double_capacity();
    }

    // shift elements forward 
    for (int i = this->count; i >= index; i--) 
    {
        this->option_list[i] = this->option_list[i - 1]; 
    }

    // insert element at position index
    this->option_list[index - 1] = e;
    this->count++;
}

int Menu::getCapacity() const
{
    return this->capacity;
}

int Menu::size() const
{
    return count;
}

void Menu::toStream(ostream &sout) const
{
    sout << endl;
    sout << top_message << endl;

    for (int k = 0; k < this->count; ++k)
    {
        sout << k + 1 << ": " << option_list[k] << endl;
    }

    sout << bottom_message << endl;

    sout << "??";
}

void Menu::set_top_message(const ElemType &m)
{
    this->top_message = m;
}
void Menu::set_bottom_message(const ElemType &m)
{
    this->bottom_message = m;
}

void Menu::pop_back()
{
    this->count--;
}

void Menu::error(std::string msg) const
{
    std::cerr << msg << "\n";
    exit(EXIT_FAILURE);
}

ostream &operator<<(ostream &sout, const Menu &menu)
{
    menu.toStream(sout);
    return sout;
}
