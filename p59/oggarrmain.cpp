#include <iostream.h>
#include "oggarr.h"

int main()
{
	using Oggetto_array::A;
	using Oggetto_array::Error;
	int dimens;
	cout << "Inserisci dimensione: " ; cin >> dimens;
	A a(dimens);

	char answer;
	do
	{
		try
		{
			int i,val;
			cout << "Inserisci indice e valore: "; cin >> i >> val;
			a[i] = val;
			cout << "Continui ? (s/n) ";  cin >> answer;
		}
		catch (Error err)
		{
			if ( err.e < 0 )
				cout << "Errore: indice " << err.e << " negativo\n";
			else
				cout << "Errore: indice " << err.e << " >= "
					<< a.getdim() << '\n';
			answer = 's';
		}
	} while ( answer == 's' );

	&a;

	a.setdim(a.getdim()+4);
	&a;

	a.setdim(a.getdim()-3);
	&a;

	return 0;
}