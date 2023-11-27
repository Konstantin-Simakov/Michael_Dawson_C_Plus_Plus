// exercise7.cpp
// 
// Create the 'Figure' abstract class with 
// calculation methods of perimeter and square for it and
// also the method displaying information about the figure on the screen.
// Create derive classes:
// 1) Rectangle;
// 2) Circle;
// 3) Triangle;
// Each class must be had your own calc. methods of perimeter and square.
// Create a figure array from n elements and 
// display full information (first of all, perimeter and square) 
// about the figures on the screen.
// 
#include <iostream>
// For to_string().
#include <string>
// For atan().
#include <cmath>
using namespace std;

class Figure {
	friend ostream & operator<<(ostream & os, const Figure & a_figure);
public:
	Figure(const string & name = "");
	virtual ~Figure();
	virtual double perimeter() const = 0;
	virtual double square() const = 0;
private:
	// The name of a figure.
	string m_name;	
	// The number of a figure.
	int m_num;
};

Figure::Figure(const string & name):
m_name(name)
{}

Figure::~Figure()
{}


class Rectangle: public Figure {
public:
	Rectangle(const string & name = "Rectangle", double height = 1.0, double length = 1.0);
	virtual double perimeter() const;
	virtual double square() const;
private:
	double m_height;
	double m_length;
};

Rectangle::Rectangle(const string & name, double height, double length):
Figure(name),
m_height(height),
m_length(length)
{}

double Rectangle::perimeter() const
{
	return 2 * (m_height + m_length);
}

double Rectangle::square() const
{
	return m_height * m_length;
}


class Circle: public Figure {
public:
	Circle(const string & name = "Circle", double radius = 1.0);
	virtual double perimeter() const;
	virtual double square() const;
	const double PI = atan(1) * 4;
private:
	double m_radius;
};


Circle::Circle(const string & name, double radius):
Figure(name),
m_radius(radius)
{}

double Circle::perimeter() const
{
	return 2 * PI * m_radius;
}

double Circle::square() const
{
	return PI * m_radius * m_radius;
}


class Triangle: public Figure {
public:
	Triangle(const string & name = "Triangle", double side_1 = 1.0,
		double side_2 = 1.0, double side_3 = 1.0);
	virtual double perimeter() const;
	virtual double square() const;
private:
	double m_side_1;
	double m_side_2;
	double m_side_3;
};

Triangle::Triangle(const string & name, double side_1, double side_2, double side_3):
Figure(name),
m_side_1(side_1),
m_side_2(side_2),
m_side_3(side_3)
{}

double Triangle::perimeter() const
{
	return m_side_1 + m_side_2 + m_side_3;
}

double Triangle::square() const
{
	// Use the Heron formula.
	const double SEMI_PERIMETER = perimeter() / 2;

	return sqrt(SEMI_PERIMETER * (SEMI_PERIMETER - m_side_1) * 
			(SEMI_PERIMETER - m_side_2) * (SEMI_PERIMETER - m_side_3));
}


// All (friend and free) function prototypes.
ostream & operator<<(ostream & os, const Figure & a_figure);
void init_figures(Figure ** pp_figure, int r, int c, int t);
void print_figures(Figure ** pp_figure, int size);
void delete_figures(Figure ** pp_figure, int size);

int main(void)
{
	int r, c, t;
	int n;

	cout << "Enter the number of rectangles: ";
	cin >> r;
	cout << "Enter the number of circles: ";
	cin >> c;
	cout << "Enter the number of triangles: ";
	cin >> t;
	
	n = r + c + t;
	Figure ** pp_figure = new Figure * [n];
	// Create and initialize the figures.
	init_figures(pp_figure, r, c, t);
	
	cout << "\nDisplaying information about the figures.\n";
	print_figures(pp_figure, n);
	
	delete_figures(pp_figure, n);
	delete [] pp_figure;

	cout << "\nBye!\n";	

	return 0;
}

void delete_figures(Figure ** pp_figure, int size)
{
	int i;

	for (i = 0; i < size; ++i)
	{
		delete pp_figure[i];
	}
}

void init_figures(Figure ** pp_figure, int r, int c, int t)
{
	int i;

	for (i = 0; i < r; ++i)
	{
		pp_figure[i] = new Rectangle("Rectangle #" + to_string(i + 1), (1 + i) / 2.0, (2 + i) / 2.0);
	}
	for (i = 0; i < c; ++i)
	{
		pp_figure[r + i] = new Circle("Circle #" + to_string(i + 1), 0.5 + i);
	}
	for (i = 0; i < t; ++i)
	{
		pp_figure[(r + c) + i] = new Triangle("Triangle #" + to_string(i + 1), i + 0.1, i + 0.2, i + 0.3);
	}
}

void print_figures(Figure ** pp_figure, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << *(pp_figure[i]) << endl;
	}
}

ostream & operator<<(ostream & os, const Figure & a_figure)
{
	os << a_figure.m_name
	   << ": perimeter = " << a_figure.perimeter()
	   << ", square = " << a_figure.square();

	return os;
}
