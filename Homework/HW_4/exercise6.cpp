// exercise6.cpp
// 'Who is your dad and grandpa?' program

/* Compile this program with option -std=c++2a on linux.
 * (If the contains() method (C++20 and above) doesn't work, replace it with count().)
 */

#include <iostream>
#include <map>
#include <vector>
#include <string>

int main(void)
{
	using namespace std;
	map<string, vector<string>> relation;		// Dictionary of relation 'son-dad-grandpa'
	int choice;									// User choice

	// Player invitation
	cout << "\tWelcome to the \'Who is your daddy and grandpa?\' program!\n";

	// Main loop
	do
	{
		// Menu
		cout << "\nChoose one from actions:\n"
			 << "0) Exit program\n"
			 << "1) Add a son-dad-grandpa trio\n"
			 << "2) Change a son-dad-grandpa trio\n"
			 << "3) Remove a son-dad-grandpa trio\n"
			 << "4) Print all son-dad-grandpa trios\n";

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
		string man;				// Name of son; dictionary key
		string dad;				// Name of his dad; first vector value of the dictionary			
		string grandpa;			// Name of his grandpa; second vector value of the dictionary
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
					cout << "Enter name of grandpa: ";
					getline(cin, grandpa);

					relation[man].push_back(dad);
					if (!(grandpa.empty()))
					{
						relation[man].push_back(grandpa);
					}
					cout << "Added successfully.\n";
				}
				else
				{
					cout << "Sorry, the son " << man << " with his dad " << relation[man][0]
						 << " and his grandpa " << relation[man][1] << " is already.\n"
						 << "Try to remove or change it or add another pair.\n";					
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
					cout << "Enter new name of grandpa: ";
					getline(cin, grandpa);

					relation[man][0] = dad;
					// If here is no current grandpa, and here is previous grandpa
					if ((grandpa.empty()) && (relation[man].size() == 2))
					{
						// Delete the previous grandpa
						relation[man].pop_back();
					}
					// If here is the current grandpa
					else if (!(grandpa.empty()))
					{
						// Add him or change name of the previous grandpa anyway
						relation[man].resize(2);
						relation[man][1] = grandpa;
					}

					cout << "Changed successfully.\n";
				}
				else
				{
					cout << "Sorry, the son " << man << " with his dad "
						 << "and grandpa is not. Try to add it.\n";					
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
						 << "and grandpa is not. Try to add it.\n";					
				}
				break;
			case 4:
				if (!(relation.empty()))
				{
					for (auto one_pair = relation.cbegin(); one_pair != relation.cend(); one_pair++)
					{
						cout << "Son: " << one_pair->first << ", his dad: " << one_pair->second[0];
						if (one_pair->second.size() == 2)
						{
							cout << ", his grandpa: " << one_pair->second[1] << endl;
						}
						else
						{
							cout << endl;
						}
					}
					cout << endl;
				}
				else
				{
					cout << "There are no \'son-dad-grandpa\' trios. Try to add it.\n";
				}
				break;
			default:
				cout << "Unknown choice. Enter 0, 1, 2, 3, 4 only.\n";
		}
	} while (choice != 0);

	return 0;
}
