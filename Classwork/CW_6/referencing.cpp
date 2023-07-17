// referencing.cpp
// Demonstrates working with references
#include <iostream>

int main(void)
{
	using namespace std;
	int my_score = 1000;
	// Create a reference.
	int & mikes_score = my_score;

	cout << "my_score is: " << my_score << endl;
	cout << "mikes_score is: " << mikes_score << "\n\n";

	cout << "Adding 500 to my_score\n";
	my_score += 500;
	cout << "my_score is: " << my_score << endl;
	cout << "mikes_score is: " << mikes_score << "\n\n";

	cout << "Adding 500 to mikes_score\n";
	mikes_score += 500;
	cout << "my_score is: " << my_score << endl;
	cout << "mikes_score is: " << mikes_score << "\n\n";	

	return 0;
}
