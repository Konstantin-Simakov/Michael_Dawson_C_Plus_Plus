// dice_roller.cpp
// Demonstrates generation of random numbers
#include <iostream>
#include <cstdlib>		// For rand(), srand(), RAND_MAX
#include <ctime>		// For time()

int main(void)
{
	using namespace std;
	// General form of explicit type conversion: 
	// static_cast<type>(value)
	srand(static_cast<unsigned>(time(0)));
	int dice = rand() % 6 + 1;
	
	cout << "You rolled " << dice << " points." << endl;
	cout << "RAND_MAX = " << RAND_MAX << endl;

	return 0;
}
