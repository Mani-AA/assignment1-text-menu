#include <iostream>
#include "Text.h"
#include <cstring>

using namespace std;

Text::Text() : Text("")
{
}

Text::Text(const char *pCstr)
{
    this->assign(pCstr);
}

Text::Text(const Text &txt) : Text(txt.getCstring())
{
}

Text::~Text()
{
    delete[](this->pStore); 
}

void Text::assign(const char *pCstr)
{
    if (this->pStore != nullptr) {
        delete[](this->pStore); 
    }
    this->pStore = new char[strlen(pCstr) + 1];
    strcpy(this->pStore, pCstr);
}

void Text::assign(const Text &txt)
{
    this->assign(txt.getCstring());
}

Text &Text::operator=(const Text &txt)
{
    if (this != &txt)
    {
        this->assign(txt);
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
