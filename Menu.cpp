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

Menu::Menu(const Menu &mnu)
{
    this->capacity = mnu.getCapacity();
    this->count = mnu.size();
    this->top_message = mnu.get_top_message();
    this->bottom_message = mnu.get_bottom_message();

    this->option_list = new ElemType[this->capacity];
    for (int k = 0; k < this->count; k++)
    {
        this->option_list[k] = mnu.get(k);
    }
}

int Menu::read_option_number()
{
    int choice{0};
    while (true)
    {
        //Print the menu
        cout << *this;
        //Read user's input
        cin >> choice;
        if (this->isEmpty() || ((choice <= count) && (choice > 0)))
        {
            break;
        }
        else
        {
            cout << "Invalid choice " << choice << ". It must be in the range [1, " << count << "]" << endl;
        }
    }

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

void Menu::remove(int index)
{
    // shift elements backward
    for (int i = index; i < count; i++)
    {
        this->option_list[i - 1] = this->option_list[i];
    }

    this->count--;
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
    if (!top_message.isEmpty())
    {
        sout << top_message << endl;
    }

    for (int k = 0; k < this->count; ++k)
    {
        sout << "  " << k + 1 << ": " << option_list[k] << endl;
    }

    if (!bottom_message.isEmpty())
    {
        sout << bottom_message << endl;
    }

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

ElemType Menu::get_top_message() const
{
    return this->top_message;
}

ElemType Menu::get_bottom_message() const
{
    return this->bottom_message;
}

void Menu::clear_top_message()
{
    this->top_message = "";
}

void Menu::clear_bottom_message()
{
    this->bottom_message = "";
}

void Menu::pop_back()
{
    this->count--;
}

bool Menu::isEmpty()
{
    return this->size() == 0;
}

ElemType Menu::get(int k) const
{
    return this->option_list[k];
}

ostream &operator<<(ostream &sout, const Menu &menu)
{
    menu.toStream(sout);
    return sout;
}
