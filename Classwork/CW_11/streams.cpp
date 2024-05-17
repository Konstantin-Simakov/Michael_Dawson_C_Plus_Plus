// streams.cpp
// Demonstrates cin, cout and cerr objects working.

#include <iostream>
using namespace std;

int main(void)
{
	int age;
	double weight;
	string name; 
	
	cout << "Enter name: ";
	// cin >> name;
	getline(cin, name, '*');
	cout << "Input age: ";
	cin >> age;
	cout << "Input weight: ";
	cin >> weight;

	cout << "Your name: " << name << ", age: " << age << ", weight: " << weight << endl;
	cerr << "Error occured!\n";
}
