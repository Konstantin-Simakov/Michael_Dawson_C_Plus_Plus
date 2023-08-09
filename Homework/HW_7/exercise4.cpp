// exercise4.cpp
// The program reverses a C-string.

#include <iostream>
#include <cstring>		// For strlen()
using namespace std;

void reverse(char * str);
void swap(char * const c_1, char * const c_2);

int main(void)
{
	char str[] = "Hello, world!";
	cout << "Source string:   " << str << endl;

	reverse(str);
	cout << "Reversed string: " << str << endl;

	return 0;
}

void reverse(char * str)
{
	const unsigned S_LEN = strlen(str);

	for (unsigned i = 0; i < S_LEN / 2; i++)
	{
		swap(str[i], str[S_LEN - (i + 1)]);
	}
}

void swap(char * const c_1, char * const c_2)
{
	char t;

	t = *c_1;
	*c_1 = *c_2;
	*c_2 = t;
}
