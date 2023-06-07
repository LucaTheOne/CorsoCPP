#include <iostream.h>
int main()
{
	int array[] = { 1, 2, 3, 4, 5 } ;
	int* pointer;
	cout << "\nValori \"puntati\":" ;
	for ( pointer = array; pointer < array+5 ; pointer++ )
		cout << "   " << *pointer ;
	cout << '\n' ;
	
	char s1[] = "Stringa dichiarata come array" ;    
//	s1 += 2;                  // questa istruzione é sbagliata 
	s1[5] = 'c';
	cout << s1 << '\n' ; 

	char* s2  = "Stringa dichiarata come puntatore" ;
	s2 += 2;                  // questa istruzione é corretta !!!
	*s2 = 'h';                // questa potrebbe dare access violation
	cout << s2 << '\n' ; 
	return 0;
} 
