// exercise6.cpp
// 
// "Triangle" program.
// Calculates the perimeter, area, and 
// median intersection point of a triangle given by its coordinates.
// 
// For fixed modificator.
#include <iostream>
// For setw(), setprecision() manipulators.
#include <iomanip>
#include <cmath>
using namespace std;

struct Point {
	float x;
	float y;
};

class Triangle {
public:
	Triangle(Point a, Point b, Point c);
	void info();
	float perimeter();
	float area();
	Point median_point();
private:
	Point m_a;
	Point m_b;
	Point m_c;
};

int main(void)
{
	Triangle t({0, 0}, {0, 5}, {12, 0});
	t.info();

	cout << fixed << setprecision(1);
	cout << "Its perimeter is: " << setw(10) << t.perimeter() << endl;
	cout << "Its area is: " << setw(15) << t.area() << endl;
	cout << "Its median point is: " << setw(3) << "(" << t.median_point().x << "; " 
		 << t.median_point().y << ")\n";

	return 0;
}

Triangle::Triangle(Point a, Point b, Point c):
m_a(a),
m_b(b),
m_c(c)
{}

float Triangle::perimeter()
{
	// Find out legnths of sides.
	float ab = sqrt(pow(m_a.x - m_b.x, 2) + pow(m_a.y - m_b.y, 2));
	float bc = sqrt(pow(m_b.x - m_c.x, 2) + pow(m_b.y - m_c.y, 2));
	float ac = sqrt(pow(m_a.x - m_c.x, 2) + pow(m_a.y - m_c.y, 2));

	return ab + bc + ac;
}

float Triangle::area()
{
	return abs((m_b.x - m_a.x) * (m_c.y - m_a.y) - (m_c.x - m_a.x) * (m_b.y - m_a.y)) / 2;
}

Point Triangle::median_point()
{
	// Point a_1 is mid side bc.
	Point a_1;
	a_1.x = (m_b.x + m_c.x) / 2;
	a_1.y = (m_b.y + m_c.y) / 2;

	// m is the point of intersection of the medians.
	Point m;
	m.x = (1 * m_a.x + 2 * a_1.x) / (2 + 1);
	m.y = (1 * m_a.y + 2 * a_1.y) / (2 + 1);

	return m;
}

void Triangle::info()
{
	cout << "The triangle has next coordinates:\n\n";
	cout << "A(" << m_a.x << "; " << m_a.y << "), "
		 << "B(" << m_b.x << "; " << m_b.y << "), "
		 << "C(" << m_c.x << "; " << m_c.y << ").\n\n";
}
