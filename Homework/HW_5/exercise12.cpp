// exercise12.cpp
// Displays n prime numbers.
#include <iostream>
using namespace std;

// n_primes is the ordinal number of the prime. 	
void prime_number(unsigned n_primes);
bool is_prime(unsigned num);

int main(void)
{
	cout << "Enter the number of primes: ";
	int n;
	cin >> n;
	
	prime_number(n);

	return 0;
}

void prime_number(unsigned n_primes)
{
	unsigned primes = 0;
	unsigned num = 1;

	while (primes < n_primes)
	{
		++num;
		if (is_prime(num))
		{
			primes++;
			cout << num << "  ";
		}
	}
	cout << endl;
}

bool is_prime(unsigned num)
{
	bool prime = true;

	for (unsigned div = 2; div * div <= num; div++)
	{
		if (num % div == 0)
		{
			prime = false;
			break;
		}		
	}

	return prime;
}