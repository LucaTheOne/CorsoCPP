#include <stdio.h>
void scrivi()
{
	int a = 10;
	static int b = 10;
	printf("Valore di a = %d\n",a);
	printf("Valore di b = %d\n",b);
	a = a+1;
	b = b+1;
}
void main()
{
	static bool Vera_o_Falsa;
	if ( Vera_o_Falsa )
	 printf("Una variabile booleana statica e' inizializzata di default true\n");
	else
	 printf("Una variabile booleana statica e' inizializzata di default false\n");
	scrivi();
	scrivi();
	scrivi();
}