// inventory_displayer.cpp
// Demonstrates working with constant references
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void display(const vector<string> & inventory);

int main(void)
{
	vector<string> inventory;

	inventory.push_back("sword");
	inventory.push_back("armour");
	inventory.push_back("shield");

	display(inventory);

	return 0;
}

void display(const vector<string> & vec)
{
	cout << "Your items:\n";
	for (vector<string>::const_iterator c_iter = vec.cbegin(); 
			c_iter != vec.cend(); ++c_iter)
	{
		cout << *c_iter << endl;
	}
}
