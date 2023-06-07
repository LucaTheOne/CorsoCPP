#include <iostream.h>

namespace per_non_duplicare_nomi
{
	class Base
	{
		int mem;
	public :
		Base(int);
		virtual Base* clone();
		virtual void where();
		virtual ~Base();
	};

	class A : public Base
	{
		int mem;
	public :
		A(int);
		Base* clone();
		void where();
		~A();
	};

	class B : public A
	{
		int mem;
	public :
		B(int);
		Base* clone();
		void where();
		~B();
	};

	class X : public Base
	{
		int mem;
	public :
		X(int);
		Base* clone();
		void where();
		~X();
	};

	class Y : public X
	{
		int mem;
	public :
		Y(int);
		Base* clone();
		void where();
		~Y();
	};
}