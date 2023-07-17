// triple.cpp
// Demonstrates function overloading

#include <iostream>
#include <string>			// For std::string
using namespace std;

int triple(int num);
string triple(string text);

int main(void)
{
	cout << "Tripling 5: " << triple(5) << "\n\n";
	cout << "Tripling \'gamer\': " << triple("gamer") << endl;

	return 0;
}

int triple(int num)
{
	return num * 3;
}

string triple(string text)
{
	return text + text + text;
}
