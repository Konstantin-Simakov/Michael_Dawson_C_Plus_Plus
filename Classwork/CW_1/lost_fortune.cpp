// lost_fortune.cpp
#include <iostream>
#include <string>		// For std::string

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;
	const int GOLD_PIECES = 1000;
	int adventurers, killed, survivors;
	string leader;

	// Get the information
	cout << "Welcome to \'Lost Fortune\'\n\n";
	cout << "Please enter the following for your personalized adventure\n";
	cout << "Enter a number: ";
	cin >> adventurers;
	cout << "Enter a number, smaller than the first: ";
	cin >> killed;
	survivors = adventurers - killed;
	cout << "Enter your last name: ";
	cin >> leader;

	// Game plot
	cout << "\nA brave group of " << adventurers << " set out on a quest ";
	cout << "-- in search of the lost treasure of the Ancient Dwarves. ";
	cout << "The group was led by that legendary rogue, " << leader << ".\n";

	cout << "\nAlong the way, a band of marauding ogres ambushed the party. ";
	cout << "All fought bravely under the command of " << leader;
	cout << ", and the ogres were defeated, but at a cost. ";
	cout << "Of the adventurers, " << killed << " were vanquished, ";
	cout << "leaving just " << survivors << " in the group.\n";
	
	cout << "\nThe party was about to give up all hope. ";
	cout << "But while laying the deceased to rest, ";
	cout << "they stumbled upon the buried fortune. ";
	cout << "So the adventurers split " << GOLD_PIECES << " gold pieces. ";
	cout << leader << " held on to the extra " << (GOLD_PIECES % survivors);
	cout << " pieces to keep things fair, of course.\n";

	return 0;
}
