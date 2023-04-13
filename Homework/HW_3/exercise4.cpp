// exercise4.cpp
// Setting the chess board with a figures and output it to the screen.
#include <iostream>

int main(void)
{
	using namespace std;
	const int ROWS = 8;
	const int COLS = 8;
	const char ROOK = 'R';
	const char HORSE = 'H';
	const char ELEPHANT = 'E';
	const char QUEEN = 'Q';
	const char KING = 'K';
	const char PAWN = 'o';
	const char CELL = '.';
	const char SPACE = ' ';
	const string SPACES(3, SPACE);
	char chess_board[ROWS][COLS];

	// Main calculations of the program
	// Setting main figures for the second player
	chess_board[0][0] = ROOK;
	chess_board[0][1] = HORSE;
	chess_board[0][2] = ELEPHANT;
	chess_board[0][3] = QUEEN;				// D-vertical
	chess_board[0][4] = KING;				// E-vertical
	chess_board[0][5] = ELEPHANT;
	chess_board[0][6] = HORSE;
	chess_board[0][7] = ROOK;
	// Setting pawns for the second player
	for (int j = 0; j < COLS; ++j)
		chess_board[1][j] = PAWN;
	
	// Setting empty cells
	for (int i = 2; i < ROWS - 2; ++i)
	{
		for (int j = 0; j < COLS; ++j)
			chess_board[i][j] = CELL;
	}

	// Setting pawns for the first player
	for (int j = 0; j < COLS; ++j)
		chess_board[ROWS - 2][j] = PAWN;
	// Setting main figures for the first player
	chess_board[ROWS - 1][0] = ROOK;
	chess_board[ROWS - 1][1] = HORSE;
	chess_board[ROWS - 1][2] = ELEPHANT;
	chess_board[ROWS - 1][3] = QUEEN;		// D-vertical
	chess_board[ROWS - 1][4] = KING;		// E-vertical
	chess_board[ROWS - 1][5] = ELEPHANT;
	chess_board[ROWS - 1][6] = HORSE;
	chess_board[ROWS - 1][7] = ROOK;

	// Greeting the player
	cout << "\t\t\tWelcome to the \'Chess Board Game\'!\n\n";
	
	// Output the program results
	cout << "That\'s it!\n\n";
	for (int i = 0; i < ROWS; ++i)
	{
		cout << "\t\t\t";
		for (int j = 0; j < COLS; ++j)
			cout << chess_board[i][j] << SPACES;
		cout << endl;
	}
	cout << "\nGood game!\n";
	cout << "\nBye!\n";

	return 0;
}
