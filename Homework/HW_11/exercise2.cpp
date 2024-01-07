// exercise2.cpp
// 
// Linear arrays and files.
// 
// The program reads an array of integers from a file, 
// then adds the maximum element after each even element. 
// The program should clarify why the file was stopped reading
// and display this information on the screen.
// The program calculates the arithmetic and geometric means 
// for both arrays (original and transformed). 
// All results are written to a file.
// 
#include <iostream>
// For std::ifstream, std::ofstream classes.
#include <fstream>
// For pow().
#include <cmath>
// For exit(), EXIT_FAILURE.
#include <cstdlib>
using namespace std;

int init(std::istream & fin, int arr[], int n);
void output_res(std::ostream & fout, const int arr[], int n);
void f_display(std::ostream & fout, const int arr[], int n);
int insert_max(int arr[], int n);
int max_item(const int arr[], int n);
double average(const int arr[], int n);
double geometric_mean(const int arr[], int n);

int main(void)
{
    const int SIZE = 100;
    int array[SIZE];
    
    // Read data.
    std::ifstream fin;
    fin.open("input2.txt");
    if (!fin.is_open())
    {
        cout << "Couldn\'t open the file input.txt\n";
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    int cur_items = init(fin, array, SIZE);
    fin.close();

    // Write the data.
    std::ofstream fout;
    fout.open("output2.txt");
    if (!fout.is_open())
    {
        cout << "Couldn\'t open the file output.txt\n";
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    // File output.
    fout << "Source array.\n";
    output_res(fout, array, cur_items);

    // Insertion.
    cur_items = insert_max(array, cur_items);

    // File output.
    fout << "\nArray after insertion.\n";
    output_res(fout, array, cur_items);
    fout.close();

    return 0;
}

int init(std::istream & fin, int arr[], int n)
{
    int i = 0;
    while (i < n && fin >> arr[i])
    {
        ++i;
    }
    
    // Check the reason of input terminating.
    if (fin.eof())
    {
        cout << "End of file was reached.\n";
    }
    else if (fin.fail())
    {
        cout << "Input was terminated by mismatch data.\n";
    }
    else
    {
        cout << "Input was terminated by unknown reason.\n";
    }

    return i;
}

void output_res(std::ostream & fout, const int arr[], int n)
{
    // Results before insertion.
    f_display(fout, arr, n);
    fout << "Average: " << average(arr, n) << endl;
    fout << "Geometric mean: " << geometric_mean(arr, n) << endl;
}

void f_display(std::ostream & fout, const int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        fout << arr[i] << ' ';
    }
    fout << endl;
}

int insert_max(int arr[], int n)
{
    const int MAX = max_item(arr, n);
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] % 2 == 0)
        {
            ++n;
            for (int j = n - 1; j > i + 1; --j)
            {
                arr[j] = arr[j - 1];
            }
            arr[++i] = MAX;
        }
    }

    return n;
}

int max_item(const int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    return max;
}

double average(const int arr[], int n)
{
    double sum = 0.0f;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
    }

    return sum / n;
}

double geometric_mean(const int arr[], int n)
{
    double multiplication = 1.0;

    for (int i = 0; i < n; ++i)
    {
        multiplication *= arr[i];
    }

    return pow(multiplication, 1.0 / n);
}
