// exercise12.cpp
// Deletes all whitespace characters from a C-string.

#include <iostream>
#include <cctype>		// For isspace() 
#include <cstring>		// For strlen()

void str_delete_spaces(char *);

int main(void)
{
	using namespace std;
	char str[] = "Hello, dear friend!\n  \t ";
	cout << "Source string:\n" << str << endl;
	cout << "The size of the string is: " << strlen(str) << endl;

	str_delete_spaces(str);
	cout << "\nProcessed string:\n" << str << endl;
	cout << "The size of the string is: " << strlen(str) << endl;
	
	return 0;
}

void str_delete_spaces(char * str)
{
	char * temp = NULL;

	while (*str)
	{
		if (isspace(*str))
		{
			temp = str;
			while (*temp)
			{
				// Shift all characters 1 position to the left.
				*temp = *(temp + 1);
				temp++;
			}
			// If the string consists of more than 1 whitespace character in a row.
			continue;
		}
		str++;
	}
}
