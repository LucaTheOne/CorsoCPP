#include <iostream.h>
#include <stdlib.h>
#include <time.h>

double media(double []);
const int NUMERO = 100 ;

int main()
{
#define NUMERO 15
#ifndef NUMERO
	int a=0;
	a+1 = a;  // istruzione sbagliata che il compilatore non vede
#endif
	double NumeroCasuale[NUMERO];
	double conversione = 10./RAND_MAX;
	srand(time(NULL));
	for (int ind=0; ind < NUMERO; ind++) 
		NumeroCasuale[ind] = rand() * conversione;
	cout << "Valore casuale medio = " 
		<< media(NumeroCasuale) << '\n';
	cout << "Media calcolata su " << NUMERO << " dati\n";
	cin >> conversione; //questa lettura serve per non fare 
	//                    uscire il programma in debug
	return 0;
}

double media(double a[])
{
	double s = 0.0;
	for (int i = 0; i < NUMERO ; i++)  
	{
		s += a[i] ;
#ifdef _DEBUG
		cout << "Valore dell'elemento " << i << " =\t"
			<< a[i] << '\n';
#endif
	}
	s /= NUMERO;
#undef NUMERO
	cout << "Nuovo valore di NUMERO: "  << NUMERO << '\n';
	return s;
}
