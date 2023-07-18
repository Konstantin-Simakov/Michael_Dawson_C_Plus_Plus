// exercise7.cpp
// The program imitates a calendar for one month 
// on the screen with input of integers.

#include <iostream>
#include <string>
#include <iomanip>		// For setw() manipulator
using namespace std;

const int MONTHS = 12;
const string MONTH_NAMES[MONTHS] = {
	"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
	"Jul", "Aug", "Sep", "Oct", "Nov", "Dev"
};
const int MONTH_DAYS[MONTHS] = {
	31, 28, 31, 30, 31, 30, 
	31, 31, 30, 31, 30, 31
};
const int DAYS_PER_WEEK = 7;

void input(int & month, int & first_day_week);
void output(int month, int first_day_week);

int main(void)
{
	int num_month;
	int first_day_week;

	input(num_month, first_day_week);
	output(num_month, first_day_week);

	return 0;
}

void input(int & month, int & first_day_week)
{
	cout << "Enter a number of month: ";
	cin >> month;

	cout << "Enter a number of the month first day: ";
	cin >> first_day_week;
}

void output(int num_month, int first_day_week)
{
	const string TWO_SPACES = "  ";

	// Month name
	cout << endl;
	cout << setw(12) << MONTH_NAMES[num_month - 1] << "\n\n";
	
	// Spaces loop
	for (int i = 1; i < first_day_week; i++)
	{
		cout << setw(3) << TWO_SPACES;
	}
	
	// Values loop	
	int cur_day_week = first_day_week;
	for (int month_day = 1; month_day <= MONTH_DAYS[num_month - 1]; 
		++month_day, ++cur_day_week)
	{
		cout << setw(3) << month_day;
		if (cur_day_week % DAYS_PER_WEEK == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}
