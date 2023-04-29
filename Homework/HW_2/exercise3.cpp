// exercise3.cpp
// 'Pie festival' program
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
	using namespace std;
	const int NUM_PIES = 5;
	string pie;							// Name of a pie filling
	
	// Preparing calculates
	srand(static_cast<unsigned>(time(0)));
	int num = rand() % NUM_PIES + 1;	// In range of 1-5
	// Calculation results
	switch (num)
	{
		case 1: 
			pie = "apple";
			break;
		case 2:
			pie = "crimson";
			break;
		case 3:
			pie = "cherry";
			break;
		case 4:
			pie = "bilberry";
			break;
		case 5:
			pie = "cottage cheese";
			break;
		default:
			pie = "unknown";
	}

	// Output of results
	cout << "\t\tWelcome to the \'Pie fistival\' program!\n\n";
	cout << "You have a pie with " << pie << " pie filling.\n";

	return 0;
}
