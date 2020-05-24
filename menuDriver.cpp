#include <iostream>
#include "Text.h"
#include "Menu.h"

using std::cout;
using std::cin;
using std::endl;

void demoText();
void demoMenu();

int main()
{
	cout << "start of demoText:" << endl;
	demoText();
	cout << "end of demoText" << endl;

	cout << endl;

	cout << "start of demoMenu:" << endl;
	demoMenu();
	cout << "end of demoMenu" << endl;

	return 0;
}

void demoMenu()
{
	//1) Create an empty menu
	Menu menu;

	//2) Print an empty menu
	cout << menu << endl;

	//3) Display the menu and read user's input 
	int choice = menu.read_option_number();
	cout << "you entered: " << choice << endl;

	//4) Add an option to our menu
	menu.push_back("Pepsi");
	cout << menu << endl;

	//5 Let's add couple of more options to our menu
	menu.push_back("Apple juice");
	menu.push_back("Root beer");
	choice = menu.read_option_number();
	cout << "you entered: " << choice << endl;

	//6) Let's setup the top and bottom message
	menu.set_top_message("Choose your thirst crusher");
	menu.set_bottom_message("Enter a drink number");
	cout << menu << endl;

	//7) Let's remove the last option and then insert a new option at number 2
	menu.pop_back();
	menu.insert(2, "Icded tea with lemon");
	choice = menu.read_option_number();
	cout << "you entered: " << choice << endl;

	//8) The menu object let's you remove an option by option number
	menu.pop_back();
	menu.remove(1);
	cout << menu << endl;

	//9) The following code segment removes the only remaining option, leaving the menu with an empty option list:
	menu.pop_back();
	cout << menu << endl;

	//10) Here is our final example
	menu.clear_bottom_message();
	menu.set_top_message("Who Says You Can't Buy Happiness?\n"
		"Just Consider Our Seriously Delicious Ice Cream Flavors");
	menu.set_bottom_message("Enter the number of your happiness! ");
	menu.push_back("Bacon ice cream!");
	menu.push_back("Strawberry ice cream");
	menu.push_back("Vanilla ice cream");
	menu.push_back("Chocolate chip cookie dough ice cream");
	choice = menu.read_option_number();
	cout << "you entered: " << choice << endl;
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
