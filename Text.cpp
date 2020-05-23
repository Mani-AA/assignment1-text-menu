#include <iostream>
#include "Text.h"
#include <cstring>

using namespace std;

Text::Text() : Text("")
{
}

Text::Text(const char *pCstr)
{
    this->pStore = new char[strlen(pCstr) + 1];
    strcpy(this->pStore, pCstr);
}

Text::Text(const Text &txt) : Text(txt.getCstring())
{
}

// destructor
Text::~Text()
{
    delete[] this->pStore; 
}

Text &Text::operator=(const Text &txt)
{
    if (this != &txt)
    {
        delete[] this->pStore;
        this->pStore = new char[strlen(txt.getCstring()) + 1];
        strcpy(this->pStore, txt.getCstring());
    }
    return *this;
}

const char *Text::getCstring() const
{
    return this->pStore;
}

ostream &operator<<(ostream &sout, const Text &txt)
{
    sout << txt.getCstring();
    return sout;
}
