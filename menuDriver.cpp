#include <iostream>
#include "Text.h"
#include "Menu.h"

using namespace std;

void demoText();
void demoMenu();

int main()
{
	//demoText();
	demoMenu();
	return 0;
}

void demoMenu()
{
	Menu menu;
	//cout << menu << endl;

	//int choice = menu.read_option_number();
	//cout << "you entered: " << choice << endl;

	menu.push_back("Pepsi");
	menu.push_back("Apple juice");
	menu.push_back("Root beer");
	menu.set_top_message("Choose your thirst crusher");
	menu.set_bottom_message("Enter a drink number");
	cout << menu << endl;
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
