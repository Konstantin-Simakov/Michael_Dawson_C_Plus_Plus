// scoping.cpp
// Demonstrates working with scopes.
#include <iostream>
using namespace std;

void func(void);

int main(void)
{
	// Local variable in main()
	int var = 5;
	cout << "In main() var is: " << var << "\n\n";

	func();
	cout << "Back in main() var is: " << var << "\n\n";
	{
		cout << "In main() in a new scope var is: " << var << "\n\n";
		
		cout << "Creating new var in new scope.\n";
		// The variable hides another variable in a new scope.
		int var = 10;
		cout << "In main() in a new scope var is: " << var << "\n\n";
	}

	cout << "At end of main() var created in new scope no longer exists.\n";
	cout << "At end of main() var is: " << var << endl;

	return 0;
}

void func(void)
{
	// Local variable in func()
	int var = -5;
	cout << "In func() var is: " << var << "\n\n";
}
