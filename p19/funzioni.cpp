#include <iostream.h>

void mostra_numeri(int first, int last)
{
	int primo,ultimo;
	primo = first <= last ?  first : last;
	ultimo = first <= last ?  last : first;
	int conta = 0, n = primo;
	while ( n <= ultimo )
	{
		if ( conta++ % 10 == 0 ) cout << "\n\t" ;
		cout << n++ << ' ' ;
	}
	cout << '\n';
}

void mostra_lettere(unsigned char first, unsigned char last)
{
	unsigned char primo,ultimo;
	primo = first <= last ?  first : last;
	ultimo = first <= last ?  last : first;
	primo = primo < 33 ? 33 : primo > 126 ? 126 : primo	 ;
	ultimo = ultimo < 33 ? 33 : ultimo > 126 ? 126 : ultimo;
	for( char n=primo; n<=ultimo; n++ )	 cout << n ;
	cout << '\n' ;
}