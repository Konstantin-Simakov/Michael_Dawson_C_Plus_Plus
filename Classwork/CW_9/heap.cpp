// heap.cpp
// Demonstrates working with dynamic memory named "heap".
#include <iostream>
using namespace std;

// Returns integer variable from heap.
int * int_on_heap();
// Create data leakage.
void leak_1();
// Create another data leakage.
void leak_2();

int main(void)
{
	int * p_heap = new int;
	*p_heap = 10;
	cout << "*p_heap: " << *p_heap << "\n\n";

	int * p_heap_2 = int_on_heap();
	cout << "*p_heap_2: " << *p_heap_2 << "\n\n";

	cout << "Freeing memory pointed to by p_heap.\n\n";
	delete p_heap;

	cout << "Freeing memory pointed to by p_heap_2.\n\n";
	delete p_heap_2;

	// Getting rid of dangling pointers.
	p_heap = NULL;
	p_heap_2 = NULL;

	return 0;
}

int * int_on_heap()
{
	int * p_temp = new int(20);

	return p_temp;
}

void leak_1()
{
	int * drip_1 = new int(30);
}

void leak_2()
{
	int * drip_2 = new int(50);
	drip_2 = new int(100);

	delete drip_2;
}
