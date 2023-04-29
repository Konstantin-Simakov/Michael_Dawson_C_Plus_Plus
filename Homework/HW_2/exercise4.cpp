// exercise4.cpp
// 'Heads or tails?' program
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
	using namespace std;
	const int HEAD = 0;				// Numeric identifier of the situation 'head drop'
	const int TAIL = HEAD + 1;		// Numeric identifier of the situation 'tail drop'
	const int THROWS = 100;			// Max number of throws of the coin
	const int SIDES = 2;			// Number of coin sides
	int heads = 0;					// Total number of throwed heads
	int tails = 0;					// Total number of throwed tails
	int coin;						// For saving the value of head or tail drop

	// Player invitation
	cout << "\t\tWelcome to the \'Heads or tails?\' program!\n\n";
	// Calculates
	srand(static_cast<unsigned>(time(0)));
	while (heads + tails != THROWS)
	{
		coin = rand() % SIDES + HEAD;
		if (HEAD == coin)
			heads++;
		else if (TAIL == coin)
			tails++;
		else
			cout << "Error coin\n\n";
	}
	// Output of results
	cout << "You throwed " << heads << " heads " 
		 << "and " << tails << " tails.\n";

	return 0;
}
