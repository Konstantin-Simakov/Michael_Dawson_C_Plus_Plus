// exercise1.cpp
// Demonstrates using a pointer to pointer to string.
#include <iostream>

int main(void)
{
	using namespace std;
	string text = "Hello, dear friend!";
	string * p_text = &text;
	string ** pp_text = &p_text;

	cout << "The size of the text is: " << (*pp_text)->size() << endl;
	cout << "The size of the text is: " << (**pp_text).size() << endl;

	return 0;
}
