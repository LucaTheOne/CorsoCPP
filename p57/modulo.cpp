#include <iostream.h>
#include <math.h>

class point
{
	double x,y;
public:
	point(const double& x0, const double& y0) : x(x0), y(y0) { }
	point& operator++();
	point operator++(int);
	operator double();
	friend ostream& operator<<(ostream& out, point*);
};

point& point::operator++()
{
	++x;
	++y;
	return *this;
}

point point::operator++(int)
{
	point temp = *this;
	++*this;
	return temp;
}

point::operator double()
{
	return sqrt(x*x+y*y);
}

ostream& operator<<(ostream& out, point* ap)
{
	out << '(' << ap->x << ',' << ap->y << ')';
	return out;
}

int main()
{
	point p(3.,4.);
	cout << "Il modulo di " << &p << " e': " << p << '\n';
	point ps = p++;
	point pp = ++p;
	cout << &point(3.,4.) << " dopo incr. suffisso: " << &ps << '\n';
	cout << &point(3.,4.) << " dopo incr. prefisso: " << &pp << '\n';
	return 0;
}
