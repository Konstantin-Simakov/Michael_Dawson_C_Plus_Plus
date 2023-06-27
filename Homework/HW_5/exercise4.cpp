// exercise4.cpp
// Factorial function.

#include <iostream>

long factorial(int n);

int main(void)
{
	using namespace std;
	int num;
	
	cout << "Enter a number: ";
	cin >> num;
	cout << num << "! = " << factorial(num) << endl;

	return 0;
}

long factorial(int n)
{
	long res = 1;

	for (int i = 1; i <= n; ++i)
		res *= i;

	return res;
}
