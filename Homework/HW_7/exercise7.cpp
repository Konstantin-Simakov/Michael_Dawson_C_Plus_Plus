// exercise7.cpp
// The program about seasons and expenses.
#include <iostream>

const int SEASONS = 4;
const char * S_NAMES[SEASONS] = {
	"Spring", "Summer", "Fall", "Winter"
};

void fill(double arr[], int n);
void show(const double arr[], int n);

int main(void)
{
	double expenses[SEASONS];

	fill(expenses, SEASONS);
	show(expenses, SEASONS);

	return 0;
}

void fill(double arr[], int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter " << S_NAMES[i] << " expenses: ";	// entering expenses by seasons
		cin >> arr[i];
	}
}

void show(const double arr[], int n)
{
	using namespace std;
	double total = 0.0;
	
	cout << "\nEXPENSES\n";								// displaying expenses by seasons
	for (int i = 0; i < n; i++)
	{
		cout << S_NAMES[i] << ": $" << arr[i] << endl;
		total += arr[i];
	}

	cout << "Total Expenses: $" << total << endl;		// displaying the total sum of expenses
}
