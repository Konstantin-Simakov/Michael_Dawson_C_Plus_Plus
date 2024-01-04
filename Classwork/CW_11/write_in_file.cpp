// write_in_file.cpp
// Write the data in the text file.
#include <iostream>
#include <fstream>
// For exit, EXIT_FAILURE.
#include <cstdlib>
using namespace std;
 
int main(void)
{
    // Write stream.
    std::ofstream fout;
    
    // Bind the file with stream variable.
    fout.open("textfile.txt");
    if (!fout.is_open())
    {
        cerr << "Couldn\'t open the file textfile.txt." << endl;
        exit(EXIT_FAILURE);
    }
    fout.close();
    cerr << "File has been written." << endl;

    return 0;
}
