// exercise1.cpp
// Demonstrates iterating over vector elements
#include <iostream>
#include <vector>		// For std::vector
#include <string>		// For std::string

int main(void)
{
	using namespace std;
	vector<int> scores = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int>::iterator score;

	// Output of the vector
	for (score = scores.begin(); score != scores.end(); score++)
	{
		cout << *score << "  ";
	}
	cout << endl;

	// Increase the value of the every vector element by 1
	for (score = scores.begin(); score != scores.end(); score++)
	{
		(*score)++;
	}

	// Output of the vector
	for (score = scores.begin(); score != scores.end(); score++)
	{
		cout << *score << "  ";
	}
	cout << endl;

	return 0;
}
