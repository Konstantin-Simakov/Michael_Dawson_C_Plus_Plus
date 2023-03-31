// finicky_counter.cpp
// Demonstrates working with 'break' and 'continue' operators
#include <iostream>

int main(void)
{
	using namespace std;
	int count = 0;

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

	return 0;
}
