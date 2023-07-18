// exercise4.cpp
// The program realizes adding of two fractions (almost).

#include <iostream>
#include <string>			// For std::to_string() function
#include <cstdlib>			// For exit(), EXIT_FAILURE
using namespace std;

void input(int & a, int & b, int & c, int & d, char & ch, char & oper);
float add_fractions(float a, float b, float c, float d);
void output(int a, int b, int c, int d, float res);

int main(void)
{
	int a, b, c, d;
	char ch, oper;

	input(a, b, c, d, ch, oper);
	float res = add_fractions(a, b, c, d);
	output(a, b, c, d, res);

	return 0;
}

void input(int & a, int & b, int & c, int & d, char & ch, char & oper)
{
	cout << "Enter the operation as a/b + c/d\n";
	cin >> a >> ch >> b >> oper >> c >> ch >> d;

	if (ch != '/' || oper != '+')
	{
		cout << "Input error\n";
		exit(EXIT_FAILURE);
	}
}

float add_fractions(float a, float b, float c, float d)
{
	return a / b + c / d;
}

void output(int a, int b, int c, int d, float res)
{
	string num;
	char numerator;

	num = to_string(res);
	numerator = num[2];

	cout << "\n" << a << "/" << b << "+" << c << "/" << d << " = " << numerator << "/10" << endl;
	cout << "\n" << a << "/" << b << "+" << c << "/" << d << " = " << res << endl;
}
