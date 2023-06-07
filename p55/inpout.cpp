#include <iostream.h>

class point
{
	double x,y;
public:
	point(const double& x0, const double& y0) : x(x0), y(y0) { }
	point& operator+=(const point&);
	point operator-() const;
	friend ostream& operator<<(ostream&, const point&);
	friend istream& operator>>(istream&, point&);
};

point& point::operator +=(const point& p)
{
	x += p.x;
	y += p.y;
	return *this;
}

point point::operator -() const
{
	point ptemp = *this;
	ptemp.x = -x;
	ptemp.y = -y;
	return ptemp;
}

ostream& operator<<(ostream& out, const point& p)
{
	out << '(' << p.x << ',' << p.y << ')';
	return out;
}

istream& operator>>(istream& inp, point& p)
{
	inp >> p.x >> p.y;
	return inp;
}

point operator +(const point& p1, const point& p2)
{
	point ptemp = p1;
	return ptemp += p2;
}

point operator -(const point& p1, const point& p2)
{
	point ptemp = p1;
	return ptemp +-p2;
}

int main()
{
	point p1(0.,0.);
	cout << "Inserisci coordinate primo punto: ";
	cin >> p1;
	point p2(0.,0.);
	cout << "Inserisci coordinate secondo punto: ";
	cin >> p2;
	cout << p1 << " + " << p2 << " = " << p1+p2 << '\n';
	cout << p1 << " - " << p2 << " = " << p1-p2 << '\n';
	return 0;
}
