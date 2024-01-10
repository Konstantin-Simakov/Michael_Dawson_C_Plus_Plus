// exercise3.cpp
// 
// Read a matrix from a file. 
// The first 2 numbers are the size of the matrix, 
// the rest are its elements in accordance with the given matrix size.
// 
// 1. Find the minimum among the values of the maximum elements of each column.
// 2. Find the maximum among the elements of the main diagonal and 
// the indices of the first maximum in the entire matrix, if it is square; 
// if not, display the corresponding message.
// 3. Square the numbers to the right and left of the zero elements of the matrix.
// 
// All the results are displayed on the screen.
// 
#include <iostream>
// For std::ifstream, std::ofstream classes.
#include <fstream>
// For srand(), rand(), exit(), EXIT_FAILURE.
#include <cstdlib>
// For time().
#include <ctime>
using namespace std;

int ** create(int ** matrix, int rows, int cols);
void init_matrix(std::istream & fin, int ** matrix, int rows, int cols);
void del_matrix(int ** matrix, int rows, int cols);
void display(int ** matrix, int rows, int cols);
int min_trg(int ** matrix, int rows, int cols);
int max_col(int ** matrix, int rows, int cols, int col_index);
int max_main_diag(int ** matrix, int rows, int cols);
int first_max_item(int ** matrix, int rows, int cols, 
                    int & index_row, int & index_col);
void to_square(int ** matrix, int rows, int cols);

int main(void)
{
    std::ifstream fin;
    fin.open("input3.txt");
    if (!fin.is_open())
    {
        cout << "Couldn\'t open the file input.txt.\n";
        cout << "Program teriminating.\n";
        exit(EXIT_FAILURE);
    }
    int rows, cols;
    // Read rows and columns of a matrix from the file.
    fin >> rows >> cols;
    
    int ** matrix = NULL;
    matrix = create(matrix, rows, cols);
    // Read the matrix from the file.
    init_matrix(fin, matrix, rows, cols);

    cout << "Source array:\n";
    display(matrix, rows, cols);

    // Processing the matrix.
    // 1.
    cout << "The target minimum element is " 
         << min_trg(matrix, rows, cols) << endl;

    // 2.
    if (rows != cols)
    {
        cout << "The matrix is not square.\n";
        cout << "Program teriminating.\n";
        exit(EXIT_FAILURE);
    }
    cout << "Max element in the matrix main diagonal is " 
         << max_main_diag(matrix, rows, cols) << endl;
    
    int index_row, index_col;
    first_max_item(matrix, rows, cols, index_row, index_col);
    cout << "The indices of matrix first max item element are: "
         << "i = " << index_row << ", j = " << index_col << endl;

    // 3.
    to_square(matrix, rows, cols);
    cout << "By squaring the elements left and right from zero, the matrix is:\n";
    display(matrix, rows, cols);

    del_matrix(matrix, rows, cols);

    return 0;
}

int ** create(int ** matrix, int rows, int cols)
{
    matrix = new int * [rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int [cols];
    }

    return matrix;
}

void init_matrix(std::istream & fin, int ** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            fin >> matrix[i][j];
        }
    }
}

void del_matrix(int ** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
}

void display(int ** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

int min_trg(int ** matrix, int rows, int cols)
{
    int global_min = max_col(matrix, rows, cols, 0);
    for (int j = 1; j < cols; ++j)
    {
        int maximum_column = max_col(matrix, rows, cols, j);
        if (global_min > maximum_column)
        {
            global_min = maximum_column;
        }
    }

    return global_min;
}

int max_col(int ** matrix, int rows, int cols, int col_index)
{
    int local_max = matrix[0][col_index];
    for (int i = 1; i < rows; ++i)
    {
        if (local_max < matrix[i][col_index])
        {
            local_max = matrix[i][col_index];
        }
    }

    return local_max;
}

int max_main_diag(int ** matrix, int rows, int cols)
{
    int max_item = matrix[0][0];
    for (int i = 1; i < rows; ++i)
    {
        if (max_item < matrix[i][i])
        {
            max_item = matrix[i][i];
        }
    }

    return max_item;
}

int first_max_item(int ** matrix, int rows, int cols, 
                    int & index_row, int & index_col)
{
    int max_item = matrix[0][0];
    index_row = index_col = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (max_item < matrix[i][j])
            {
                max_item = matrix[i][j];
                index_row = i;
                index_col = j;
            }
        }
    }

    return max_item;
}

void to_square(int ** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (0 == matrix[i][j])
            {
                if (cols - 1 == j)
                {
                    matrix[i][j - 1] *= matrix[i][j - 1];
                }
                else if (0 == j)
                {
                    matrix[i][1] *= matrix[i][1];
                }
                else
                {
                    matrix[i][j - 1] *= matrix[i][j - 1];
                    matrix[i][j + 1] *= matrix[i][j + 1];
                }
            }
        }
    }
}
