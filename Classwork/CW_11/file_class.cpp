// file_class.cpp
// Use a class for reading the text file.
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
 
class Point {
public:
    // Inline methods.
    Point(double x, double y): m_x(y), m_y(y) {}
    double get_x() const { return m_x; }
    double get_y() const { return m_y; }
private:
    double m_x;
    double m_y;
};

int main(void)
{
    vector<Point> points = {Point(0, 0), Point(4, 5), Point(-5, 7)};
    
    // Data writing.
    std::ofstream fout("points.txt");
    if (!fout.is_open())
    {
        cerr << "Couldn\'t open the file points.txt." << endl;
        exit(EXIT_FAILURE);
    }
    // Write all Point objects in the text file.
    // (Based on range 'for' loop.)
    for (const Point& point: points)
    {
        fout << point.get_x() << " " << point.get_y() << std::endl;
    }
    fout.close();
  
    vector<Point> new_points;
    // Data reading.
    std::ifstream fin("points.txt");
    if (!fin.is_open())
    {
        cerr << "Couldn\'t open the file points.txt." << endl;
        exit(EXIT_FAILURE);
    }
    double x, y;
    while (fin >> x >> y)
    {
        new_points.push_back(Point(x, y));
    }
    fin.close();
  
    for (const Point& point: new_points)
    {
        cout << "Point x: " << point.get_x() << "\ty: " << point.get_y() << endl;
    }
}
