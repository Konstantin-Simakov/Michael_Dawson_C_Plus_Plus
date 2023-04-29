// hero's_inventory3.cpp
// Demonstrates working with iterators
#include <iostream>
#include <string>		// For std::string
#include <vector>		// For std::vector

int main(void)
{
	using namespace std;
	vector<string> inventory;

	inventory.push_back("sword");
	inventory.push_back("armour");
	inventory.push_back("shield");

	vector<string>::iterator my_iterator;
	vector<string>::const_iterator iter;

	cout << "Your items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
		cout << *iter << endl;

	cout << "\nYou trade your sword for a battle axe.\n";
	my_iterator = inventory.begin();
	*my_iterator = "battle axe";

	cout << "\nYour items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
		cout << *iter << endl;

	cout << "\nThe item name \'" << *my_iterator << "\' has " 
		 << (*my_iterator).size() << " letters in it.\n";
	cout << "\nThe item name \'" << *my_iterator << "\' has "
		 << my_iterator->size() << " letters in it.\n";

	cout << "\nYou recover a crossbow from a slain enemy.\n";
	inventory.insert(inventory.begin(), "crossbow");
	
	cout << "Your items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
		cout << *iter << endl;

	cout << "\nYour armour is destroyed in a fierce battle.\n";
	inventory.erase(inventory.begin() + 2);

	cout << "Your items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); iter++)
		cout << *iter << endl;

	return 0;
}
