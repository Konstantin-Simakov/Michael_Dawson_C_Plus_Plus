// exercise7.cpp
// 'Creator of Roler Person' program

#include <iostream>
#include <string>		// For std::string class
#include <map>			// For std::map container
#include <vector>		// For std::vector container

int main(void)
{
	using namespace std;
	// Constants
	const int MAX_POOL = 30;
	// Initial variables.
	// Values of the 'person': 
	// 1st element -- points,
	// 2nd element -- index of a key.
	map<string, vector<int>> person = {
		{"Strength", {0, 0}},	
		{"Health", {0, 1}}, 
		{"Wisdom", {0, 2}}, 
		{"Dexterity", {0, 3}}
	};
	int pool = MAX_POOL;

	// Player invitation
	cout << "\t\t\tWelcome to \'Creator of Roler Person\'!\n";

	int choice;
	do
	{
		// Data output in the order they were initialized.
		cout << "\nYour person has follow attributes:\n\n";
		for (unsigned index_key = 0; index_key < person.size(); ++index_key)
		{
			// Data search by the given condition
			for (auto m_citer = person.cbegin(); m_citer != person.cend(); ++m_citer)
			{
				if (static_cast<unsigned>(m_citer->second[1]) == index_key)
				{
					cout << "\t\t" << m_citer->first << " - " << m_citer->second[0] << endl;
					break;
				}
			}
		}
		cout << "\n\t\tPool has " << pool << " points.\n";

		// Menu
		cout << "\nWhat action do you want to choose?\n\n";
		cout << "\t\t0 - Exit\n";
		cout << "\t\t1 - Add a points to attributes from pool\n";
		cout << "\t\t2 - Withdraw points from attributes to pool\n";

		// Choice of action
		cout << "\n\nYour action: ";
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

			// 1 - Add points from pool to attributes from pool
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
				person["Strength"][0] += strength;
				person["Health"][0] += health;
				person["Wisdom"][0] += wisdom;
				person["Dexterity"][0] += dexterity;
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
				if (strength > person["Strength"][0] || strength < 0)
				{
					strength = person["Strength"][0];
				}
				if (health > person["Health"][0] || health < 0)
				{
					health = person["Health"][0];
				}
				if (wisdom > person["Wisdom"][0] || wisdom < 0)
				{
					wisdom = person["Wisdom"][0];
				}
				if (dexterity > person["Dexterity"][0] || dexterity < 0)
				{
					dexterity = person["Dexterity"][0];
				}

				// Data writing when all is OK.
				person["Strength"][0] -= strength;
				person["Health"][0] -= health;
				person["Wisdom"][0] -= wisdom;
				person["Dexterity"][0] -= dexterity;
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
