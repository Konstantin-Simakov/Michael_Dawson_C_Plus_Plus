// exercise1.cpp
// 
// File compression program.
// Compress the input file n=3 times into the output file.
// 
#include <iostream>
#include <string>
// For std::ifstream, std::ofstream classes.
#include <fstream>
#include <cstdlib>
using namespace std;

void compress_file(std::istream & in, std::ostream & out);

// File compression factor.
const int FACTOR = 3;

int main(void)
{
    // File variable for data reading.
    std::ifstream fin("input1.txt");
    if (!fin.is_open())
    {
        cerr << "Coudn\'t open the file input1.txt\n";
        exit(EXIT_FAILURE);
    }
    // File variable for data writing.
    std::ofstream fout("output1.txt");
    if (!fout.is_open())
    {
        cerr << "Coudn\'t open the file output1.txt\n";
        exit(EXIT_FAILURE);
    }

    compress_file(fin, fout);

    // Closing files.
    fin.close();
    fout.close();

    return 0;
}

void compress_file(std::istream & in, std::ostream & out)
{
    std::string line;

    // Read all the file.
    while (getline(in, line, static_cast<char>(EOF)))
    {
        continue;
    }

    // Process the read data.
    for (unsigned i = 0; i < line.size(); ++i)
    {
        if (i % FACTOR == 0)
        {
            out << line[i];
        }
    }
    out << endl;    
}
