#include <iostream.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	double NumeroCasuale[100];
	cout << "L'array \"NumeroCasuale\" occupa "
		 << sizeof(NumeroCasuale) << " bytes" << "\n\n";
	double conversione, media=0.0;
	int ind;

	srand(time(NULL));
	conversione = 10./RAND_MAX;
	for (ind=0; ind<100; ind++) 
	{
		NumeroCasuale[ind] = rand() * conversione;
		media += NumeroCasuale[ind];
	}
	media /= 100.;
	cout << "Valore casuale medio = " << media << "\n\n";

	conversione = 99.99/RAND_MAX;
	for ( int i = 0; i < 10 ; i++)
	{
		ind = (int)(rand()*conversione);
		cout << "Numero Casuale(" << ind << ") = " <<
			NumeroCasuale[ind] << '\n';
	}
	cout << "\n\n\n";
}