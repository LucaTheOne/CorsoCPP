#include <iostream.h>
bool n1 , n2;
void percorsi()
{
	if ( n1 )  cout << "\nPrimo vero, " ;
	else cout << "\nPrimo falso, ";
	if ( n2 ) cout << "secondo vero\n";
	else    cout << "secondo falso\n";

	if ( n1 )
		if (n2)	cout << "Primo percorso\n" ;	   
	else
		cout << "Secondo percorso\n";
}
void main()
{
	n1 =  true;  n2 =  true;  percorsi();
	n1 =  true;  n2 = false;  percorsi();
	n1 = false;  n2 =  true;  percorsi();
	n1 = false;  n2 = false;  percorsi();
	cout << "\n\n\n\n";
}
