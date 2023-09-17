// heap_data_member.cpp
// Demonstrates behaviour of an object having a member data 
// for which memory is dynamically allocated.
#include <iostream>
#include <string>
using namespace std;

class Critter {
public:
	Critter(const string & name =  "", int age = 0);
	// Prototype of destructor.
	~Critter();
	// Prototype of copy constructor.
	Critter(const Critter & c);
	// Overloaded assignment operator.
	Critter & operator=(const Critter & c);
	void greet() const;
private:
	string * m_p_name;
	int m_age;
};

Critter::Critter(const string & name, int age)
{
	cout << "Constructor called\n";
	m_p_name = new string(name);
	m_age = age;
}

// Definition of the destructor.
Critter::~Critter()
{
	cout << "Destructor called\n";
	delete m_p_name;
}

// Definition of the copy constructor.
Critter::Critter(const Critter & c)
{
	cout << "Copy Constructor called\n";
	m_p_name = new string(*(c.m_p_name));
	m_age = c.m_age;
}

// Definition of the overloaded assignment operator.
Critter & Critter::operator=(const Critter & c)
{
	cout << "Overloaded Assignment Operator called\n";
	if (this != &c)
	{
		delete m_p_name;
		m_p_name = new string(*(c.m_p_name));
		m_age = c.m_age;
	}

	return *this;
}

void Critter::greet() const
{
	cout << "I\'m " << *m_p_name << " and I\'m " << m_age << " years old. ";
	cout << "&(*m_p_name): " << &(*m_p_name) << endl;
}

void test_destructor();
void test_copy_constructor(Critter a_copy);
void test_assignment_op();

int main(void)
{
	test_destructor();
	cout << endl;

	Critter crit("Poochie", 5);
	crit.greet();
	test_copy_constructor(crit);
	crit.greet();
	cout << endl;
	
	test_assignment_op();

	return 0;
}

void test_destructor()
{
	Critter to_destroy("Rover", 3);
	to_destroy.greet();
}

void test_copy_constructor(Critter a_copy)
{
	a_copy.greet();
}

void test_assignment_op()
{
	Critter crit_1("crit_1", 7);
	Critter crit_2("crit_2", 9);

	crit_1 = crit_2;
	crit_1.greet();
	crit_2.greet();
	cout << endl;

	Critter crit_3("crit", 11);
	crit_3 = crit_3;
	crit_3.greet();
}
