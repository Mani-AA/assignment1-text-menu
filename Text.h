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
    const char *getCstring() const;
    Text &operator=(const Text &txt);
};

ostream &operator<<(ostream &sout, const Text &txt);
