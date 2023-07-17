// global_reach.cpp
// Demonstrates working with global variables

#include <iostream>
using namespace std;

// Creating a global variable
int glob = 10;

void access_global(void);
void hide_global(void);
void change_global(void);

int main(void)
{
	cout << "In main() glob is: " << glob << "\n\n";
	access_global();
	
	hide_global();
	cout << "In main() glob is: " << glob << "\n\n";
	
	change_global();
	cout << "In main() glob is: " << glob << "\n\n";

	return 0;
}

void access_global(void)
{
	cout << "In access_global() glob is: " << glob << "\n\n";
}

void hide_global(void)
{
	// Hide the global variable 'glob'
	int glob = 0;

	cout << "In hide_global() glob is: " << glob << "\n\n";
}

void change_global(void)
{
	// Change the global variable 'glob'
	glob = -10;
	cout << "In change_global() glob is: " << glob << "\n\n";
}
