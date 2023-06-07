#include <iostream.h>

class point
{
	double x,y;
public:
	point(const double& x0, const double& y0) : x(x0), y(y0) { }
	point& operator+=(const point&);
	point operator-() const;
	void show();
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

void point::show()
{
	cout << '(' << x << ',' << y << ')';
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
	double x,y;
	cout << "Inserisci coordinate primo punto: ";
	cin >> x >> y;
	point p1(x,y);
	cout << "Inserisci coordinate secondo punto: ";
	cin >> x >> y;
	point p2(x,y);
	p1.show(); cout << " + " ; p2.show() ; cout << " = ";
		(p1+p2).show(); cout << '\n';
	p1.show(); cout << " - " ; p2.show() ; cout << " = ";
		(p1-p2).show(); cout << '\n';
	return 0;
}
