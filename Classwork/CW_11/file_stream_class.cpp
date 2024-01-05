// file_stream_class.cpp
// Use overloading << and >> operators for file writing and reading.
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
 
class Person {
    friend istream & operator>>(istream & in, Person & person);
    friend ostream & operator<<(ostream & os, const Person & person);
public:
    // Inline methods.
    Person(string name = "", unsigned age = 0): m_name(name), m_age(age) {}
    string get_name() const { return m_name; }
    unsigned get_age() const { return m_age; }
 private:
    string m_name;
    unsigned m_age;
};

void display(std::ostream & out, const vector<Person> & persons);
istream & operator>>(istream & in, Person & person);
ostream & operator<<(ostream & os, const Person & person);

int main(void)
{
    // Write the data in file.
    ofstream fout("people.txt");
    if (!fout.is_open())
    {
        cerr << "Couldn\'t open the file points.txt." << endl;
        exit(EXIT_FAILURE);
    }
    // Initial data is the Person vector.
    vector<Person> people =
    {
        Person("Tom", 23),
        Person("Bob", 25),
        Person("Alice", 22),
        Person("Kate", 31)
    };
    display(fout, people);
    fout.close();
    
    // Read the data written earlier.
    ifstream fin("people.txt");
    if (!fin.is_open())
    {
        cerr << "Couldn\'t open the file points.txt." << endl;
        exit(EXIT_FAILURE);
    }    
    // New vector for the read data.
    vector<Person> new_people;
    Person person;
    while (fin >> person)
    {
        new_people.push_back(person);
    }
    fin.close();
    
    // Display the input data to the consol.
    cout << "All people:" << endl;
    display(cout, new_people);
    return 0;
}

void display(ostream & out, const vector<Person> & people)
{
    for (const Person & person: people)
    {
        out << person << endl;
    }
}

ostream & operator<<(ostream & os, const Person & person)
{
    return os << person.get_name() << " " << person.get_age();
}

istream & operator>>(istream & in, Person & person)
{
    string name;
    unsigned age;
    in >> name >> age;
    // If the input failed, values are set by default.
    if (in)    
    {
        person.m_name = name;
        person.m_age = age;
    }

    return in;
}
