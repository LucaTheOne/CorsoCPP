#include <iostream.h>
#include "frttr.h"


int main()
{
	using Punto_sul_piano::point;
	using RotoTraslazione::rttr;

	int i;
	point p[8];
	rttr r(-45.);
	p[0] = point(1.,0.);
	for (i=1; i<8; i++) p[i] = r(p[i-1]);

	double ang,x0,y0;
	cout << "Inserisci angolo di rotazione del sist. di rif.: ";
	cin >> ang;
	cout << "Inserisci coord. dell'origine del nuovo sist. di rif.: ";
	cin >> x0 >> y0;
	rttr rtd(ang,x0,y0);
	rttr rti = !rtd;
	cout << "\nTrasf. diretta : " << rtd;
	cout << "Trasf. inversa : " << rti;
	cout << "\nCoordinate iniziali\tdopo trasf. diretta" <<
		"\tdopo trasf. inversa\n";
	for (i=0; i<8; i++)
	{
		point temp;
		cout << p[i] << '\t' << (temp=rtd(p[i])) << '\t'
		<< rti(temp) <<'\n';
	}
	return 0;
}