// exercise3.cpp
// List of the favourite games with 'vector' container type

#include <iostream>			// For cout, cin, etc.
#include <string>			// For std::string type, getline() function, std::string::npos constant == -1
#include <vector>			// For std::vector type, earse(), empty(), begin(), end() methods
#include <algorithm>		// For find()

int main(void)
{
	using namespace std;
	vector<string> games;	// List of games
	int choice;				// User choice

	// Player invitation
	cout << "\tWelcome to the \'Maintaining a list of games\' program!\n";
	
	// Main loop
	do
	{
		// Menu
		cout << "\nChoose one of the action.\n";
		cout << "0) Exit porgram\n";
		cout << "1) List the titles of all specified games\n";
		cout << "2) Add a game title\n";
		cout << "3) Remove a game title\n";

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
		string game;
		vector<string>::const_iterator c_iter;
		switch (choice)
		{
			case 0:
				// Player farewell
				cout << "\nBye!\n";
				break;
			case 1: 
				cout << "Your list of games:\n";
				if (games.empty())
				{
					cout << "You have nothing in the list yet.\n";
				}
				else
				{
					for (c_iter = games.begin(); c_iter != games.end(); c_iter++)
					{
						cout << "\t" << *c_iter << endl;
					}					
				}
				break;
			case 2:
				cout << "Enter a game title: ";
				getline(cin, game);
				
				// Checking if the name already exists
				if (find(games.begin(), games.end(), game) != games.end())
				{
					cout << "This game has already existed in the list. " 
						 << "Try to remove it or add another one.\n";
				}
				else
				{
					games.push_back(game);
					cout << "Added successfully.\n";					
				}
				break;
			case 3: 
				cout << "Enter a game title: ";
				getline(cin, game);

				c_iter = find(games.begin(), games.end(), game);
				if (games.end() == c_iter)
				{
					cout << "This game is absent in the list. " 
						 << "Firstly try to add it or remove another one.\n";
				}
				else
				{
					games.erase(c_iter);
					cout << "Removed successfully.\n";
				}
				break;
			default:
				cout << "Unknow choice. Please choose 0, 1, 2, 3.\n";
		}
	} while (choice != 0);

	return 0;
}
