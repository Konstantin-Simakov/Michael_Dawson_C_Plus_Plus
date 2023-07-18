// exercise8.cpp
// The program imitates a calendar for one month 
// on the screen with input of strings.

#include <iostream>
#include <string>
#include <iomanip>		// For setw() manipulator
using namespace std;

const int DAYS_PER_WEEK = 7;
const int MONTHS = 12;

const string MONTH_NAMES[MONTHS] = {
	"January", "February", "March", "April", "May", "June", 
	"July", "August", "September", "October", "November", "December"
};
const string WEEK_NAMES[DAYS_PER_WEEK] = {
	"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
};
const int MONTH_DAYS[MONTHS] = {
	31, 28, 31, 30, 31, 30, 
	31, 31, 30, 31, 30, 31
};

void input(string & month, string & day_week);
void setting(const string &, const string &, int &, int &);
void output(int month, int first_day_week);

int main(void)
{
	string name_month;
	string name_first_day_week;
	int num_month;
	int first_day_week;

	input(name_month, name_first_day_week);
	setting(name_month, name_first_day_week, num_month, first_day_week);
	output(num_month, first_day_week);

	return 0;
}

void input(string & month, string & day_week)
{
	cout << "Enter a name of month: ";
	cin >> month;

	cout << "Enter a name of the first day week: ";
	cin >> day_week;
}

void setting(const string & month, const string & day_week, int & m, int & f)
{
	// Setting the number of month
	for (int i = 0; i < MONTHS; ++i)
	{
		if (MONTH_NAMES[i] == month)
		{
			m = i + 1;
			break;
		}
	}

	// Setting the number of first day week
	for (int i = 0; i < DAYS_PER_WEEK; ++i)
	{
		if (WEEK_NAMES[i] == day_week)
		{
			f = i + 1;
			break;
		}
	}
}

void output(int num_month, int first_day_week)
{
	const string TWO_SPACES = "  ";

	// Month name
	cout << endl;
	cout << setw(13) << MONTH_NAMES[num_month - 1] << "\n\n";
	
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
