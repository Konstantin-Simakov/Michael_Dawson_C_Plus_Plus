// designers_network.cpp
// Demonstrates working with logical operators
#include <iostream>
#include <string>		// For std::string

int main(void)
{
	using namespace std;
	string username;
	string password;
	bool success;

	cout << "\tGame Designer's Netowork\n\n";
	do
	{
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;

		cout << endl;
		if ("S.Meier" == username && "civilization" == password)
		{
			cout << "Hey, Sid!\n";
			success = true;
		}
		else if ("S.miyamoto" == username && "mariobros" == password)
		{
			cout << "Wats\'up, Shigeru?\n";
			success = true;
		}
		else if ("W.Wright" == username && "thesims" == password)
		{
			cout << "How goes it, Will?\n";
			success = true;
		}
		else if ("guest" == username || "guest" == password)
		{
			cout << "Welcome, guest!\n";
			success = true;
		}
		else
		{
			cout << "Your login failed.\n";
			success = false;
		}
	} while (!success);

	return 0;
}
