// inventory_pointer.cpp
// Demonstrates returning a pointer.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string * const ptr_to_element(vector<string> * const p_vec, int i);

int main(void)
{
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armour");
	inventory.push_back("shield");

	cout << "Sending the object pointed to by returned pointer to cout:\n";
	cout << *(ptr_to_element(&inventory, 0)) << "\n\n";

	cout << "Assigning the returned pointer to another pointer.\n";
	string * const p_str = ptr_to_element(&inventory, 1);
	cout << "Sending the object pointed to by new pointer to cout:\n";
	cout << *p_str << "\n\n";

	cout << "Assigning object pointed to by pointer to a string object.\n";
	string str = *(ptr_to_element(&inventory, 2));
	cout << "Sending the new string object to cout:\n";
	cout << str << "\n\n";

	cout << "Altering an object through a returned pointer.\n";
	*p_str = "Healing Potion";
	cout << "Sending the altered object to cout:\n";
	cout << inventory[1] << endl;

	return 0;
}

string * const ptr_to_element(vector<string> * const p_vec, int i)
{
	return &((*p_vec)[i]);
}
