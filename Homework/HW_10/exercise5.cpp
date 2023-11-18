// exercise5.cpp
// 
// Improvement the 'Blackjack' game (exercise3.cpp) by adding betting functionality.
// 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

// Function prototypes.
char ask_yes_no(const string & str);
int ask_number(const string & str, int low, int high);

const char YES = 'Y';
const char NO = 'N';


class Card {
public:
    enum Rank {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, 
        JACK, QUEEN, KING
    };
    enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};

    // Overload the << operator to ability of sending a Card object to cout.
    friend ostream & operator<<(ostream & os, const Card & a_card);
    Card(Rank r = ACE, Suit s = SPADES, bool ifu = true);
    // Return a card value from 1 to 11.
    int get_value() const;
    // Flip a card: a card that is face up is turned face down, and vice versa. 
    void flip();
private:
    Rank m_rank;
    Suit m_suit;
    bool m_is_face_up;
};

Card::Card(Rank r, Suit s, bool ifu): m_rank(r), m_suit(s), m_is_face_up(ifu)
{}

int Card::get_value() const
{
    // If a card is not face up, its value equals zero.
    int value = 0;

    if (m_is_face_up)
    {
        // A value is the number specified on a card.
        value = m_rank;
        // The value equals 10 for opened cards.
        if (value > 10)
        {
            value = 10;
        }
    }

    return value;
}

void Card::flip()
{
    m_is_face_up = !(m_is_face_up);
}


class Hand {
public:
    Hand();
    virtual ~Hand();
    // Copy constructor.
    Hand(const Hand & a_hand);
    // Overloaded assignment operator.
    Hand & operator=(const Hand & a_hand);
    // Add card to the hand.
    void add(Card * p_card);
    // Clear the hand from the cards.
    virtual void clear();
    // Get the sum of scores in the hand 
    // asigning an ace the value 1 or 11 depening on the situation.
    int get_total() const;
    // Get the number of all cards in a hand.
    unsigned get_number() const;
    // Max possible cards in a hand.
    // Used outside this class.
    static const int MAX_CARDS = 7;
protected:
    vector<Card *> m_cards;
};

Hand::Hand()
{
    // No more than MAX_CARDS card per hand.
    m_cards.reserve(MAX_CARDS);
}

Hand::Hand(const Hand & a_hand)
{
	for (auto pp_card = a_hand.m_cards.begin(); pp_card != a_hand.m_cards.end(); ++pp_card)
	{
		add(*pp_card);
	}
}

Hand & Hand::operator=(const Hand & a_hand)
{
	if (this != &a_hand)
	{
		clear();
		for (auto pp_card = a_hand.m_cards.begin(); pp_card != a_hand.m_cards.end(); ++pp_card)
		{
			add(*pp_card);
		}
	}

	return *this;
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
    vector<Card *>::iterator iter = m_cards.begin();
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
    bool is_end = false;

    if (m_cards.empty() || 0 == m_cards[0]->get_value())
    {
        is_end = true;
    }

    if (!is_end)
    {
        // Every ace gives 1 score in the total sum;
        vector<Card *>::const_iterator iter;
        for (iter = m_cards.begin(); iter != m_cards.end(); ++iter)
        {
            total += (*iter)->get_value();
        }
        
        // Define if the hand has an ace.
        bool contains_ace = false;
        for (iter = m_cards.begin(); iter != m_cards.end(); ++iter)
        {
            if ((*iter)->get_value() == Card::ACE)
            {
                contains_ace = true;
            }
        }
        // If the hand has an ace and some rather small, the ace gives 11 scores.
        // 1 score for an ace has already been added, take this into account.
        if (contains_ace && total <= (10 + 1))
        {
            // Add only 10 scores because 
            // 1 score has already been added for every ace.
            total += (11 - 1);
        }
    }

    return total;
}


class Generic_Player: public Hand {
    friend ostream & operator<<(ostream & os, const Generic_Player & a_generic_player);
public:
    Generic_Player(const string & name = "");
    virtual ~Generic_Player();
    // Show if the player wants to hit cards.
    virtual bool is_hitting() const = 0;
    // Return true if the player has busted.
    bool is_busted() const;
    // Declare player has busted.
    virtual void bust();
    static const int BJ_SCORE = 21;
protected:
    string m_name;
};

Generic_Player::Generic_Player(const string & name):
m_name(name)
{}

Generic_Player::~Generic_Player()
{}

bool Generic_Player::is_busted() const
{
    return (get_total() > Generic_Player::BJ_SCORE);
}

void Generic_Player::bust()
{
    cout << m_name << " busts.\n";
}


class Deck: public Hand {
public:
    Deck();
    virtual ~Deck();
    // Create a standard deck from MAX_CARDS cards.
    void populate();
    // Shuffle cards.
    void shuffle();
    // Deal one card to a hand.
    void deal(Hand & a_hand);
    // Give additional cards to a player.
    void additional_cards(Generic_Player & a_generic_player);
    const int MAX_CARDS = 52;
};

Deck::Deck()
{
    // Create a standard deck from MAX_CARDS cards.
    m_cards.reserve(MAX_CARDS);
    populate();
}

Deck::~Deck()
{}

void Deck::populate()
{
    clear();

    // Create a standard deck.
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
    {
        for (int r = Card::ACE; r <= Card::KING; ++r)
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

void Deck::additional_cards(Generic_Player & a_generic_player)
{
    cout << endl;

    // Continue dealing cards while a player busts or wants to hit.
    while (!(a_generic_player.is_busted()) && a_generic_player.is_hitting())
    {
        deal(a_generic_player);
        cout << a_generic_player << endl;
        if (a_generic_player.is_busted())
        {
            a_generic_player.bust();            
        }
    }
}


class Player: public Generic_Player {
public:
    Player(const string & name = "", float fund = 100.0);
    virtual ~Player();
    // Show if a player wants to hit cards.
    virtual bool is_hitting() const;
    virtual void clear();
    virtual void bust();
    // Declare that player wins;
    // 'factor' variable affects the size of the winnings.
    void win(double factor);
    // Declare that player lose
    // and decrease the sum of player's fund.
    void lose();
    // Declare push.
    void push() const;
    // Find out how much money a player wants to bet.
    void place_bet();
    int get_fund() const;
    const string & get_name() const;
    bool get_round_end() const;
private:
	int m_bet;
	// If a player has a blackjack immediately, 
	// he can end the round right away or wait until it ends.
	// True -- if the player won, false -- if he lost in a game round.
	bool m_round_end;
	int m_fund;
};

Player::Player(const string & name, float fund):
Generic_Player(name)
{
	m_fund = fund;
	m_bet = 0;
	m_round_end = false;
}

Player::~Player()
{}

bool Player::get_round_end() const
{
	return m_round_end;
}

int Player::get_fund() const
{
	return m_fund;
}

const string & Player::get_name() const
{
	return m_name;
}

void Player::place_bet()
{
	// Report about the player's fund.
	cout << m_name << "\'s fund is $" << m_fund << ".\n";

	// Get how much money the player wants to bet.
	int bet = ask_number("Your bet (1 - " + to_string(m_fund) + "): $", 1, m_fund);
	m_bet = bet;
}

void Player::clear()
{
	// The player returns to the beginning state of the game 
	// to the next game round.
	Hand::clear();
	m_round_end = false;
}

bool Player::is_hitting() const
{
	bool hit = false;

	if (get_total() != Generic_Player::BJ_SCORE)
	{
	    cout << m_name << ", do you want a hit? (y/n): ";
	    char response;
	    cin >> response;
	    hit = ('y' == response || 'Y' == response);
	}
	else
	{
		cout << m_name << " has Blackjack.\n";	
	}

    return hit;
}

void Player::win(double factor)
{
    int winnings = m_bet * factor;

    cout << m_name << " wins $" << winnings << ".\n";
    m_fund += winnings;

    m_round_end = true;
}

void Player::bust()
{
	Generic_Player::bust();
	lose();
}

void Player::lose()
{
    cout << m_name << " loses $" << m_bet << ".\n";
    m_fund -= m_bet;
}

void Player::push() const
{
    cout << m_name << " pushes and sticks to his bet.\n";
}


class Dealer: public Generic_Player {
public:
    Dealer(const string & name = "Dealer");
    virtual ~Dealer();
    // Show if the dealer wants to hit cards.
    virtual bool is_hitting() const;
    // Flip the first card.
    void flip_first_card();
    const int STOP_SCORE = 17;
};

Dealer::Dealer(const string & name):
Generic_Player(name)
{}

Dealer::~Dealer()
{}

bool Dealer::is_hitting() const
{
    int total = get_total();
    bool hit = (total < STOP_SCORE);
    if (Generic_Player::BJ_SCORE == total)
    {
        cout << "Dealer has Blackjack.\n";
    }

    return hit;
}

void Dealer::flip_first_card()
{
    if (!(m_cards.empty()))
    {
        m_cards[0]->flip();
    }
    else
    {
        cout << "No card to flip!\n";
    }
}


class Game {
public:
	const int MAX_DECKS = 8;
    Game(const vector<Player> & players);
    ~Game();
    // Conduct the game.
    void play();
private:
    Deck m_deck;
    Dealer m_dealer;
    vector<Player> m_players;
    // The number of decks: up to MAX_DECKS decks.
    int m_decks;
private:
    // Delete all players they haven't fund more before the next round. 
	void remove_bankrupts();
    // Clear the hands of all players and the dealer before the next game round.
    void clear_all();
    // Check if all players is busted before opening the dealer's hand.
    bool all_is_busted() const;
};

Game::Game(const vector<Player> & players):
m_players(players),
m_decks(0)
{
    // Seed the random range generator.
    srand(static_cast<unsigned>(time(0)));
    m_deck.populate();
    m_deck.shuffle();
}

Game::~Game()
{}

void Game::remove_bankrupts()
{
	for (auto p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
	{
		if (0 == p_player->get_fund())
		{
			cout << p_player->get_name() << " has no more money and leaves the gaming table.\n\n";
			// erase() method crushes placement of iterators
			// or returns the iterator to the last vector element.
			// p_player is decremented after it is passed to earse() method
			// but before erase() is executed.
			m_players.erase(p_player--);
		}
	}
}

void Game::clear_all()
{
    for (auto p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
    {
        p_player->clear();
    }
    m_dealer.clear();
}

bool Game::all_is_busted() const
{
    bool all_busts = true;
    for (auto p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
    {
        if (!p_player->is_busted())
        {
            all_busts = false;
        }
    }

    return all_busts;
}

void Game::play()
{
	// If only 1 player is left and he has blackjack.
	// At the beginning of the next round, there is no such player.
	bool only_one_and_bj = false;

	// Check if any players have no money left before the next round and remove them.
	remove_bankrupts();
	// Check if there is at least 1 player in the game.
	if (m_players.empty())
	{
		cout << "No one player has money. The game is over.\n";
		cout << "\nBye!\n";
        clear_all();

		exit(EXIT_FAILURE);
	}

	// The remaining players place their bets.
	for (auto p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
	{
		p_player->place_bet();
	}
	cout << endl;

	// Check how many cards in the deck.
	// If the number cards in the deck is less than 
	// the number of players and the dealer multiplied by max cards in a hand, 
	// populate and shuffle the deck extra. 
	if (m_deck.get_number() < ((m_players.size() + 1) * Hand::MAX_CARDS) &&
		m_decks < MAX_DECKS)
	{
		m_decks++;
		cout << "Populate and shuffle the deck...\n";
		m_deck.populate();
		m_deck.shuffle();
	}

    // Deal 2 start cards for players.
    vector<Player>::iterator p_player;
    for (int i = 0; i < 2; ++i)
    {
        for (p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
        {
            m_deck.deal(*p_player);
        }
        m_deck.deal(m_dealer);
    }
    // Hide the first card of the dealer.
    m_dealer.flip_first_card();

    // Open the hands of all players and the dealer.
    for (p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
    {
        cout << *p_player << endl;
    }
    cout << m_dealer << endl;

    // Deal additional cards for players.
    for (p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
    {
        m_deck.additional_cards(*p_player);
        if (Generic_Player::BJ_SCORE == p_player->get_total())
        {
        	char answer = ask_yes_no("Do you want to collect your winnings or "
                "wait until the end of the game? (y/n): ");
        	if (YES == answer)
        	{
        		// The player wins with a factor of 1
        		// because he took the winnings immediately.
        		p_player->win(1.0);

        		// If the only 1 player is left and he has blackjack,
        		// end the game round with initial values
        		// for the remaining player and the dealer
        		// before the next round.
        		if (m_players.size() == 1)
        		{
        			only_one_and_bj = true;
        		}
        	}
        }
    }

    // Show the dealer's hand 
    // only if there is at least 1 player in the game round 
    // and he isn't the last one left.
    if (!(only_one_and_bj) && !(all_is_busted()))
    {
	    // Show the first card of the dealer.
	    m_dealer.flip_first_card();
	    cout << endl << m_dealer;

	    m_deck.additional_cards(m_dealer);
	    if (m_dealer.is_busted())
	    {
	        // All remaining in the game wins.
	        for (p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
	        {
	            if (!(p_player->get_round_end()) && !(p_player->is_busted()))
	            {
	            	// The player wins with factor 1.5
	            	// because he waited for the end of the game round.
	                p_player->win(1.5);
	            }
	        }
	    }
	    else
	    {
	        // Compare all remaining players' the sum of scores with the dealer's one.
	        for (p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
	        {
	            if (!(p_player->get_round_end()) && !(p_player->is_busted()))
	            {
	                if (p_player->get_total() > m_dealer.get_total())
	                {
	                	// The player wins with factor 1.5
	            		// because he waited for the end of the game round.
	                    p_player->win(1.5);
	                }
	                else if (p_player->get_total() < m_dealer.get_total())
	                {
	                    p_player->lose();
	                }
	                else
	                {
	                    p_player->push();
	                }
	            }
	        }
	    }
    }

    // Before the next game round.
    clear_all();
}


// Friend function prototypes.
ostream & operator<<(ostream & os, const Card & a_card);
ostream & operator<<(ostream & os, const Generic_Player & a_generic_player);

int main(void)
{
    cout << "\t\tWelcome to Blackjack!\n\n";
    
    int num_players = 0;
    while (num_players < 1 || num_players > 7)
    {
        cout << "How many players? (1 - 7): ";
        (cin >> num_players).ignore();
    }

    string name;
    int fund;
    vector<Player> players;
    for (int i = 0; i < num_players; ++i)
    {
        cout << "Enter player name: ";
        getline(cin, name);
        cout << "Enter player fund: $";
        (cin >> fund).ignore();
        
        players.push_back(Player(name, fund)); 
    }
    cout << endl;

    // Game loop.
    Game a_game(players);
    char again;
    do
    {
        a_game.play();
        
        again = ask_yes_no("\nDo you want to play again? (Y/N): ");
    } while (again != NO);
  
    cout << "\nBye\n";

    return 0;
}

char ask_yes_no(const string & str)
{
    const string VALID_ANSWER = "YyNn";
	char choice;
	do
	{
		cout << str;
		cin >> choice;
	} while (VALID_ANSWER.find(choice) == string::npos);
    choice = toupper(choice);

	return choice;
}

int ask_number(const string & str, int low, int high)
{
    int number;
    do
    {
        cout << str;
        cin >> number;
    } while (number < low || number > high);

    return number;
}

// Overload the << operator to be able to send a Card object to the cout stream.
ostream & operator<<(ostream & os, const Card & a_card)
{
    const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    const string SUITS[] = {"c", "d", "h", "s"};

    if (a_card.m_is_face_up)
    {
        os << RANKS[a_card.m_rank] << SUITS[a_card.m_suit];
    }
    else
    {
        os << "XX";
    }

    return os;
}

// Overload the << operator to be able to send a Generic_Player object to the cout stream.
ostream & operator<<(ostream & os, const Generic_Player & a_generic_player)
{
    os << a_generic_player.m_name << ":\t";
    
    vector<Card *>::const_iterator p_card;
    if (!a_generic_player.m_cards.empty())
    {
        for (p_card = a_generic_player.m_cards.begin();
            p_card != a_generic_player.m_cards.end();
            ++p_card)
        {
            os << *(*p_card) << "\t";
        }

        if (a_generic_player.get_total() != 0)
        {
            cout << "(" << a_generic_player.get_total() << ")";
        }
    }
    else
    {
        os << "<empty>";
    }

    return os;
}
