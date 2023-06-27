// exercise8.cpp
// power() function.
#include <iostream>
#include <cmath>
using namespace std;

double power(double base, int degree);

int main(void)
{
	double base;
	int degree;

	cout << "Enter a power base: ";
	cin >> base;
	cout << "Enter a power degree: ";
	cin >> degree;

	double p = power(base, degree);
	cout << base << "^" << degree << " = " << p << endl;

	return 0;
}

double power(double base, int n)
{
	double res = 1.0;
	
	if (base != 0.0)
	{
		if (n > 0)
		{
			for (int i = 1; i <= n; i++)
			{
				res *= base;
			}			
		}
		else
		{
			for (int i = 1; i <= (-n); i++)
			{
				res *= base;
			}
			res = 1.0 / res;
		}		
	}
	else
	{
		if (n == 0)
		{
			cout << "\nThe result of raising 0 to the 0 power is undefined.\n";
			res = nan("The result of raising 0 to the 0 power is undefined.");
		}
		else
		{
			res = 0.0;
		}
	}

	return res;
}
