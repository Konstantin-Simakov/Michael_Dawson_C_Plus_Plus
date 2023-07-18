// exercise6.cpp
// The program traverses a positive number.

#include <iostream>
#include <string>
using namespace std;

void reverse(string & str);
void swap(char & c_1, char & c_2);

int main(void)
{
	string str;

	cout << "Enter a string:\n";
	getline(cin, str);
	
	reverse(str);
	cout << "Reversed string:\n" << str << endl;

	cout << "\nBye!\n";

	return 0;
}

void reverse(string & str)
{
	const unsigned S_LEN = str.size();

	for (unsigned i = 0; i < S_LEN / 2; i++)
		swap(str[i], str[S_LEN - (i + 1)]);
}

void swap(char & c_1, char & c_2)
{
	char t;

	t = c_1;
	c_1 = c_2;
	c_2 = t;
}
