// exercise4.cpp
// Prints the input text in direct and reverse order
#include <iostream>

int main(void)
{
	using namespace std;
	cout << "Enter the text:\n";
	string text;
	getline(cin, text);

	cout << "\nThe text in direct order:\n";
	cout << text << endl;

	cout << "\nThe text in reverse order:\n";
	for (int i = text.size() - 1; i >= 0; --i)
		cout << text[i];
	
	cout << "\n\nBye!\n";

	return 0;
}
