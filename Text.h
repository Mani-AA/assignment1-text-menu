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
    const char *getCstring() const;
    Text & operator=(const Text &txt);

};

ostream &operator<<(ostream &sout, const Text &txt);
