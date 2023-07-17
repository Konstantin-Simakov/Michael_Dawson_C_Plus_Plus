// tic-tac-toe.cpp
// Coputer plays "tic-tac-toe" againt a user.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

void instructions(void);
char ask_yes_no(string question);
int ask_number(string question, int high, int low = 0);
char human_piece(void);
char opponent(char piece);
void display_board(const vector<char> & board);
char winner(const vector<char> & board);
inline bool is_legal(const vector<char> & board, int move);
int human_move(const vector<char> & board, char human);
int computer_move(vector<char> board, char computer);
void announce_winner(char winner, char computer, char human);

int main(void)
{
	int move;
	const int NUM_SQUARES = 9;
	vector<char> board(NUM_SQUARES, EMPTY);
	char human = human_piece();
	char computer = opponent(human);
	char turn = X;

	instructions();
	display_board(board);

	while (winner(board) == NO_ONE)
	{
		if (turn == human)
		{
			move = human_move(board, human);
			board[move] = human;
		}
		else
		{
			move = computer_move(board, computer);
			board[move] = computer;
		}

		display_board(board);
		turn = opponent(turn);
	}
	announce_winner(winner(board), computer, human);

	return 0;
}

void instructions(void)
{
	cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe.\n"
		 << "--where human brain is pit against silicon processor\n\n";
	cout << "Make your move known by entering a number 0-8. "
		 << "The number corresponds to the desired board position, as illustrated:\n\n";
	cout << "\t0 | 1 | 2\n"
		 << "\t---------\n"
		 << "\t3 | 4 | 5\n"
		 << "\t---------\n"
		 << "\t6 | 7 | 8\n\n";
	cout << "Prepare yourself, human. The battle is about to begin.\n\n";
}

char ask_yes_no(string question)
{
	char response;

	do
	{
		cout << question << " (y/n): ";
		cin >> response;
	} while (response != 'y' && response != 'n');

	return response;
}

int ask_number(string question, int high, int low)
{
	int number;

	do
	{
		cout << question << " (" << low << " - " << high << "): ";
		cin >> number;
	} while (number > high || number < low);

	return number;
}

char human_piece(void)
{
	char go_first = ask_yes_no("Do you require the first move?");
	char human_move;

	if ('y' == go_first)
	{
		cout << "\nThen take the first move. You will need it.\n";
		human_move = X;
	}
	else
	{
		cout << "\nYour bravery will be your undoing... I will go first.\n";
		human_move = O;
	}

	return human_move;
}

char opponent(char piece)
{
	char opponent_move;

	if (X == piece)
	{
		opponent_move = O;
	}
	else
	{
		opponent_move = X;
	}

	return opponent_move;
}

void display_board(const vector<char> & board)
{	
	cout << endl;
	cout << "\t" << board[0] << " | " << board[1] << " | " << board[2] << endl;
	cout << "\t" << "---------" << endl;
	cout << "\t" << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "\t" << "---------" << endl;
	cout << "\t" << board[6] << " | " << board[7] << " | " << board[8] << endl;
	cout << endl;
}

char winner(const vector<char> & board)
{
	// All possible winning rows
	const int WINNING_ROWS[8][3] = {
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		{0, 3, 6},
		{1, 4, 7},
		{2, 5, 8},
		{0, 4, 8},
		{2, 4, 6},
	};
	const int TOTAL_ROWS = 8;
	bool game_end = false;
	char winner_chip;

	// If there are three identical values in one of the possible winning rows 
	// (and they are not equal to empty), then the winner is determined.
	for (int row = 0; row < TOTAL_ROWS; ++row)
	{
		if (board[WINNING_ROWS[row][0]] != EMPTY &&
			board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]] &&
			board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]])
		{
			winner_chip = board[WINNING_ROWS[row][0]];
			game_end = true;
		}
	}

	// Since the winner is not determined, we check 
	// if there is a draw (whether there are empty cells on the field).
	if (count(board.begin(), board.end(), EMPTY) == 0)
	{
		winner_chip = TIE;
		game_end = true;
	}

	// Since the winner has not been determined 
	// and the draw has not yet come, the game continues.
	if (!game_end)
	{
		winner_chip = NO_ONE;
	}

	return winner_chip;	
}

inline bool is_legal(const vector<char> & board, int move)
{
	return EMPTY == board[move];	
}

int human_move(const vector<char> & board, char human)
{
	int move = ask_number("Where will you move?", (board.size() - 1));

	while (!is_legal(board, move))
	{
		cout << "\nThat square is already occupied, foolish human.\n";
		move = ask_number("Where will you move?", (board.size() - 1));
	}
	cout << "Fine...\n";

	return move;
}

int computer_move(vector<char> board, char computer)
{
	unsigned move = 0;
	bool found = false;

	// 1. If computer can win with the next move, make this move.
	while (!found && move < board.size())
	{
		if (is_legal(board, move))
		{
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY;
		}	
		if (!found)
		{
			++move;
		}
	}

	// 2. Else if the human can win the next move, block this move.
	if (!found)
	{
		move = 0;
		char human = opponent(computer);

		while (!found && move < board.size())
		{
			if (is_legal(board, move))
			{
				board[move] = human;
				found = winner(board) == human;
				board[move] = EMPTY;
			}
			if (!found)
			{
				++move;
			}
		}
	}

	// 3. Else take the optimal free cell in the next move.
	if (!found)
	{
		move = 0;
		unsigned i = 0;
		const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};

		// Choose the optimal free cell
		while (!found && i < board.size())
		{
			move = BEST_MOVES[i];
			if (is_legal(board, move))
			{
				found = true;
			}
			++i;
		}
	}

	cout << "I will take square number " << move << endl;

	return move;
}

void announce_winner(char winner, char computer, char human)
{
	if (winner == computer)
	{
		cout << winner << " is won!\n";
		cout << "As I predicted, human, I am triumphant once more -- proof\n"
			 << "that computer are superrior to humans in all regards.\n";
	}
	else if (winner == human)
	{
		cout << winner << " is won!\n";
		cout << "No, no! It cannot be! Somehow you tricked me, human.\n"
			 << "But never again! I, the computer, so swear it!\n";
	}
	else
	{
		cout << "It\'s a tie.\n";
		cout << "You were most lucky, human, and somehow managed to tie me.\n"
			 << "Celebrate... for this is the best you will ever achieve.\n";
	}
}
