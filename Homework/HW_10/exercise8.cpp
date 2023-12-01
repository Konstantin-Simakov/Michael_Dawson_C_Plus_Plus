// exercise8.cpp
// 
// Create a 'Customer' class with next properties:
// 1) First name;
// 2) Middle name;
// 3) Last name;
// 4) Address;
// 5) Credit card number;
// 6) Bank account number.
// 
// In the class, next methods have to be realized:
// 1) Constructor;
// 2) Setters for properties' values;
// 3) Getters for properties' values;
// 4) Overloaded <<() operator to display customer information.
// 
// Create a common array of objects of this class without initialization.
// Then use setters to initailize all properties for each object in the array.
// Display the list of customers in alphabetical order 
// (use any custom sorting algorithm) and 
// the list of customers whose credit card number is in a given range.
// 
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Customer {
friend ostream & operator<<(ostream & os, const Customer & a_customer);
public:
	// Constructor.
	Customer(
		const string & fist_name = "", 
		const string & middle_name = "",
		const string & last_name = "",
		const string & address = "",
		long credit_card_num = 0,
		long bank_account_num = 0);
	// Getters.
	const string & get_first_name() const;
	const string & get_middle_name() const;
	const string & get_last_name() const;
	const string & get_address() const;
	long get_credit_card_num() const;
	long get_bank_account_num() const;
	// Setters.
	void set_first_name(const string & new_first_name = "");
	void set_middle_name(const string & new_middle_name = "");
	void set_last_name(const string & new_last_name = "");
	void set_address(const string & new_address = "");
	bool set_credit_card_num(long new_credit_card_num = 0);
	bool set_bank_account_num(long new_bank_account_num = 0);
private:
	string m_first_name;
	string m_middle_name;
	string m_last_name;
	string m_address;
	long m_credit_card_num;
	long m_bank_account_num;
};

Customer::Customer(
	const string & first_name, 
	const string & middle_name,
	const string & last_name,
	const string & address,
	long credit_card_num,
	long bank_account_num):
m_first_name(first_name),
m_middle_name(middle_name),
m_last_name(last_name),
m_address(address),
m_credit_card_num(credit_card_num),
m_bank_account_num(bank_account_num)
{}

// Getters.
const string & Customer::get_first_name() const
{
	return m_first_name;
}

const string & Customer::get_middle_name() const
{
	return m_middle_name;
}

const string & Customer::get_last_name() const
{
	return m_last_name;
}

const string & Customer::get_address() const
{
	return m_address;
}

long Customer::get_credit_card_num() const
{
	return m_credit_card_num;
}

long Customer::get_bank_account_num() const
{
	return m_bank_account_num;
}

// Setters.
void Customer::set_first_name(const string & first_name)
{
	m_first_name = first_name;
}

void Customer::set_middle_name(const string & middle_name)
{
	m_middle_name = middle_name;
}

void Customer::set_last_name(const string & last_name)
{
	m_last_name = last_name;
}

void Customer::set_address(const string & address)
{
	m_address = address;
}

bool Customer::set_credit_card_num(long credit_card_num)
{
	bool ret_val = false;
	if (credit_card_num >= 0)
	{
		m_credit_card_num = credit_card_num;
		ret_val = true;
	}

	return ret_val;
}

bool Customer::set_bank_account_num(long bank_account_num)
{
	bool ret_val = false;
	if (bank_account_num >= 0)
	{
		m_bank_account_num = bank_account_num;
		ret_val = true;
	}

	return ret_val;
}


// Function prototypes.
ostream & operator<<(ostream & os, const Customer & a_customer);
void init(Customer customers[], int num);
void display(const Customer customers[], int num);
void sort_alphabetical(Customer customers[], int num);
void show_credit_card_range(const Customer customers[], int num, long start, long finish);

int main(void)
{
	// The number of customers in an array.
	const int NUM = 3;
	Customer customers[NUM];

	cout << "Enter the data about " << NUM << " customers.\n";
	init(customers, NUM);

	int start, finish;
	cout << "Enter a start and a finish numbers for a range of the credit card number "
		 << "(through a space): ";
	cin >> start >> finish;
	if (start >= finish)
	{
		cout << "Error: start number has to be less than finish one.\n";
		cout << "Program terminated.\n";
		exit(EXIT_FAILURE);
	}

	cout << "\nSource list of customers.\n";
	display(customers, NUM);

	cout << "\nThe list of customers in alphabetical order.\n";
	sort_alphabetical(customers, NUM);
	display(customers, NUM);

	cout << "\nThe list of customers whose credit card number is in the range from " 
		 << start << " to " << finish << ".\n";
	show_credit_card_range(customers, NUM, start, finish);

	cout << "\nBye!\n";

	return 0;
}

ostream & operator<<(ostream & os, const Customer & a_customer)
{
	os << a_customer.m_last_name << ' ' << a_customer.m_first_name << ' ' << a_customer.m_middle_name << ", "
	   << "Address: " << a_customer.m_address << ", "
	   << "Credit card number: " << a_customer.m_credit_card_num << ", "
	   << "Bank account number: " << a_customer.m_bank_account_num << '.';

	return os;
}

void init(Customer customers[], int num)
{
	string first_name;
	string middle_name;
	string last_name;
	string address;
	long credit_card_num;
	long bank_account_num;
	
	for (int i = 0; i < num; ++i)
	{
		// Read data for each customer.
		cout << i + 1 << ".\n";
		cout << "Last name: ";
		cin >> last_name;
		cout << "First name: ";
		cin >> first_name;
		cout << "Middle name: ";
		cin >> middle_name;
		cout << "Address: ";
		cin >> address;
		cout << "Credit card number: ";
		cin >> credit_card_num;
		cout << "Bank account number: ";
		cin >> bank_account_num;
		cout << endl;

		// Write the data in the array of customers.
		customers[i].set_first_name(first_name);
		customers[i].set_middle_name(middle_name);
		customers[i].set_last_name(last_name);
		customers[i].set_address(address);
		customers[i].set_credit_card_num(credit_card_num);
		customers[i].set_bank_account_num(bank_account_num);
	}
}

void display(const Customer customers[], int num)
{
	for (int i = 0; i < num; ++i)
	{
		cout << customers[i] << endl;
	}
}

// Modified insertion sort algorithm.
void sort_alphabetical(Customer customers[], int num)
{
	for (int i = 0; i < num - 1; ++i)
	{
		for (int j = i; j < num; ++j)
		{
			if ((customers[i].get_last_name() > customers[j].get_last_name()) ||
				(customers[i].get_last_name() == customers[j].get_last_name() && 
				customers[i].get_middle_name() > customers[j].get_middle_name()) ||
				(customers[i].get_middle_name() == customers[j].get_middle_name() && 
				customers[i].get_first_name() > customers[j].get_first_name()))
			{
				swap(customers[i], customers[j]);
			}			
		}
	}
}

void swap(Customer & c1, Customer & c2)
{
	Customer temp = c1;
	c1 = c2;
	c2 = temp;
}

void show_credit_card_range(const Customer customers[], int num, long start, long finish)
{
	for (int i = 0; i < num; ++i)
	{
		if (customers[i].get_credit_card_num() >= start && 
			customers[i].get_credit_card_num() <= finish)
		{
			cout << customers[i] << endl;
		}
	}
}
