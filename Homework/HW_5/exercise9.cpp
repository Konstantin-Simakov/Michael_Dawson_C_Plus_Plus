// exercise9.cpp
// fibonacci() function.
#include <iostream>
using namespace std;

unsigned long fibonacci(unsigned number);

int main(void)
{
	cout << "Enter an integer: ";
	int num;
	cin >> num;

	cout << "fibonacci(" << num << ") = " << fibonacci(num) << endl;

	return 0;
}

unsigned long fibonacci(unsigned number)
{
	unsigned long result;
	unsigned long prev_1, prev_2;
	unsigned count;

	result = prev_1 = prev_2 = 1;

	for (count = 3; count <= number; count++)
	{
		result = prev_2 + prev_1;
		prev_2 = prev_1;
		prev_1 = result;
	}

	return result;
}
