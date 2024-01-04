// read_from_file.cpp
// Read data from the text file.
#include <iostream>
#include <fstream>
// For getline().
#include <string>
using namespace std;
 
int main(void)
{
    string line;
    
    // Open the file for reading.
    std::ifstream fin("textfile.txt");
    if (!fin.is_open())
    {
        cerr << "Couldn\'t open the file textfile.txt." << endl;
        exit(EXIT_FAILURE);
    }

    // Process the file.
    while (getline(fin, line))
    {
        cout << line << endl;
    }
    // Close the file.
    fin.close();
}
