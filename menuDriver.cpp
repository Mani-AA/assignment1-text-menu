#include <iostream>
#include "Text.h"

using namespace std;

int main()
{
	Text t1;
	Text t2("quick brown fox");
	Text t3{t2};

	cout << "t1: " << t1 << endl;
	cout << "t2: " << t2 << endl;
	cout << "t3: " << t3 << endl;

	t2 = Text(" jumps over  ");	
	cout << "t2:" << t2 << endl;

	return 0;
}
