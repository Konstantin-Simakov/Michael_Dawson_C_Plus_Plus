// exercise1.cpp
// Counts from start to end number through interval and in reverse order
#include <iostream>

int main(void)
{
	using namespace std;
	cout << "Enter the start number, end number and interval between numbers: ";
	int start, end, interval;
	cin >> start >> end >> interval;

	cout << "\nCounting by ascend order:\n";
	for (int num = start; num <= end; num += interval)
		cout << num << "   ";
	cout << endl;

	cout << "\nCounting by descend order:\n";
	for (int num = end; num >= start; num -= interval)
		cout << num << "   ";
	cout << endl;

	return 0;
}
