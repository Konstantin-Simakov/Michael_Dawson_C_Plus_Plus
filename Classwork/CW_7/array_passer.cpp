// array_passer.cpp
// Demonstrates the relationship between pointers and arrays.
#include <iostream>
using namespace std;

void increase(int * const array, const int NUM_ELEMENTS);
void display(const int * const array, const int NUM_ELEMENTS);

int main(void)
{
	cout << "Creating an array of high scores.\n\n";
	const int NUM_SCORES = 3;
	int high_scores[NUM_SCORES] = {5000, 3500, 2700};

	cout << "Displaying scores using array name as a constant pointer.\n";
    // array_name[i] == *(array_name + i)
	cout << *high_scores << endl;              // high_scores[0]
	cout << *(high_scores + 1) << endl;        // high_scores[1]
	cout << *(high_scores + 2) << "\n\n";      // high_scores[2]

	cout << "Increasing scores by passing array as a constant pointer.\n\n";
	increase(high_scores, NUM_SCORES);

	cout << "Displaying scores by passing array as a constant pointer to a constant.\n";
	display(high_scores, NUM_SCORES);

	return 0;
}

void increase(int * const array, const int NUM_ELEMENTS)
{
	for (int i = 0; i < NUM_ELEMENTS; ++i)
	{
		array[i] += 500;
	}
}

void display(const int * const array, const int NUM_ELEMENTS)
{
	for (int i = 0; i < NUM_ELEMENTS; ++i)
	{
		cout << array[i] << endl;
	}
}
