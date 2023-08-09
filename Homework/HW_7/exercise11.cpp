// exercise11.cpp
// Checks if the character is in a C-string.
#include <iostream>

bool is_within(const char * s, char c);

int main(void)
{
	using namespace std;
	char str[] = "Hello, dear friend!";
	char ch = '.';

	cout << "Source string:\n" << str << endl;
	if (is_within(str, ch))
	{
		cout << "The character \'" << ch << "\' consists in the string.\n";
	}
	else
	{
		cout << "The character \'" << ch << "\' doesn\'t consist in the string.\n";
	}

	return 0;
}

bool is_within(const char * s, char c)
{
	bool in_str = false;

	while (*s != c && *s)
	{
		s++;
	}	
	if (*s)
	{
		in_str = true;
	}

	return in_str;
}
