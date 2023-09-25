// exercise3.cpp
// 
// "Dynamic number array" program.
// 
// Functionality:
// 1) constructor allocating memory for a given number of elements;
// 2) destructor;
// 3) copy constructor;
// 4) overloaded assignment operator;
// 5) overloaded subscript operator;
// 6) filling the array with random numbers;
// 7) shuffle of the array randomly;
// 8) search for the number of different elements;
// 9) displaying the array on the screen with cout object and << operator;
// Note: no use std::vector!!!
// The program must be tested for all array methods.
// 
#include <iostream>
#include <iomanip>
// For rand(), srand()
#include <cstdlib>
// For time()
#include <ctime>
using namespace std;

class Dynamic_Array {
	// Friend functions cannot use the overloaded subscript operator.
	friend ostream & operator<<(ostream & os, const Dynamic_Array & an_array);
public:
	Dynamic_Array(int elements = 2);
	~Dynamic_Array();
	Dynamic_Array(const Dynamic_Array & c);
	Dynamic_Array & operator=(const Dynamic_Array & c);
	double & operator[](int index);
public:
	void fill_random();
	void shuffle_random();
	int search_diff_nums();
private:
	double * m_p_array;
	int m_size;
public:
	const int UP_LIMIT = 50;
	const int LOW_LIMIT = -50;
private:
	int search_equal_nums();
};

Dynamic_Array::Dynamic_Array(int elements)
{
	m_p_array = new double[elements];
	m_size = elements;
}

Dynamic_Array::~Dynamic_Array()
{
	delete [] m_p_array;
}

Dynamic_Array::Dynamic_Array(const Dynamic_Array & c)
{
	m_p_array = new double[c.m_size];
	for (int i = 0; i < c.m_size; ++i)
	{
		m_p_array[i] = c.m_p_array[i];
	}
	m_size = c.m_size;
}

Dynamic_Array & Dynamic_Array::operator=(const Dynamic_Array & c)
{
	if (this != &c)
	{
		delete [] m_p_array;
		m_p_array = new double[c.m_size];
		for (int i = 0; i < c.m_size; ++i)
		{
			m_p_array[i] = c.m_p_array[i];
		}

		m_size = c.m_size;
	}

	return *this;
}

double & Dynamic_Array::operator[](int index)
{
	return m_p_array[index];
}

void Dynamic_Array::fill_random()
{
	for (int i = 0; i < m_size; ++i)
	{
		// Generation of random numbers between LOW_LIMIT and UP_LIMIT.
		m_p_array[i] = rand() % (UP_LIMIT - LOW_LIMIT + 1) + LOW_LIMIT;
	}
}

void Dynamic_Array::shuffle_random()
{
	int i = 0;
	int index_1, index_2;

	while (i < m_size)
	{
		index_1 = rand() % m_size;
		index_2 = rand() % m_size;
		
		if (index_1 == index_2)
		{
			continue;
		}
		else
		{
			double temp = m_p_array[index_1];
			m_p_array[index_1] = m_p_array[index_2];
			m_p_array[index_2] = temp;
		}
		++i;
	}
}

int Dynamic_Array::search_diff_nums()
{
	return m_size - search_equal_nums();
}

int Dynamic_Array::search_equal_nums()
{
	// Counter of equal numbers in the array.
	int count = 0;

	for (int i = 0; i < m_size; ++i)
	{
		for (int j = 0; j != i && j < m_size; ++j)
		{
			if (m_p_array[i] == m_p_array[j])
			{
				count++;
				break;
			}
		}
	}

	return count;
}

ostream & operator<<(ostream & os, const Dynamic_Array & an_array)
{
	os << fixed << setprecision(2);
	for (int i = 0; i < an_array.m_size; ++i)
	{
		os << setw(10) << an_array.m_p_array[i];
	}
	os << endl;

	return os;
}

int main(void)
{
	// For fill_random() and shuffle_random() methods.
	srand(static_cast<unsigned>(time(0)));
	// Constructor is working.
	Dynamic_Array arr_1(20);
	arr_1.fill_random();

	// Copy constructor is working.
	Dynamic_Array arr_3 = arr_1;
	Dynamic_Array arr_2;
	// Overloaded assignment operator (method operator=()) is working.
	arr_2 = arr_1;

	// Overloaded subscript operator (operator[]()) is working both writing and reading.
	arr_1[0] = -5.5;
	cout << "arr_1[0] = " << arr_1[0] << endl;
	
	cout << "\nArray 1:\n";
	// Friend function operator<<() is working.
	cout << arr_1 << endl;
	cout << "The number of different numbers is " << arr_1.search_diff_nums() << endl;
	
	cout << "\nSame array 2:\n";
	cout << arr_2 << endl;

	arr_3.shuffle_random();
	cout << "\nShuffled array 3 with same elements as array 1 and 2:\n";
	cout << arr_3 << endl;

	return 0;
}
