// exercise5.cpp
// 
// "Time" program.
// Imitates counter of Moscow time on the screen.
// 
#include <iostream>
// For setfill(), setw() manipulators.
#include <iomanip>
#include <thread>
#include <chrono>
// For exit(), EXIT_FAILURE
#include <cstdlib>
using namespace std;

class Time {
public:
	const int SECS_PER_MIN = 60;
	const int MINS_PER_HOUR = 60;
	const int HOURS_PER_DAY = 24;
	Time(int hours = 0, int mins = 0, int secs = 0);
	void times();
private:
	int m_hour;
	int m_min;
	int m_sec;
	void display();
};


int main(void)
{
	Time tm(23, 59, 50);
	tm.times();

	return 0;
}

Time::Time(int hours, int mins, int secs):
m_hour(hours),
m_min(mins),
m_sec(secs)
{
	if (m_hour < 0 || m_hour >= HOURS_PER_DAY)
	{
		cout << "Unpermissible number of hours is entered: the program is finished.\n";
		exit(EXIT_FAILURE);
	}
	if (m_min < 0 || m_min >= MINS_PER_HOUR)
	{
		cout << "Unpermissible number of minutes is entered: the program is finished.\n";
		exit(EXIT_FAILURE);
	}
	if (m_sec < 0 || m_sec >= SECS_PER_MIN)
	{
		cout << "Unpermissible number of seconds is entered: the program is finished.\n";
		exit(EXIT_FAILURE);
	}
}

void Time::times(void)
{
	while (true)
	{
		++m_sec;
		if (SECS_PER_MIN == m_sec)
		{
			m_sec = 0;
			++m_min;

			if (MINS_PER_HOUR == m_min)
			{
				m_min = 0;
				++m_hour;

				if (HOURS_PER_DAY == m_hour)
				{
					m_hour = 0;
				}
			}
		}
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000000000));
		display();
	}
}

void Time::display()
{
	cout << "\n\n\n\n\n\n\n";
	cout << "\t\t\t\t  Moscow time\n\n";
	cout << "\t\t\t\t  " 
		 << setfill('0') << setw(2) << m_hour << ":"
		 << setfill('0') << setw(2) << m_min << ":"
		 << setfill('0') << setw(2) << m_sec << endl;
	cout << "\n\n\n\n\n\n\n\n\n";
}
