#include <stdio.h>
void main()
{
	//  ampiezza e precisione
	printf("Temperatura della sauna (rotta):%7.1f gradi\n\n",
		107.86);

	//  ampiezza e precisione parametrizzate
	printf("Pi greco:%*.*f\n\n",7,4,3.14159265);

	//  precisione applicata a numeri interi
	printf("Data di nascita:%3.2d -%3.2d -%3.2d\n\n",4,5,1970);

	//  cifre decimali e significative
	printf("3 cifre decimali con il formato f: %.3f\n",1.5678);
	printf("3 cifre significative con il formato g: %.3g\n\n",1.5678);

	//  ampiezza e precisione applicate alle stringhe
	printf("Ampiezza=minimo numero caratteri del campo:%8s\n","pippo");
	printf("Precisione=massimo numero caratteri della stringa:%.5s\n",
		"gelsomina");
	printf("Ampiezza e precisione insieme:%10.5s\n\n","gelsomina");

	//  uso dello specificatore +
	printf("Il mio conto in banca e' di %+d lire\n\n",27000);

	//  filling di zeri a sinistra
	printf("Numero di inventario: %05d\n\n",43);

	// allineamento
	printf("A sinistra: --->%-10d<-----\nDefault a destra: \
--->%10d<-----\n\n",132457,132457);

	//  decimale, ottale, esadecimale
	printf("%4d decimale = %#o ottale = %#x esadecimale\n\n",
		784,784,784);

	// funzione come argomento
	printf("La frase precedente contiene %d caratteri\n",
		printf("Mi mancano %d lire\n",1000));
}