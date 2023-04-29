// hero's_inventory2.cpp
// Demonstrates working with vectors.
#include <iostream>
#include <vector>		// For std::vector
#include <string>		// For std::string

int main(void)
{
	using namespace std;
	vector<string> inventory;
	
	// Adding elements to the end of vector
	inventory.push_back("sword");
	inventory.push_back("armour");
	inventory.push_back("shield");

	// Displaying the number of elements in the vector
	cout << "You have " << inventory.size() << " items.\n";
	// Displaying consists of vector elements 
	cout << "\nYour items:\n";
	for (unsigned i = 0; i < inventory.size(); ++i)
		cout << inventory[i] << endl;

	// Changing the value of a vector element
	cout << "\nYou trade your sword for a battle axe.\n";
	inventory[0] = "battle axe";
	// Displaying the changed vector consist 
	cout << "Now your items:\n";
	for (unsigned i = 0; i < inventory.size(); ++i)
		cout << inventory[i] << endl;

	// Working with a vector element by its index
	cout << "\nThe item name \'" << inventory[0] << "\' has "
		 << inventory[0].size() << " letters in it.\n";

	// Deleting the end element from the vector
	cout << "\nYour shield is destroyed in a fierce battle.";
	inventory.pop_back();
	// Displaying the changed vector consist
	cout << "\nNow your items:\n";
	for (unsigned i = 0; i < inventory.size(); ++i)
		cout << inventory[i] << endl;

	// Deleting of all elements in the vector and making empty it consist
	cout << "\nYou were robbed of all of your possessions by a thief.";
	inventory.clear();
	// Checking if the vector is empty
	if (inventory.empty())
		cout << "\nYou have nothing.\n";
	else
		cout << "\nYou have at least one item.\n";

	return 0;
}
