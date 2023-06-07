#include <iostream.h>

class Base 
{
  protected: int m;
  public:
	Base(int);
	~Base();
	void display();
} ;

class Derivata : public Base 
{
	int f;
  public :
	Derivata(int,int);
	~Derivata();
	void display();
} ;

Base::Base(int d) : m(d) 
{
	cout << "Costruita la Base" << '\n';
}

Base::~Base()  
{
	cout << "Distrutta la Base" << '\n' ;
}

void Base::display()
{
	cout << "m = " << m << '\n';
}

Derivata::Derivata(int d1, int d2) : f(d1),	 Base(d2)
{
	cout << "Costruita la Derivata" << '\n';
}

Derivata::~Derivata()
{
	cout << "Distrutta la Derivata" << '\n' ;
}

void Derivata::display()
{
	Base::display();
	cout << "f = " << f << '\n';
}


int main()
{
	Derivata fm(3,4);
	fm.display();
	return 0;
}



