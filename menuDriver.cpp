#include <iostream>
#include "Text.h"

using namespace std;

void demoText();

int main()
{
	demoText();
	return 0;
}

void demoText()
{
	Text t1;
	Text t2("quick brown fox");
	Text t3{t2};

	cout << "t1: " << t1 << endl;
	cout << "t2: " << t2 << endl;
	cout << "t3: " << t3 << endl;

	t1.append("The ");
	cout << "t1: " << t1 << endl;
	t1.append(t2);
	cout << "t1: " << t1 << endl;

	t2 = Text(" jumps over ");
	cout << "t2:" << t2 << endl;

	t3.assign("a lazy dog");
	cout << "t3: " << t3 << endl;

	t1.append(t2);
	cout << "t1: " << t1 << endl;

	t1.append(t3);
	cout << "t1: " << t1 << endl;
}
