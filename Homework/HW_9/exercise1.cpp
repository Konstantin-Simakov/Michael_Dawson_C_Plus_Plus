// exercise1.cpp
// 
// Improvement of the 'Lobby' game (game_lobby.cpp).
// Redefined operator<<() for the Lobby class,
// with using an added operator<<() for the Player class.
// Also, effective is increased for the Lobby::add_player() 
// with changing of main program data structure from queue to deque.
// 
#include <iostream>
#include <string>
using namespace std;

class Player {
	friend ostream & operator<<(ostream & os, const Player & a_player);
public:
	Player(const string & name = "");
	Player * get_next() const;
	void set_next(Player * next);
private:
	string m_name;
	// Pointer to the next player in the list.
	Player * m_p_next;
};

Player::Player(const string & name):
m_name(name),
m_p_next(NULL)
{}

Player * Player::get_next() const
{
	return m_p_next;
}

void Player::set_next(Player * next)
{
	m_p_next = next;
}

ostream & operator<<(ostream & os, const Player & a_player)
{
	os << a_player.m_name << endl;

	return os;
}

class Lobby {
	friend ostream & operator<<(ostream & os, const Lobby & a_lobby);
public:
	Lobby();
	~Lobby();
	void add_player();
	void remove_player();
	void clear();
private:
	Player * m_p_head;
	Player * m_p_tail;
};

Lobby::Lobby():
m_p_head(NULL),
m_p_tail(NULL)
{}

Lobby::~Lobby()
{
	clear();
}

void Lobby::add_player()
{
	// Create a new player.
	cout << "Please enter the name of the new player: ";
	string name;
	getline(cin, name);
	Player * p_new_player = new Player(name);

	// If the list is emtpy, place to its beginning (ending) the new player.
	if (NULL == m_p_head)
	{
		m_p_head = m_p_tail = p_new_player;
	}
	// Else find its ending by the tail element of the list and add the player there.
	else
	{
		m_p_tail->set_next(p_new_player);
		m_p_tail = p_new_player;
	}
}

void Lobby::remove_player()
{
	if (NULL == m_p_head)
	{
		cout << "The game lobby is empty. No one to remove!\n";
	}
	else
	{
		Player * p_temp = m_p_head;
		m_p_head = m_p_head->get_next();
		
		// If the list has become an empty, 
		// set all remaining data members to their initial values.
		if (NULL == m_p_head)
		{
			m_p_tail = NULL;
		}
		
		delete p_temp;
	}
}

void Lobby::clear()
{
	while (m_p_head != NULL)
	{
		remove_player();
	}
}

ostream & operator<<(ostream & os, const Lobby & a_lobby)
{
	Player * p_iter = a_lobby.m_p_head;

	os << "\nHere\'s who\'s in the game lobby:\n";
	if (NULL == p_iter)
	{
		os << "The lobby is empty.\n";
	}
	else
	{
		while (p_iter != NULL)
		{
			os << *p_iter;
			p_iter = p_iter->get_next();
		}
	}

	return os;
}

int main(void)
{
	Lobby my_lobby;
	
	int choice;
	do
	{
		cout << my_lobby;
		cout << "\nGame LOBBY\n";
		cout << "0 - Exit the program.\n";
		cout << "1 - Add a player to the lobby.\n";
		cout << "2 - Remove a player from the lobby.\n";
		cout << "3 - Clear the lobby.\n";

		cout << "\nEnter choice: ";
		(cin >> choice).get();
		switch (choice)
		{
			case 0:
				cout << "Good-bye!\n";
				break;
			case 1:
				my_lobby.add_player();
				break;
			case 2:
				my_lobby.remove_player();
				break;
			case 3:
				my_lobby.clear();
				break;
			default:
				cout << "That was not a valid choice.\n";			
		}
	} while (choice != 0);

	return 0;
}
