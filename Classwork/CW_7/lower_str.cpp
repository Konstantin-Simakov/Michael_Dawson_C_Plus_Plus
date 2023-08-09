// lower_str.cpp
// Converts C-string to lower case characters.
#include <iostream>
#include <cctype>       // For toupper()
using namespace std;

void to_lower_str(char * str);

int main(void)
{
	char str[] = "HELLO, Dear Friend.";
	cout << "Source string: " << str << endl;

	to_lower_str(str);
	cout << "New string: " << str << endl;

	return 0;
}

void to_lower_str(char * str)
{
	while (*str)
	{
		*str = tolower(*str);
		++str;
	}

}
