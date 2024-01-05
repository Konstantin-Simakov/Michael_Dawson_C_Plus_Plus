// in_operator.cpp
// Overloading the >> (input) operator.
#include <iostream>
using namespace std;
  
class Person {
    friend std::istream & operator>>(std::istream & in, Person & person);
public:
    // Inline methods.
    Person(string name = "", unsigned age = 0): m_name(name), m_age(age) {}
    string get_name() const { return m_name; }
    unsigned get_age() const { return m_age; }
private:
    string m_name;
    unsigned m_age;
};

std::istream & operator>>(std::istream & in, Person & person)
{
    string name;
    unsigned age;
    
    in >> name >> age;
    if (in)
    {
        person.m_name = name;
        person.m_age = age;
    }

    return in;
}

int main(void)
{
    Person bob;

    cout << "Input name and age: ";
    cin >> bob;
    cout << "Name: " << (bob.get_name() != "" ? bob.get_name() : "<empty>");
    cout << "\tAge: " << bob.get_age() << endl;

    return 0;
}
