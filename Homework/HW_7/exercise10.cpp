// exercise10.cpp
// Self realization of the strchr() function from C standard library. 
#include <iostream>

char * my_strchr(const char * str, int ch);

int main(void)
{
	using namespace std;
	char str[] = "Hello, my friends!\nHow are you?\n";
	const char * const find = my_strchr(str, '\n');
	
	cout << find + 1 << endl;

	return 0;
}

char * my_strchr(const char * str, int ch)
{
	char * ptr_to_ch;

	while (*str != ch && *str)
	{
		str++;
	}
	
	if (!*str)
	{
		ptr_to_ch = NULL;
	}
	else
	{
		ptr_to_ch = (char *) (str);
	}

	return ptr_to_ch;
}
