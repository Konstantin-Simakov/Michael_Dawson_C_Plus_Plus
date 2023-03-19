// exercise3.cpp
#include <iostream>

int main(void)
{
	using namespace std;
	cout << "Enter 3 sum of scores for different attempts in a play.\n";
	cout << "Only integers: ";
	int sum1, sum2, sum3;
	cin >> sum1 >> sum2 >> sum3;	// Cascading for >> operation

	// Calculating and displaying results
	float average = (sum1 + sum2 + sum3) / 3.0;	// With 3.0 for float dividing due to 
												// implicit type conversion
	cout << "Average of this 3 values equals " << average << endl;

	return 0;
}
