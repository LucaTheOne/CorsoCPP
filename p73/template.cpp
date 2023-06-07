#include <iostream.h>

namespace My_region
{
	template<class T> class A
	{
		T mem;
	public:
		A(const T& m) : mem(m) {}
		friend ostream& operator<<(ostream&, const A&);
	};

	template<class T> ostream& operator<<(ostream& out, const A<T>& a)
	{
		out << a.mem << "   ";
		return out;
	}

	class point
	{
		double x,y;
	public:
		point(const double& x0, const double& y0)
			: x(x0), y(y0) {}
		friend ostream& operator<<(ostream&, const point&);
	};

	ostream& operator<<(ostream& out, const point& p)
	{
		out << '(' << p.x << ',' << p.y << ')';
		return out;
	}
}

int main()
{
	using My_region::A;
	using My_region::point;

	A<int> ai(5);
	A<double> ad(1.7);
	A<char> ac(69);
	A<point> ap(point(5.4,2.3));

	cout << "\n\t\t" << ai << ad << ac << ap << "\n\n\n";
	return 0;
}

