// simplepolydr.cpp
// Copyright by Venu Dasigi

#include "simplepoly.h"
#include <iostream>

using namespace std;

const unsigned int MAX = 50;
void main ()
{
	// Pre: None.
	// Post: Give the user a menu of choices.
	//       Based on what command the user inputs, take
	//       the appropriate action as guaranteed by the menu.
	//       Input is accepted in a case-insensitive manner!
	simplepoly p[MAX];
	char command;
	unsigned int i, j, k;
	float value;
	void printmenu ();

	printmenu();
	do
	{
		cin >> command;
		switch (command)
		{
			case '?':
			case 'H':
			case 'h':
				printmenu();
				break;
			case 'R':
			case 'r':
				cin >> i;
				p[i].read();
				break;
			case 'P':
			case 'p':
				cin >> i;
				p[i].write();
				break;
			case '+':
				cin >> i >> j >> k;
				p[k] = p[i].plus(p[j]);
				break;
			case '-':
				cin >> i >> j >> k;
				p[k] = p[i].minus(p[j]);
				break;
			case 'E':
			case 'e':
				cin >> i >> value;
				cout << p[i].evaluate(value) <<endl;
				break;
			case 'Q':
			case 'q':
				break;
			default:
				cout << "Enter a valid command.  Type H or ? for help."
					<< endl;
		};
	}
	while ((command != 'Q') && (command != 'q'));
};

void printmenu ()
{
	// Pre: None.
	// Post: Print a menu of choices.
	cout
		<< "Available commands:\n"
		<< "?: to print this menu\n"
		<< "H: to print this menu\n"
		<< "R n: to read a value for polynomial n\n"
		<< "P n: to print the value of polynomial n\n"
		<< "+ i j k: to add polynomials i and j and store result in k\n"
		<< "- i j k: to subtract polynomials j from i and store result in k\n"
		<< "E n v: to evaluate polynomial n with its variable set to value v\n"
		<< "Q: to quit\n";
};
