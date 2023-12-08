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

class Point {
public:
	Point(float x = 0.0, float y = 0.0);
	float get_x() const;
	float get_y() const;
	void set_x(float x);
	void set_y(float y);	
private:
	float m_x;
	float m_y;
};

Point::Point(float x, float y):
m_x(x),
m_y(y)
{}

float Point::get_x() const
{
	return m_x;
}

float Point::get_y() const
{
	return m_y;
}

void Point::set_x(float x)
{
	m_x = x;
}

void Point::set_y(float y)
{
	m_y = y;
}


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
	Triangle t(Point(0, 0), Point(3, 0), Point(0, 4));
	t.info();

	cout << fixed << setprecision(1);
	cout << "Its perimeter is: " << setw(10) << t.perimeter() << endl;
	cout << "Its area is: " << setw(15) << t.area() << endl;
	cout << "Its median point is: " << setw(3) << "(" << t.median_point().get_x() << "; " 
		 << t.median_point().get_y() << ")\n";

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
	float ab = sqrt(pow(m_a.get_x() - m_b.get_x(), 2) + pow(m_a.get_y() - m_b.get_y(), 2));
	float bc = sqrt(pow(m_b.get_x() - m_c.get_x(), 2) + pow(m_b.get_y() - m_c.get_y(), 2));
	float ac = sqrt(pow(m_a.get_x() - m_c.get_x(), 2) + pow(m_a.get_y() - m_c.get_y(), 2));

	return ab + bc + ac;
}

float Triangle::area()
{
	return abs((m_b.get_x() - m_a.get_x()) * (m_c.get_y() - m_a.get_y()) - (m_c.get_x() - m_a.get_x()) * (m_b.get_y() - m_a.get_y())) / 2;
}

Point Triangle::median_point()
{
	Point m;
	m.set_x((m_a.get_x() + m_b.get_x() + m_c.get_x()) / 3.0);
	m.set_y((m_a.get_y() + m_b.get_y() + m_c.get_y()) / 3.0);

	return m;
}

void Triangle::info()
{
	cout << "The triangle has next coordinates:\n\n";
	cout << "A(" << m_a.get_x() << "; " << m_a.get_y() << "), "
		 << "B(" << m_b.get_x() << "; " << m_b.get_y() << "), "
		 << "C(" << m_c.get_x() << "; " << m_c.get_y() << ").\n\n";
}
