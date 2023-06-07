#include "virtuali.h"


namespace per_non_duplicare_nomi
{
	Base::Base(int m) : mem(m)
	{ 
		cout << "\nCostruttore di Base con valore " << m << '\n';
	}

	A::A(int m) : mem(m), Base(m)
	{ 
		cout << "Costruttore di A con valore " << m << '\n';
	}

	B::B(int m) : mem(m), A(m)
	{ 
		cout << "Costruttore di B con valore " << m << '\n';
	}

	X::X(int m) : mem(m), Base(m)
	{ 
		cout << "Costruttore di X con valore " << m << '\n';
	}

	Y::Y(int m) : mem(m), X(m)
	{ 
		cout << "Costruttore di Y con valore " << m << '\n';
	}

	Base* Base::clone()
	{
		return new Base(*this);
	}

	Base* A::clone()
	{
		return new A(*this);
	}

	Base* B::clone()
	{
		return new B(*this);
	}

	Base* X::clone()
	{
		return new X(*this);
	}

	Base* Y::clone()
	{
		return new Y(*this);
	}

	void Base::where()
	{
		cout << "Oggetto Base: valore = " << mem << '\n';
	}

	void A::where()
	{
		cout << "Oggetto A: valore = " << mem << '\n';
	}

	void B::where()
	{
		cout << "Oggetto B: valore = " << mem << '\n';
	}

	void X::where()
	{
		cout << "Oggetto X: valore = " << mem << '\n';
	}

	void Y::where()
	{
		cout << "Oggetto Y: valore = " << mem << '\n';
	}

	Base::~Base()
	{
		cout << "Distruttore di Base\n" ;
	}

	A::~A()
	{
		cout << "Distruttore di A\n" ;
	}

	B::~B()
	{
		cout << "Distruttore di B\n" ;
	}

	X::~X()
	{
		cout << "Distruttore di X\n" ;
	}

	Y::~Y()
	{
		cout << "Distruttore di Y\n" ;
	}
}
