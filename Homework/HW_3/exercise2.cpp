// exercise2.cpp
// Prints the input text in reverse order
#include <iostream>

int main(void)
{
	using namespace std;
	cout << "Enter the text:\n";
	string text;
	getline(cin, text);

	cout << "\nThis text in reverse order:\n";
	for (int i = text.size() - 1; i >= 0; --i)
		cout << text[i];
	cout << "\n\nBye!\n";

	return 0;
}
