// exercise5.cpp
// The program calculates absolute value of integer
// and minimum between two integers.

#include <iostream>
using namespace std;

void input(int & x, int & y, int & z);
unsigned absolute(int x);
int minimum(int y, int z);
void output(int x, int y, int z, int a, int m);

int main(void)
{
	int x, y, z;
	int a;		// For absolute value
	int m;		// For minimum value

	input(x, y, z);

	a = absolute(x);
	m = minimum(y, z);
	
	output(x, y, z, a, m);

	return 0;
}

void input(int & x, int & y, int & z)
{
	cout << "Enter an integer: ";
	cin >> x;

	cout << "Enter two integers: ";
	cin >> y >> z;
}

unsigned absolute(int x)
{
	return x < 0 ? -x : x;
}

int minimum(int y, int z)
{
	return y < z ? y : z;
}

void output(int x, int y, int z, int a, int m)
{
	cout << "\nAbolute value of " << x << ": " << a << endl;
	cout << "\nMinimum of " << y << " and " << z << ": " << m << endl;
}
