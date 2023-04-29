// exercise2.cpp
// Endless cycle
#include <iostream>

int main(void)
{
	using namespace std;
	int x = 1;

	while (x < 10)
	{
		++x;
		cout << x << endl;
	}

	return 0;
}
