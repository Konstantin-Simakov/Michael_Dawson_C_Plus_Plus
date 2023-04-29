// high_scores.cpp
// Demonstrates working with algorithms
#include <iostream>
#include <vector>		// For std::vector
#include <algorithm>	// For STL algorithm using
#include <ctime>		// For time()
#include <cstdlib>		// For srand()

int main(void)
{
	using namespace std;
	vector<int>::const_iterator iter;

	cout << "Creating a list of scores.\n";
	vector<int> scores;
	scores.push_back(1500);
	scores.push_back(3500);
	scores.push_back(7500);

	cout << "High Scores:\n";
	for (iter = scores.begin(); iter != scores.end(); iter++)
		cout << *iter << endl;

	cout << "\nFinding a score.\n";
	cout << "Enter a score to find: ";
	int score;
	cin >> score;
	iter = find(scores.begin(), scores.end(), score);
	if (iter != scores.end())
		cout << "Score found.";
	else
		cout << "Score not found.";

	cout << "\n\nRandomizing scores.\n";
	srand(static_cast<unsigned>(time(0)));
	random_shuffle(scores.begin(), scores.end());
	cout << "High Scores:\n";
	for (iter = scores.begin(); iter != scores.end(); iter++)
		cout << *iter << endl;

	cout << "\nSorting scores.\n";
	sort(scores.begin(), scores.end());
	cout << "High Scores:\n";
	for (iter = scores.begin(); iter != scores.end(); iter++)
		cout << *iter << endl;

	return 0;
}
