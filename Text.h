#ifndef TEXT_H
#define TEXT_H

#include <iostream>

using namespace std;

class Text
{
private:
    char *pStore;

public:
    Text();
    Text(const char *pCstr);
    Text(const Text &text);
    virtual ~Text();
    void assign(const char *pCstr);
    void assign(const Text &txt);
    void append(const char *pCstr);
    void append(const Text &txt);
    void clear();
    int length();
    bool isEmpty();
    const char *getCstring() const;
    Text &operator=(const Text &txt);
};

ostream &operator<<(ostream &sout, const Text &txt);

#endif
