// finicky_counter.cpp
// Demonstrates working with 'break' and 'continue' operators
#include <iostream>

int main(void)
{
	using namespace std;
	int count = 0;

	// 1st version of 'while' loop 
	// (with 'break' and 'continue' using)
	while (true)
	{
		count++;
		
		// End the loop if the value more than 10
		if (count > 10)
			break;
		// Skip 5
		if (5 == count)
			continue;

		cout << count << endl;
	}
	cout << endl;

	count = 1;
	// 2nd version of 'while' loop 
	// (without 'break' and 'continue' using)
	while (count <= 10)
	{
		if (count != 5)
			cout << count << endl;
		count++;
	}

	return 0;
}
