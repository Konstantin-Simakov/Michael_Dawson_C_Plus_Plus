// endless_loop.cpp
// Demonstrates working with endless loop
// (Bad program)

#include <iostream>

int main(void)
{
	using namespace std;
	int test = 10;

	while (10 == test)
		cout << test << endl;

	return 0;
}
