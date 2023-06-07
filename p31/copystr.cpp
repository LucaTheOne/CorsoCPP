#include <iostream.h>

void copia(char* , char*);

int main()
{
	char s1[] = "Stringa da copiare" ;
	char s2[30] ;
	cout << "\nPuntatore s1 prima della copia: " 
		<< (int*)s1 << '\n' ;
	copia(s1,s2) ;
	cout << "Puntatore s1 (nel main) dopo la copia:     " 
		<< (int*)s1 << '\n' ;
	cout << "Stringa copiata = " << s2 << '\n' ;
	return 0;
}

void copia(char* s1, char* s2)
{
	while ( *s2++ = *s1++ ) ;
	cout << "Puntatore s1 (nella funzione) dopo la copia:     " 
		<< (int*)s1 << '\n' ;
}
	