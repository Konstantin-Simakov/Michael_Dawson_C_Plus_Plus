// inventory_reference.cpp
// Demonstrates reference returning.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string & ref_to_element(vector<string> & inventory, int i);

int main(void)
{
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armour");
	inventory.push_back("shield");

	cout << "Sending the returned reference to cout:\n";
	cout << ref_to_element(inventory, 0) << "\n\n";

	cout << "Assigning the returned reference to another reference.\n";
	string & r_str = ref_to_element(inventory, 1);
	cout << "Sending the new reference to cout:\n";
	cout << r_str << "\n\n";

	cout << "Assigning the returned reference to a string object.\n";
	string str = ref_to_element(inventory, 2);
	cout << "Sending the new string object to cout:\n";
	cout << str << "\n\n";

	cout << "Altering an object through a returned reference.\n";
	r_str = "Healing Potion";
	cout << "Sending the altered object to cout:\n";
	cout << inventory[1] << endl;

	return 0;
}

string & ref_to_element(vector<string> & vec, int i)
{
	return vec[i];
}
