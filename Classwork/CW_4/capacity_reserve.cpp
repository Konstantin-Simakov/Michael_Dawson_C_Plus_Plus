// capacity_reserve.cpp
// Use capacity() and reverse() methods of vector.
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    cout << "Creating a 10 element vector to hold scores.\n";
    vector<int> scores(10, 0);
    cout << "Vector size is " << scores.size() << endl;
    cout << "Vector capacity is " << scores.capacity() << endl;
    
    cout << "\nAdd a score.\n";
    scores.push_back(0);
    cout << "Vector size is " << scores.size() << endl;
    cout << "Vector capacity is " << scores.capacity() << endl;

    cout << "\nReserving more memory.\n";
    scores.reserve(scores.capacity() * 2);
    cout << "Vector size is " << scores.size() << endl;
    cout << "Vector capacity is " << scores.capacity() << endl;

    return 0;
}
