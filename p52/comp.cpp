#include <iostream.h>
#include "comp.h"

void main()
{
	cout << " ........ Primo oggetto .....\n";
	Compt primo(5,6,7);

	cout << "\n ........ Secondo oggetto .....\n";
	Comp1 ogg1(11);
	Comp2 ogg2(12);
	Compt oggt(13,ogg1,ogg2);
	cout << "\n\n";
}

Comp1::Comp1(const int& d) : me(d)
{
	cout << "Sta costruendo oggetto di Comp1 con " << d 
		<< '\n';
}

Comp1::Comp1(const Comp1& ogg1)
{
	me = ogg1.me +100;
	cout << "Sta costruendo per copia oggetto di Comp1 con " << 
		me << '\n';
}


Comp1::~Comp1()
{
	cout << "Sta distruggendo oggetto di Comp1 con " << me 
		<< '\n';
}

Comp2::Comp2(const int& d) : me(d)
{
	cout << "Sta costruendo oggetto di Comp2 con " << d 
	   << '\n';
}

Comp2::~Comp2()
{
	cout << "Sta distruggendo oggetto di Comp2 con " << me 
		<< '\n';
}

Compt::Compt(const int& dt, const int& d1, const int& d2)  :
   me(dt), me1(d1), me2(d2)
{
	cout << "Sta costruendo oggetto di Compt con " << dt  
		<< '\n';
}

Compt::Compt(const int& d, const Comp1 & ist1, 
		 const Comp2 & ist2)  : me(d), me1(ist1), me2(ist2)
{
	cout << "Sta costruendo oggetto di Compt con " << d  
		<< '\n';
}

Compt::~Compt()
{
	cout << "Sta distruggendo oggetto di Compt con " << me 
		<< '\n';
}


