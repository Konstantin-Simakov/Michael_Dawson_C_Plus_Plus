// exercise4.cpp
// 
// "Televisor" program.
// The program imitates the TV as an object.
// User can enter a channel and increase/reduce the volume.
// 
#include <iostream>
#include <string>
using namespace std;

const int MAX_CHANNEL = 100;
const int MAX_VOLUME = 10;

class Televisor {
public:
	Televisor(int channel = 1, int volume = (MAX_VOLUME / 2));
	void menu() const;
	// Tells about channel number and current volume level.
	void info() const;
	void select_channel();
	void volume_up();
	void volume_down();
private:
	int m_channel;
	int m_volume;
};

int main(void)
{
	cout << "\t\tWelcome to the TV imitataion program.!\n\n";
	cout << "\t\tChannels: 1 - " << MAX_CHANNEL << endl;
	cout << "\t\tVolume levels: 1 - " << MAX_VOLUME << "\n\n";

	// Set tv with default arguments.
	Televisor tv;
	tv.info();

	int choice;
	do
	{
		tv.menu();
		cout << "Your choice: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
			case 0:
				cout << "Good-bye.\n";
				break;
			case 1:
				tv.info();
				break;
			case 2:
				tv.select_channel();
				break;
			case 3:
				tv.volume_up();
				break;
			case 4:
				tv.volume_down();
				break;
			default:
				cout << "Sorry, there is no item " << choice << " in the menu.\n";
		}
	} while (choice != 0);

	return 0;
}

Televisor::Televisor(int channel, int volume):
m_channel(channel),
m_volume(volume)
{

}

void Televisor::menu() const
{
	cout << endl;
	cout << "\t\t0 - Quit\n"
		 << "\t\t1 - Display status\n"
		 << "\t\t2 - Select channel number\n"
		 << "\t\t3 - Up volume level\n"
		 << "\t\t4 - Down volume level\n";
	cout << endl;
}

void Televisor::info() const
{
	cout << endl;
	cout << "Your channel: " << m_channel << endl;
	cout << "Your volume: " << m_volume << "\n\n";
}

void Televisor::select_channel()
{
	cout << "Enter a channel number: ";
	int channel;
	cin >> channel;
	while (channel < 1 || channel > MAX_CHANNEL)
	{
		cout << "Incorrect channel number has been entered. Try again.\n";
		cout << "Enter a channel number: ";
		cin >> channel;
	}

	cout << "Ok...\n";
	m_channel = channel;
}

void Televisor::volume_up()
{
	++m_volume;
	if (m_volume > MAX_VOLUME)
	{
		m_volume = MAX_VOLUME;
	}
	cout << "Ok.\n";
}

void Televisor::volume_down()
{
	--m_volume;
	if (m_volume < 0)
	{
		m_volume = 0;
	}
	cout << "Ok.\n";
}
