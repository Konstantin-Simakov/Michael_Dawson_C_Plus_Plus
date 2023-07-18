// exercise3.cpp
// Converts string object to upper case characters with using references.
#include <iostream>
#include <string>		// For std::string class
#include <cctype>		// For toupper()
using namespace std;

void to_upper_str(string & str);

int main(void)
{
	string str;

	cout << "Enter a string:\n";
	getline(cin, str);

	to_upper_str(str);
	cout << str << endl;

	cout << "Bye.\n";

	return 0;
}

void to_upper_str(string & str)
{
	for (unsigned i = 0; i < str.size(); i++)
	{
		str[i] = toupper(str[i]);
	}
}
