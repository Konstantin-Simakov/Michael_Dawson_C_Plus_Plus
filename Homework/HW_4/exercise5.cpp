// exercise5.cpp
// 'Who is your daddy?' program with 'map' (for C++, 'dicionary' for Python) type

/* Compile this program with option -std=c++2a on linux.
 * (If the contains() method (C++20 and above) doesn't work, replace it with count().)
 */

#include <iostream>
#include <map>
#include <string>

int main(void)
{
	using namespace std;
	map<string, string> relation;				// Dictionary of relation 'son-dad'
	int choice;									// User choice

	// Player invitation
	cout << "\tWelcome to the \'Who is your daddy?\' program!\n";

	// Main loop
	do
	{
		// Menu
		cout << "\nChoose one from actions:\n"
			 << "0) Exit program\n"
			 << "1) Add a son-dad pair\n"
			 << "2) Change a son-dad pair\n"
			 << "3) Remove a son-dad pair\n"
			 << "4) Print all son-dad pairs\n";

		// Getting and checking the choice
		cout << "\nYour choice: ";
		while (!(cin >> choice))				// SPECIFY THIS FOR STUDENT!!!
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Please enter a number: ";
		}
		cin.get();

		// Choice processing
		string man;						// Name of son; dictionary key
		string dad;						// Name of his dad; dictionary value
		switch (choice)
		{
			case 0:
				cout << "\nBye!\n";
				break;
			case 1:
				cout << "Enter name of son: ";
				getline(cin, man);
				while (man.empty())
				{
					getline(cin, man);
				}

				if (!(relation.contains(man)))
				{
					cout << "Enter name of dad: ";
					getline(cin, dad);
					while (dad.empty())
					{
						getline(cin, dad);
					}

					relation[man] = dad;
					cout << "Added successfully.\n";
				}
				else
				{
					cout << "Sorry, the son " << man << " with his dad " << relation[man]
						 << " is already. Try to remove it or add another pair.\n";					
				}
				break;
			case 2:
				cout << "Enter name of son: ";
				getline(cin, man);
				while (man.empty())
				{
					getline(cin, man);
				}

				if (relation.contains(man))
				{
					cout << "Enter new name of dad: ";
					getline(cin, dad);
					while (dad.empty())
					{
						getline(cin, dad);
					}
					
					relation[man] = dad;
					cout << "Changed successfully.\n";
				}
				else
				{
					cout << "Sorry, the son " << man << " with his dad "
						 << "is not. Try to add it.\n";					
				}
				break;
			case 3:
				cout << "Enter a name of son: ";
				getline(cin, man);
				while (man.empty())
				{
					getline(cin, man);
				}

				if (relation.contains(man))
				{
					relation.erase(man);
					cout << "Removed successfully.\n";
				}
				else
				{
					cout << "Sorry, the son " << man << " with his dad "
						 << "is not. Try to add it.\n";					
				}
				break;
			case 4:
				if (!(relation.empty()))
				{
					for (auto one_pair = relation.cbegin(); one_pair != relation.cend(); one_pair++)
					{
						cout << "Son: " << one_pair->first << ", his dad: " << one_pair->second << endl;
					}
					cout << endl;					
				}
				else
				{
					cout << "There are no \'son-dad\' pairs. Try to add it.\n";
				}
				break;
			default:
				cout << "Unknown choice. Enter 0, 1, 2, 3, 4 only.\n";
		}
	} while (choice != 0);

	return 0;
}
