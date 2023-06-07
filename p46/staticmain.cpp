#include <iostream.h>
#include "static.h"

namespace My_region
{
	void printv(const int& objnum, Valori* v)
	{
		int index = 0;
		try
		{
			cout << "Valori oggetto " << objnum << ": ";
			while (true) cout << (v+objnum)->access(index++) << ' ';
		}
		catch (Error) { }
		cout << '\n';
	}
}


int main ()
{
	using My_region::Valori;
	using My_region::Error;
	using My_region::printv;
	Valori v[2];
	v[0].init();
	double newdef;
	cout << "Nuovo default per la classe Valori: "; cin >> newdef;
	Valori::changedef(newdef);
	v[1].init();
	printv(0,v);
	printv(1,v);
	cout << '\n';
	int objnum, index;
	double val;
	char answer;
	do
	{
		cout << "Oggetto (0/1), indice del valore, nuovo valore: ";
		cin >> objnum >> index >> val;
		if ( objnum <0 || objnum > 1 )
			cout << "Errore: l'oggetto deve essere 0 o 1\n";
		else
		{
			try
			{
				(v+objnum)->access(index) = val;
				printv(objnum,v);
			}
			catch (Error)
			{
				cout << "Errore: indice del valore fuori dal range\n";
			}
		}
		cout << "\nContinui ? (s/n) ";  cin >> answer;
	} while ( answer == 's' );
	return 0;
}