#include <iostream.h>
#include <stdio.h>

class point
{
	double x,y;
public:
	point(const double& x0, const double& y0) : x(x0), y(y0) { }
	point(const double& d) : x(d), y(d) {   }
	point& operator+=(const point&);
	point& operator*=(const point&);
	point operator-() const;
	friend double operator%(const point&, const point&);
	friend bool operator==(const point&, const point&);
	friend ostream& operator<<(ostream&, const point&);
	friend istream& operator>>(istream&, point&);
};

point& point::operator +=(const point& p)
{
	x += p.x;
	y += p.y;
	return *this;
}

point& point::operator *=(const point& p)
{
	x *= p.x;
	y *= p.y;
	return *this;
}

point point::operator -() const
{
	point ptemp = *this;
	ptemp.x = -x;
	ptemp.y = -y;
	return ptemp;
}

point operator*(const point& p1, const point& p2)
{
	point ptemp = p1;
	return ptemp *=p2;
}

double operator%(const point& p1, const point& p2)
{
	point ptemp = p1*p2;
	return ptemp.x+ptemp.y;  // prodotto scalare
}

bool operator==(const point& p1, const point& p2)
{
	return p1.x == p2.x && p1.y == p2.y;
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

void operator/(const char* msg, const point& p)
{
	cout << msg << " = " << p << '\n';
}

bool operator!=(const point& p1, const point& p2)
{
	return !(p1==p2);
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
	double fscal, trasl;
	cout << "Inserisci fattore di scala primo punto: ";
	cin >> fscal;
	cout << "Inserisci traslazione secondo punto: ";
	cin >> trasl;
	cout << "\n\n\n";
	"p1"/p1;
	"p2"/p2;
	"p1+p2"/(p1+p2);
	"p1-p2"/(p1-p2);
	char msg[30];
	sprintf(msg,"p1 * %f",fscal);
	msg/(fscal*p1);
	sprintf(msg,"p2 + %f",trasl);
	msg/(p2+trasl);
	if ( p1 != p2 )
		cout << "I punti " << p1 << " e " << p2 << " sono diversi\n";
	point p3 = 3.;
	if ( 3.0 == p3 )
		cout << "Il punto " << p3 << " ha coordinate uguali a 3\n"; 
	cout << "Prodotto scalare p1 x p2 = " << p1%p2 << "\n\n\n";
	return 0;
}
