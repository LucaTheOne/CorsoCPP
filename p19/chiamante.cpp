#include <iostream.h>
#include "prototipi.h"
void main()
{
	int n1,n2;
	cout << "Digita 2 numeri, estremi dell'intervallo: ";
	cin >> n1 >> n2;
	cout << "Lista dei numeri :" ;
	mostra_numeri(n1,n2);

	unsigned char c1,c2;
	cout << "\nDigita 2 lettere, estremi dell'intervallo: ";
	cin >> c1 >> c2;
	cout << "Lista delle lettere :\n\t" ;
	mostra_lettere(c1,c2);
	cout << "\n\n\n";
}