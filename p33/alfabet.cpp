#include <iostream.h>

#define MINIMO 0
#define MASSIMO 1

char* minmax(int, char*, char*);
char upcase(char);

int main()
{
	char w1[80], w2[80] ;
	do
	{
	cout << "\nInserisci due parole: " ;
	cin >> w1 >> w2 ;
	cout << "In ordine alfabetico \"" << minmax(MINIMO,w1,w2) 
	   << "\" precede \"" << minmax(MASSIMO,w1,w2) << "\"\n" ;
	} while ( w1[0] != '/' ) ;
	return 0;
}

char* minmax(int sw, char* w1, char* w2)
{
	char* temp1;
	char* temp2;
	for( temp1=w1,temp2=w2 ;
		 *temp1 && upcase(*temp1)==upcase(*temp2);
		 temp1++, temp2++ )  ;
	if ( upcase(*temp1) <= upcase(*temp2) )
		return sw==MINIMO ? w1 : w2 ;
	else  return sw==MASSIMO ? w1 : w2 ;
}

char upcase(char letter)
{
	return letter >= 'a' && letter <= 'z' ? letter-32 : letter;
}