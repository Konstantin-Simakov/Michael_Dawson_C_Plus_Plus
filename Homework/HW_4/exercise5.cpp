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
	map<string, string> relation;		// Dictionary of relation 'son-dad'
	int choice;

	// Player invitation
	cout << "\tWelcome to the \'Who is your daddy?\' program!\n";

	// Main loop
	do
	{
		// Menu
		cout << "\nChoose one from actions:\n"
			 << "1) Add a son-dad pair\n"
			 << "2) Change a son-dad pair\n"
			 << "3) Remove a son-dad pair\n"
			 << "4) Print all son-dad pairs\n"
			 << "5) Exit program\n";

		// Getting choice
		cout << "\nYour choice: ";
		(cin >> choice).get();

		// Choice processing
		string man;						// Name of son; dictionary key
		string dad;						// Name of his dad; dictionary value
		switch (choice)
		{
			case 1:
				cout << "Enter name of son: ";
				getline(cin, man);
				if (!(relation.contains(man)))
				{
					cout << "Enter name of dad: ";
					getline(cin, dad);
					relation[man] = dad;
					cout << "Added successfully.\n";
				}
				else
				{
					cout << "Sorry, the son " << man << " with his dad " << dad
						 << " is already. Try to remove it or add another pair.\n";					
				}
				break;
			case 2:
				cout << "Enter name of son: ";
				getline(cin, man);
				if (relation.contains(man))
				{
					cout << "Enter new name of dad: ";
					getline(cin, dad);
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
			case 5:
				cout << "\nBye!\n";
				break;
			default:
				cout << "Unknown choice. Enter 1, 2, 3, 4 or 5 only.\n";
				if (!cin)
					cin.clear();
				while (cin.get() != '\n')
					continue;
		}
	} while (choice != 5);

	return 0;
}
