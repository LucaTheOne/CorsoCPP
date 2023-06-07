#include <iostream.h>
#include <stdarg.h>

void miniprintf(char [],...);
/* questa funzione opera come la printf, salvo che
riconosce solo gli specificatori %d e %f  */

int main()
{
	miniprintf("Srittura senza argomenti opzionali\n");
	miniprintf("Il numero %d e' intero\n",23);
	miniprintf("floating: %f ;	  intero: %d\n",3.4,18);
	return 0;
}

void miniprintf(char control[],...)
{
	va_list marker;
	bool opt = false;
	va_start(marker,control);         // punta agli arg. opzionali
	for (int i=0; control[i] ; i++)
		if ( opt )
		{
			switch	( control[i] )
			{
				case 'd': cout << va_arg(marker,int) ;
						  break;
				case 'f': cout << va_arg(marker,double);
						  break;
				default : cout << '%' << control[i] ;
			}
			opt = false;
		}
		else
		{
			opt =  control[i] == '%' ;
			if ( !opt  ) cout << control[i] ;
		}
	if ( opt ) cout << '%' ;
	va_end(marker);
}