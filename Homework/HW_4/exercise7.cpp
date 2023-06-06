// exercise7.cpp
// 'Creator of Roler Person' program

#include <iostream>
#include <string>		// For std::string class
#include <map>			// For std::map container

int main(void)
{
	using namespace std;
	// Constants
	const int MAX_POOL = 30;
	// Initial variables
	map<string, int> person = {
		{"Strength", 0},	
		{"Health", 0}, 
		{"Wisdom", 0}, 
		{"Dexterity", 0}
	};
	
	int pool = MAX_POOL;

	// Player invitation
	cout << "\t\t\tWelcome to \'Creator of Roler Person\'!\n";

	int choice;
	do
	{
		// Output of results
		cout << "\nYour person has follow attributes:\n\n";
		cout << "\t\tStrength - " << person["Strength"] << endl;
		cout << "\t\tHealth - " << person["Health"] << endl;
		cout << "\t\tWisdom - " << person["Wisdom"] << endl;
		cout << "\t\tDexterity - " << person["Dexterity"] << endl;		
		cout << "\n\t\tPool has " << pool << " points.\n";

		// Menu
		cout << "\nWhat action do you want to choose?\n\n";
		cout << "\t\t0 - Exit\n";
		cout << "\t\t1 - Add a points to attributes\n";
		cout << "\t\t2 - Withdraw points from attributes\n\n";

		// Choice of action
		cout << "Your action: ";
		cin >> choice;

		// Values for according keys
		int strength = 0;
		int health = 0;
		int wisdom = 0;
		int dexterity = 0;
		switch (choice)
		{
			// 0 - Exit
			case 0:	
				break;

			// 1 - Add points from pool to attributes
			case 1: 
				// Data reading.
				cout << "\nHow many points do you want to add for \'Strength\'? ";
				cin >> strength;
				cout << "How many points do you want to add for \'Health\'? ";
				cin >> health;
				cout << "How many points do you want to add for \'Wisdom\'? ";
				cin >> wisdom;
				cout << "How many points do you want to add for \'Dexterity\'? ";
				cin >> dexterity;

				// Input validataion.
				while (strength + health + wisdom + dexterity > pool ||
						strength < 0 || health < 0 || wisdom < 0 || dexterity < 0)
				{
					cout << "Not enough points in the pool or incorrect input. Try again.\n";
					cout << "\nHow many points do you want to add for \'Strength\'? ";
					cin >> strength;
					cout << "How many points do you want to add for \'Health\'? ";
					cin >> health;
					cout << "How many points do you want to add for \'Wisdom\'? ";
					cin >> wisdom;
					cout << "How many points do you want to add for \'Dexterity\'? ";
					cin >> dexterity;
				}

				// Data writing if all is OK.
				person["Strength"] += strength;
				person["Health"] += health;
				person["Wisdom"] += wisdom;
				person["Dexterity"] += dexterity;
				pool -= strength + health + wisdom + dexterity;
				break;

			// 2 - Withdraw points from attributes to pool
			case 2:
				// Data reading.
				cout << "\nHow many points do you want to withdraw from \'Strength\'? ";
				cin >> strength;
				cout << "How many points do you want to withdraw from \'Health\'? ";
				cin >> health;
				cout << "How many points do you want to withdraw from \'Wisdom\'? ";
				cin >> wisdom;
				cout << "How many points do you want to withdraw from \'Dexterity\'? ";
				cin >> dexterity;

				// Input validation and setting correct values for according keys.
				if (strength > person["Strength"] || strength < 0)
				{
					strength = person["Strength"];
				}
				if (health > person["Health"] || health < 0)
				{
					health = person["Health"];
				}
				if (wisdom > person["Wisdom"] || wisdom < 0)
				{
					wisdom = person["Wisdom"];
				}
				if (dexterity > person["Dexterity"] || dexterity < 0)
				{
					dexterity = person["Dexterity"];
				}

				// Data writing when all is OK.
				person["Strength"] -= strength;
				person["Health"] -= health;
				person["Wisdom"] -= wisdom;
				person["Dexterity"] -= dexterity;
				pool += strength + health + wisdom + dexterity;
				break;

			// Invalid choice
			default:
				cout << "Invalid choice. Choose 0, 1 or 2.\n";
				break;
		}
	} while (choice != 0);
	cout << "\nBye!\n";

	return 0;
}
