// exercise4.cpp
// 
// 'War' game ('GW', 'Game War').
// Every player takes one card from the full deck of 52 cards.
// Winner is who has the biggest rank of his card.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;


class Card {
public:
    enum Rank {
        TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, 
        JACK, QUEEN, KING, ACE
    };
    enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};

    // Overload the << operator to ability of sending a Card object to cout.
    friend ostream & operator<<(ostream & os, const Card & a_card);
    Card(Rank r = ACE, Suit s = SPADES);
    // Return a card value from 2 to 14.
    int get_value() const;
private:
    Rank m_rank;
    Suit m_suit;
};

Card::Card(Rank r, Suit s): m_rank(r), m_suit(s)
{}

int Card::get_value() const
{
	return m_rank;
}


class Hand {
public:
    Hand();
    virtual ~Hand();
    // Add card to the hand.
    void add(Card * p_card);
    // Clear the hand from the cards.
    void clear();
    // Get the sum of scores in the hand.
    int get_total() const;
    // Get the number of all cards in a hand.
    unsigned get_number() const;
    // Max possible cards in a hand.
    // Used outside this class.
    static const int MAX_CARDS = 1;
protected:
    vector<Card *> m_cards;
};

Hand::Hand()
{
    // No more than MAX_CARDS card per hand.
    m_cards.reserve(MAX_CARDS);
}

Hand::~Hand()
{
    clear();
}

void Hand::add(Card * p_card)
{
    m_cards.push_back(p_card);
}

void Hand::clear()
{
    // Iterates through the vector, freeing all memory on the heap.
    vector<Card *>::iterator iter;
    for (iter = m_cards.begin(); iter != m_cards.end(); ++iter)
    {
        delete *iter;
        *iter = NULL;
    }
    // Clear the vector of pointers.
    m_cards.clear();
}

unsigned Hand::get_number() const
{
	return m_cards.size();
}

int Hand::get_total() const
{
    int total = 0;

    if (!m_cards.empty())
    {
        vector<Card *>::const_iterator iter;
        for (iter = m_cards.begin(); iter != m_cards.end(); ++iter)
        {
            total += (*iter)->get_value();
        }        
    }

    return total;
}


class Player: public Hand {
    // Overload the << operator to ability of sending a Hand object inherited from one to cout.
    friend ostream & operator<<(ostream & os, const Player & a_player);
public:
	Player(const string & name = "");
	virtual ~Player();
	void win() const;
	void lose() const;
	void push() const;
	bool is_hitting() const;
private:
	string m_name;
};

Player::Player(const string & name):
m_name(name)
{}

Player::~Player()
{}

bool Player::is_hitting() const
{
    cout << m_name << ", do you want a hit? (y/n): ";
    char response;
    cin >> response;

    return ('y' == response || 'Y' == response);
}

void Player::win() const
{
    cout << m_name << " wins.\n";
}

void Player::lose() const
{
	cout << m_name << " loses.\n";
}

void Player::push() const
{
	cout << m_name << " pushes.\n";
}


class Deck: public Hand {
public:
    Deck();
    virtual ~Deck();
    // Create a standard deck from 52 cards.
    void populate();
    // Shuffle cards.
    void shuffle();
    // Deal one card to a hand.
    void deal(Hand & a_hand);
    // Give additional cards to a player.
    void additional_cards(Player & a_player);
    // The number of cards in one deck.
    static const int MAX_CARDS = 52;
};

Deck::Deck()
{
    // Create a standard deck from MAX_CARDS cards.
    m_cards.reserve(Deck::MAX_CARDS);
    populate();
}

Deck::~Deck()
{}

void Deck::populate()
{
    // Create a standard deck and add it to existed one.
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
    {
        for (int r = Card::TWO; r <= Card::ACE; ++r)
        {
            add(new Card(static_cast<Card::Rank>(r), static_cast<Card::Suit>(s)));
        }
    }
}

void Deck::shuffle()
{
    random_shuffle(m_cards.begin(), m_cards.end());
}

void Deck::deal(Hand & a_hand)
{
    if (!m_cards.empty())
    {
        a_hand.add(m_cards.back());
        m_cards.pop_back();
    }
    else
    {
        cout << "Out of cards. Unable to deal.\n";
    }
}

void Deck::additional_cards(Player & a_player)
{
    cout << endl;

    // Continue dealing cards while a player busts or wants to hit.
    while (a_player.is_hitting())
    {
        deal(a_player);
        cout << a_player << endl;
    }
}


class Game {
public:
	const int MAX_DECKS = 8;
	Game(const vector<string> & names);
	~Game();
	// Conduct the game.
	void play();
private:
	Deck m_deck;
	vector <Player> m_players;
	int m_decks;
private:
	void winners();
};

Game::Game(const vector<string> & names):
m_decks(0)
{
	// Create a vector of players from the vector of names.
	for (auto p_name = names.begin(); p_name != names.end(); ++p_name)
	{
		m_players.push_back(Player(*p_name));
	}

	// Seed the random range generator.
	srand(static_cast<unsigned>(time(0)));
	m_deck.populate();
	m_deck.shuffle();
}

Game::~Game()
{}

void Game::winners()
{
	// May be more than one winner.
	// The vector of pointers is needed 
	// to prevent calling the destructor more than 1 time for the same data.
	vector<Player *> p_win_players;

	// Determine the max score.
	int max_score = 0;
	for (auto p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
	{
		if (max_score < p_player->get_total())
		{
			max_score = p_player->get_total();
		}
	}

	// Determine players who has the max score.
	for (auto p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
	{
		if (max_score == p_player->get_total())
		{
			p_win_players.push_back(&(*p_player));
		}
	}

	// Display the winners.
	for (auto pp_winner = p_win_players.begin(); pp_winner != p_win_players.end(); ++pp_winner)
	{
		(*pp_winner)->win();
	}
}

void Game::play()
{
	// Check how many cards in the deck.
	// If the number cards in the deck is less than 
	// the number of players multiplied by max cards in a hand, 
	// populate and shuffle the deck extra. 
	if (m_deck.get_number() < (m_players.size() * Hand::MAX_CARDS) &&
		m_decks < MAX_DECKS)
	{
		m_decks++;
		cout << "Populate and shuffle the deck...\n";
		m_deck.populate();
		m_deck.shuffle();
	}

	// Deal MAX_CARDS card(s) to each player's hand.
	// (In this case 1 card is dealt to each player's hand.)
	for (int i = 0; i < Hand::MAX_CARDS; ++i)
	{
		for (auto p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
		{
			m_deck.deal(*p_player);
		}
	}

	// Display info about each player.
	for (auto p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
	{
		cout << *p_player << endl;
	}

	// Determine and display winners.
	winners();

	// Clear the hands of players.
	for (auto p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
	{
		p_player->clear();
	}
}


ostream & operator<<(ostream & os, const Card & a_card);
ostream & operator<<(ostream & os, const Player & a_player);

int main(void)
{
	cout << "\t\tWelcome to the \'War\' card game!\n\n";

	const int MIN_PLAYERS = 2;
	const int MAX_PLAYERS = Deck::MAX_CARDS;
	int num_players;
	do
	{
		cout << "How many players total? (" << MIN_PLAYERS << " - " << MAX_PLAYERS << "): ";
		cin >> num_players;
	} while (num_players < MIN_PLAYERS || num_players > MAX_PLAYERS);

	vector<string> names;
	string name;
	for (int i = 0; i < num_players; ++i)
	{
		cout << "Enter player name: ";
		cin >> name;

		names.push_back(name);
	}
	cout << endl;

	// Game loop.
	Game a_game(names);
	char again;
	do
	{
		a_game.play();

		cout << "Do you want to play again? (Y/N): ";
		cin >> again;
	} while (again != 'n' && again != 'N');

	cout << "\nBye!\n";

	return 0;
}

// Overload the << operator to be able to send a Card object to the cout stream.
ostream & operator<<(ostream & os, const Card & a_card)
{
    const string RANKS[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    const string SUITS[] = {"c", "d", "h", "s"};

    os << RANKS[a_card.m_rank - Card::TWO] << SUITS[a_card.m_suit];

    return os;
}

// Overload the << operator to ability of sending a Hand object inherited from one to cout.
ostream & operator<<(ostream & os, const Player & a_player)
{
	os << a_player.m_name << ":\t";
    
    vector<Card *>::const_iterator p_card;
    if (!a_player.m_cards.empty())
    {
        for (p_card = a_player.m_cards.begin();
            p_card != a_player.m_cards.end();
            ++p_card)
        {
            os << *(*p_card) << "\t";
        }

        if (a_player.get_total() != 0)
        {
            cout << "(" << a_player.get_total() << ")";
        }
    }
    else
    {
        os << "<empty>";
    }

    return os;
}
