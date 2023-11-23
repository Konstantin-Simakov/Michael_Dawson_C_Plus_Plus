// exercise6.cpp
// 
// 'Robot' game.
// A simple object-oriented game in which 
// the player can change their location 
// by moving to one of the places closest to the current one.
// Allowed moves: up, low, right, left.
// Illegal moves are diagonal.
// Range of the board size is from 2x2 to 10x10.
// 
#include <iostream>
// For setw(), setfill() manipulators.
#include <iomanip>
// For stoi() function.
#include <string>
#include <vector>
// For find() algorithm.
#include <algorithm>
// For std::invalid_argument exception.
#include <stdexcept>
// For exti(), EXIT_FAILURE, abort().
#include <cstdlib>
using namespace std;

const char SPACE = ' ';
const string QUIT = "QUIT";

// Free function prototypes.
void init_range(vector<int> & a_range, int low, int high, int step);
int ask_number(const string & str, int low, int high);
void display_instruct(int size);
void str_to_upper(string & str);


class Board;
// The player is a piece on the board (asterisk by default). 
class Player {
public:
    Player(int location = 0, char piece = '*');
    // 'size' is a size of one board side. 
    int make_move(int position, int size);
    int get_location() const;
    bool set_location(const Board & a_board, int position = 0);
    char get_piece() const;
private:
    int m_location;
    char m_piece;
private:
    // Use in make_move() function.
    // Define legal moves for a player and write it to the 'legals' vector.
    void legal_moves(vector<int> & legals, int size);
};

class Player;
// A board for a player.
class Board {
    friend ostream & operator<<(ostream & os, const Board & a_board);
public:
    Board(int size, const Player & a_player);
    // Change the player's piece location by the specified position.
    bool change_piece_location(Player & a_player, int position);
    int get_size() const;
private:
    // 'm_size' is the number of cells on one side of the board.
    int m_size;
    vector<char> m_board;
};

Player::Player(int location, char piece):
m_location(location),
m_piece(piece)
{}

int Player::make_move(int position, int size)
{
    // The collection of legal moves depending on the current piece location.
    vector<int> legals;
    // Initialize the 'legals' vector.
    legal_moves(legals, size);

    // While the 'position' element doesn't consist in the vector.
    while (find(legals.begin(), legals.end(), position) == legals.end())
    {
        position = ask_number("You cannot move to this position. Your move (0 - " +
            to_string((size * size) - 1) + "): ", 0, (size * size) - 1);
    }

    return position;
}

int Player::get_location() const
{
    return m_location;
}

char Player::get_piece() const
{
    return m_piece;
}

bool Player::set_location(const Board & a_board, int position)
{
    bool success = false;

    if (position >= 0 && position < (a_board.get_size() * a_board.get_size()))
    {
        m_location = position;
        success = true;
    }

    return success;
}

void Player::legal_moves(vector<int> & legals, int size)
{

    // 1. When we can make only 2 moves.
    // Upper left corner:
    if (0 == get_location())
    {
        legals.insert(legals.begin(), {get_location() + 1, get_location() + size});
    }
    // Upper right corner:
    else if ((size - 1) == get_location())
    {
        legals.insert(legals.begin(), {get_location() - 1, get_location() + size});
    }
    // Lower left corner:
    else if ((size * size) - size == get_location())
    {
        legals.insert(legals.begin(), {get_location() + 1, get_location() - size});
    }
    // Lower right corner:
    else if ((size * size) - 1 == get_location())
    {
        legals.insert(legals.begin(), {get_location() - 1, get_location() - size});
    }
    else
    {        
        // Vector of potential next positions depending on the current piece location.
        vector<int> next_pos;
        // 2. When we can make 3 moves.
        // Upper side: [1; size - 2] with step = 1.
        init_range(next_pos, 1, size - 2, 1);
        if (find(next_pos.begin(), next_pos.end(), get_location()) != next_pos.end())
        {
            legals.insert(legals.begin(), {get_location() + 1, get_location() - 1, get_location() + size});
        }
        // Lower side: [(size * size) - (size - 1); (size * size) - 2] with step = 1.
        next_pos.clear();
        init_range(next_pos, (size * size) - (size - 1), (size * size) - 2, 1);
        if (find(next_pos.begin(), next_pos.end(), get_location()) != next_pos.end())
        {
            legals.insert(legals.begin(), {get_location() + 1, get_location() - 1, get_location() - size});
        }
        // Left side: [size; (size * size) - (2 * size)] with step = size.
        next_pos.clear();
        init_range(next_pos, size, (size * size) - (2 * size), size);
        if (find(next_pos.begin(), next_pos.end(), get_location()) != next_pos.end())
        {
            legals.insert(legals.begin(), {get_location() + 1, get_location() + size, get_location() - size});
        }
        // Right side: [(2 * size) - 1; (size * size) - size - 1] with step = size.
        next_pos.clear();
        init_range(next_pos, (2 * size) - 1, (size * size) - size - 1, size);
        if (find(next_pos.begin(), next_pos.end(), get_location()) != next_pos.end())
        {
            legals.insert(legals.begin(), {get_location() - 1, get_location() + size, get_location() - size});
        }

        // 3. When we can make all 4 moves.
        else
        {
            legals.insert(legals.begin(), {get_location() + 1, get_location() - 1, get_location() + size, get_location() - size});
        }
    }

}

Board::Board(int size, const Player & a_player):
m_size(size)
{
    m_board.reserve(size * size);
    // Create an empty board.
    for (int i = 0; i < size * size; ++i)
    {
        m_board.push_back(SPACE);
    }

    // Set the player's piece to the position he chooses.
    m_board[a_player.get_location()] = a_player.get_piece();
}

int Board::get_size() const
{
    return m_size;
}

bool Board::change_piece_location(Player & a_player, int position)
{
    bool success = false;
    
    position = a_player.make_move(position, m_size);
    if (position >= 0 && position < (m_size * m_size))
    {
        m_board[position] = a_player.get_piece();
        m_board[a_player.get_location()] = SPACE;
        if (a_player.set_location(*this, position))
        {
            success = true;
        }
    }

    return success;
}


// Friend funciton prototypes.
// ostream & operator<<(ostream & os, const Board & a_board);

// Main program.
int main(void)
{
    // Greeting and incstructions.
    cout << "\tWelcome to the \'Robot\' game.\n\n\n";
    int size = ask_number("Enter a size of one board side (2 - 10): ", 2, 10);
    display_instruct(size);

    // Start the game.
    int start_pos = ask_number("Enter a start location of your piece (0 - " + 
        to_string((size * size) - 1) + "): ", 0, (size * size) - 1);
    Player a_player(start_pos);
    Board a_board(size, a_player);
    cout << a_board << endl;
    
    cout << "\nYou may enter \'" << QUIT << "\' to finish the game.\n\n";
    cout << "Enter the next position you want to be in (0 - " + 
        to_string((size * size) - 1) + "): ";    
    string s_next_pos;
    cin >> s_next_pos;
    str_to_upper(s_next_pos);
    while (s_next_pos != QUIT)
    {
        int next_pos;
        try
        {
            next_pos = stoi(s_next_pos);
        }
        catch (const std::invalid_argument & ex)
        {
            cout << "Invalid argument: " << ex.what() << endl;
            abort();
        }

        if (!a_board.change_piece_location(a_player, next_pos))
        {
            cout << "Failed to change piece location. The program terminated.\n";
            exit(EXIT_FAILURE);
        }
        cout << a_board << endl;

        cout << "Enter the next position you want to be in (0 - " + 
            to_string((size * size) - 1) + "): ";    
        cin >> s_next_pos;
        str_to_upper(s_next_pos);
    }
    cout << "\nBye!\n";

    return 0;
}

void str_to_upper(string & str)
{
    for (unsigned i = 0; i < str.size(); ++i)
    {
        str[i] = toupper(str[i]);
    }
}

// Display the game instructions.
void display_instruct(int size)
{
    cout << "This is a board on which you can make moves with numbers from 0 to " 
         << (size * size) - 1 << " as specified below.\n";

    cout << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << "\t\t";
        for (int j = 0; j < size; ++j)
        {
            cout << "-----";
        }
        cout << endl;

        cout << "\t\t";
        for (int j = 0; j < size; ++j)
        {
            cout << "|" << setfill(SPACE) << setw(3) << (i * size + j) << SPACE;  
        }
        cout << "|\n";
    }

    cout << "\t\t";
    for (int j = 0; j < size; ++j)
    {
        cout << "-----";
    }
    cout << "\n\n";
}

void init_range(vector<int> & range, int low, int high, int step)
{
    for (int i = low; i <= high; i += step)
    {
        range.push_back(i);
    }
}

int ask_number(const string & str, int low, int high)
{
    int number;
    do
    {
        cout << str;
        while ((cin >> number).fail())
        {
            cout << "Incorrect data input. Your number: ";
            cin.clear();
            while (cin.get() != '\n')
            {
                continue;
            }
        }
    } while (number < low || number > high);

    // Discard the remaining input line.
    while (cin.get() != '\n')
    {
        continue;
    }

    return number;
}

ostream & operator<<(ostream & os, const Board & a_board)
{
    os << endl;
    for (int i = 0; i < a_board.m_size; ++i)
    {
        os << "\t\t";
        for (int j = 0; j < a_board.m_size; ++j)
        {
            os << "-----";
        }
        os << endl;

        os << "\t\t";
        for (int j = 0; j < a_board.m_size; ++j)
        {
            os << "|" << setfill(SPACE) << setw(3) << a_board.m_board[i * a_board.m_size + j] << SPACE;
        }
        os << "|\n";
    }

    os << "\t\t";
    for (int j = 0; j < a_board.m_size; ++j)
    {
        os << "-----";
    }
    os << "\n\n";

    return os;
}
