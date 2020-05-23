#include <iostream>
#include "Text.h"
#include <cstring>

using namespace std;

Text::Text() : Text("")
{
}

Text::Text(const char *pCstr)
{
    this->pStore = (char *)pCstr;
}

Text::Text(const Text &txt) : Text(txt.getCstring())
{
}

Text &Text::operator=(const Text &txt)
{
    if (this != &txt)
    {
        this->pStore = (char *)txt.getCstring();
    }
    return *this;
}

const char *Text::getCstring() const
{
    return pStore;
}

ostream &operator<<(ostream &sout, const Text &txt)
{
    sout << txt.getCstring();
    return sout;
}
