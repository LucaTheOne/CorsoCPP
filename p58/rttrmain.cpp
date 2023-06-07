#include <iostream.h>
#include <stdio.h>
#include "rttr.h"


int main()
{
	using Punto_sul_piano::point;
	using RotoTraslazione::rttr;
	point p(1,0);
	"Il punto nel sist. di rif. iniziale: "/p;
	cout << "diventa, dopo la rotazione del sistema di ....\n";
	for (int i=45; i<=360; i+=45)
	{
		char str[20];
		sprintf(str,".... %3d gradi : ",i);
		str/(p*rttr(i));
	}

	double x,y;
	cout << "\n\n\nInserisci coordinate di un punto: ";
	cin >> x >> y;
	point pi(x,y);
	double ang,x0,y0;
	cout << "Inserisci angolo di rotazione del sist. di rif.: ";
	cin >> ang;
	cout << "Inserisci coord. dell'origine del nuovo sist. di rif.: ";
	cin >> x0 >> y0;
	rttr rt(ang,x0,y0);
	"\nIl punto, che nel sist. di rif. iniziale e': "/pi;
	"diventa, dopo la rototraslazione di: "/rt;
	"nel nuovo sist. di rif.: "/(pi*rt);
	cout << "\n\n\n\n";
	return 0;
}