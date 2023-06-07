#include <stdio.h>
void main()
{
	printf("Scrivo il numero 111 in ottale ed esadecimale: %o %X\n",111,111);
	printf("Interpreto il numero -1 con segno e senza segno: %d %u\n",-1,-1);
	printf("Scrivo il numero 27.12 in modo normale \
ed esponeziale: %f %e\n",27.12,27.12);
	printf("Se lascio scegliere a lui, come scrivera' 3.45 ?: %g\n",3.45);
	printf("E invece il numero 0.00000001 ?: %G\n",0.00000001);
	printf("Ora scrivo il carattere A e il suo codice ASCII: %c %d\n",65,65);
	printf("E infine scrivo questa stringa: %s\n","Ciao a tutti!");
}