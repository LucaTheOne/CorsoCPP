#include <iostream.h>

namespace My_region
{
	template <class T> class A
	{
		T mem;
	public:
		A& operator=(const T&);
		friend ostream& operator<<(ostream&, const A&);
	};

	template<class T> A<T>& A<T>::operator=(const T& t)
	{ 
		mem = t; 
		return *this;
	}

	template<class T> ostream& operator<<(ostream& out, const A<T>& a)
	{
		out << a.mem << " (oggetto classe A)";
		return out;
	}

	template <class Q, class T=A<Q> > struct B
	{
		Q mem1;
		T mem2;  
	};
}

int main()
{
	using My_region::B;
	{
		B<double> p;
		cout << (p.mem1 = 66.45) << '\n';
		cout << (p.mem2 = 67.12) << "\n\n";
	}
	{
		B<char> p;
		cout << (p.mem1 = 66.45) << '\n';
		cout << (p.mem2 = 67.12) << "\n\n";
	}
	{
		B<int,char> p;
		cout << (p.mem1 = 66.45) << '\n';
		cout << (p.mem2 = 67.12) << "\n\n";
	}
	return 0;
}

