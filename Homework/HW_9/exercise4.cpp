// exercise4.cpp
// 
// "Dybamic string array" program.
// 
// Funcionality:
// 1) the ability to access individual rows of an array by indexes; 
// 2) control going beyond the limits of arrays; 
// 3) perform element-by-element operations of concatenating two arrays to form a new array;
// 4) merging two arrays with the exclusion of duplicate elements; 
// 5) displaying an array element and the entire array;
// 6) assignment operator for an array;
// 7) copy constructor;
// 8) constructor;
// 9) destructor;
// 10) add an element of an array;
// 
// It is recommended to use a stack data structure that tracks the number of elements.
// The program must be tested for all array methods.
// 
#include <iostream>
#include <string>
// For assert()
#include <cassert>
using namespace std;

class String {
    friend ostream & operator<<(ostream & os, const String & a_string);
private:
    std::string m_str;
    String * m_p_next;
public:
    String(const std::string & str = "");
    std::string & get_string();
    String * get_next() const;
    void set_next(String * next);
};

String::String(const std::string & str):
m_str(str),
m_p_next(NULL)
{}

std::string & String::get_string()
{
    return m_str;
}

String * String::get_next() const
{
    return m_p_next;
}

void String::set_next(String * next)
{
    m_p_next = next;
}

ostream & operator<<(ostream & os, const String & a_string)
{
    os << a_string.m_str;

    return os;
}


class String_Array {
private:
    friend ostream & operator<<(ostream & os, const String_Array & s_ar);
    bool contains(const std::string & str) const;
public:
    String_Array();
    ~String_Array();
    String_Array(const String_Array & c);
    String_Array & operator=(const String_Array & c);
    std::string & operator[](int index) const;
    String_Array operator+(const String_Array & str_ar) const;
    String_Array merge_with(const String_Array & s_ar) const;
    int get_length() const;
    void add_string(const std::string & s);
    void remove_string();
    void clear();
private:
    String * m_p_head;
    int m_size;
};

String_Array::String_Array():
m_p_head(NULL),
m_size(0)
{}

String_Array::~String_Array()
{
    clear();
}

int String_Array::get_length() const
{
    return m_size;
}

String_Array::String_Array(const String_Array & c)
{
    m_p_head = NULL;
    m_size = 0;

    String * p_iter = c.m_p_head;
    while (p_iter != NULL)
    {
        add_string(p_iter->get_string());
        p_iter = p_iter->get_next();
    }
}

String_Array & String_Array::operator=(const String_Array & c)
{
    if (this != &c)
    {
        clear();
        m_size = 0;

        String * p_iter = c.m_p_head;
        while (p_iter != NULL)
        {
            add_string(p_iter->get_string());
            p_iter = p_iter->get_next();
        }        
    }

    return *this;
}

std::string & String_Array::operator[](int index) const
{
    assert(index >= 0 && index < m_size);

    String * p_iter = m_p_head;
    for (int i = 0; i < index; ++i)
    {
        p_iter = p_iter->get_next();
    }
    
    return p_iter->get_string();
}

void String_Array::add_string(const std::string & str)
{
    String * p_new_string = new String(str);

    if (NULL == m_p_head)
    {
        m_p_head = p_new_string;
    }
    else
    {
        String * p_iter = m_p_head;
        while (p_iter->get_next() != NULL)
        {
            p_iter = p_iter->get_next();
        }
        p_iter->set_next(p_new_string);
    }
    ++m_size;
}

String_Array String_Array::operator+(const String_Array & str_ar) const
{
    String_Array added;

    String * p_iter = m_p_head;
    while (p_iter != NULL)
    {
        added.add_string(p_iter->get_string());
        p_iter = p_iter->get_next();
    }

    p_iter = str_ar.m_p_head;
    while (p_iter != NULL)
    {
        added.add_string(p_iter->get_string());
        p_iter = p_iter->get_next();
    }

    return added;
}

bool String_Array::contains(const std::string & str) const
{
    bool found = false;

    String * p_iter = m_p_head;
    while (p_iter != NULL)
    {
        if (p_iter->get_string() == str)
        {
            found = true;
            break;
        }
        p_iter = p_iter->get_next();
    }

    return found;
}

String_Array String_Array::merge_with(const String_Array & s_ar) const
{
    String_Array merged;

    String * p_iter = m_p_head;
    while (p_iter != NULL)
    {
        if (!s_ar.contains(p_iter->get_string()))
        {
            merged.add_string(p_iter->get_string());
        }
        p_iter = p_iter->get_next();
    }

    p_iter = s_ar.m_p_head;
    while (p_iter != NULL)
    {
        if (!contains(p_iter->get_string()))
        {
            merged.add_string(p_iter->get_string());
        }
        p_iter = p_iter->get_next();
    }

    return merged;
}

void String_Array::remove_string()
{
    if (NULL == m_p_head)
    {
        cout << "The list is empty. No one to remove!\n";
    }
    else if (NULL == m_p_head->get_next())
    {
        String * p_temp = m_p_head;
        m_p_head = NULL;
        delete p_temp;
    }
    else
    {
        String * p_iter = m_p_head;
        while (p_iter->get_next()->get_next() != NULL)
        {
            p_iter = p_iter->get_next();
        }
        String * p_temp = p_iter->get_next();
        p_iter->set_next(NULL);
        delete p_temp;
    }
    --m_size;
}

void String_Array::clear()
{
    while (m_p_head != NULL)
    {
        remove_string();
    }
}

ostream & operator<<(ostream & os, const String_Array & an_array)
{
    String * p_iter = an_array.m_p_head;

    os << "\nHere\'s the list of strings:\n";
    if (NULL == p_iter)
    {
        os << "The list is empty.\n";
    }
    else
    {
        while (p_iter != NULL)
        {
            os << *p_iter << endl;
            p_iter = p_iter->get_next();
        }
    }

    return os;
}

int main(void)
{
    String_Array arr_1;
    arr_1.add_string("one");
    arr_1.add_string("two");
    arr_1.add_string("three");

    String_Array arr_2 = arr_1;
    arr_2.add_string("four");
    arr_2.add_string("five");
    arr_2.add_string("two");

    cout << arr_1 << endl;
    cout << arr_2 << endl;

    String_Array arr_3;
    arr_3 = arr_1;
    cout << arr_3 << endl;
    cout << arr_1 + arr_2 << endl;
    
    String_Array arr_4 = arr_1.merge_with(arr_2);
    cout << arr_4 << endl;
    
    arr_4[0] = "zero";
    cout << "arr_4:\n";
    for (int i = 0; i < arr_4.get_length(); ++i)
    {
        cout << arr_4[i] << endl;
    }

    return 0;
}
