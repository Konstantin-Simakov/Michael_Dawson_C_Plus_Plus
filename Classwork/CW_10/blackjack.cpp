// blackjack.cpp
// 
// 'Blackjack' game.
// The simple version of the game; from 1 to 7 players.
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
    // Add card to the hand.
    void add(Card * p_card);
    // Clear the hand from the cards.
    void clear();
    // Get the sum of scores on the hand 
    // asigning an ace the value 1 or 11 depening on the situation.
    int get_total() const;
protected:
    vector<Card *> m_cards;
};

Hand::Hand()
{
    // No more than 7 card per hand.
    m_cards.reserve(7);
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
    void bust() const;
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
    return (get_total() > 21);
}

void Generic_Player::bust() const
{
    cout << m_name << " busts.\n";
}


class Player: public Generic_Player {
public:
    Player(const string & name = "");
    virtual ~Player();
    // Show if a player wants to hit cards.
    virtual bool is_hitting() const;
    // Declare that player wins.
    void win() const;
    // Declare that player lose.
    void lose() const;
    // Declare push.
    void push() const;
};

Player::Player(const string & name):
Generic_Player(name)
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


class Dealer: public Generic_Player {
public:
    Dealer(const string & name = "Dealer");
    virtual ~Dealer();
    // Show if the dealer wants to hit cards.
    virtual bool is_hitting() const;
    // Flip the first card.
    void flip_first_card();
};

Dealer::Dealer(const string & name):
Generic_Player(name)
{}

Dealer::~Dealer()
{}

bool Dealer::is_hitting() const
{
    return (get_total() < 17);
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
    void additional_cards(Generic_Player & a_generic_player);
};

Deck::Deck()
{
    // Create a standard deck from 52 cards.
    m_cards.reserve(52);
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


class Game {
public:
    Game(const vector<string> & names);
    ~Game();
    // Conduct the game.
    void play();
private:
    Deck m_deck;
    Dealer m_dealer;
    vector<Player> m_players;
};

Game::Game(const vector<string> & names)
{
    // Create a vector of players from the vector of names.
    vector<string>::const_iterator p_name;
    for (p_name = names.begin(); p_name != names.end(); ++p_name)
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

void Game::play()
{
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
    }

    // Show the first card of the dealer.
    m_dealer.flip_first_card();
    cout << endl << m_dealer;

    // Deal additional cards for the dealer.
    m_deck.additional_cards(m_dealer);
    if (m_dealer.is_busted())
    {
        // All remaining in the game wins.
        for (p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
        {
            if (!(p_player->is_busted()))
            {
                p_player->win();
            }
        }
    }
    else
    {
        // Compare all remaining players' the sum of scores with the dealer's one.
        for (p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
        {
            if (!(p_player->is_busted()))
            {
                if (p_player->get_total() > m_dealer.get_total())
                {
                    p_player->win();
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

    // Clear the hands of all players.
    for (p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
    {
        p_player->clear();
    }
    m_dealer.clear();
}


// Function prototypes.
ostream & operator<<(ostream & os, const Card & a_card);
ostream & operator<<(ostream & os, const Generic_Player & a_generic_player);

int main(void)
{
    cout << "\t\tWelcome to Blackjack!\n\n";
    
    int num_players = 0;
    while (num_players < 1 || num_players > 7)
    {
        cout << "How many players? (1 - 7): ";
        cin >> num_players;
    }

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
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        a_game.play();
        
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }

    return 0;
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
