// wstreams.cpp
// Demonstrates wcout, wcerr, wcin objects working.
#include <iostream>
using namespace std;

int main(void)
{
	int age;
	double weight;

	wcout << L"Введите возраст: ";
	wcin >> age;
	wcout << L"Введите вес: ";
	wcin >> weight;

	if (age <= 0 || weight <= 0)
		wcerr << L"Введены некорректные данные.\n";
	else
		wcout << L"Ваш возраст: " << age << L", вес: " << weight << endl;

	return 0;
}
