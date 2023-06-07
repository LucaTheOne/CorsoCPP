#include <stdio.h>
void main()
{
	char MioChar;
	char MiaStr[] = "Pippo";
	MioChar = 'A' + 1;
	printf("Codice del carattere A : %d\n",'A'); 
	printf("MioChar = %c (codice %d)\n",MioChar,MioChar);
	printf("Dimensioni di MioChar = %d\n",sizeof(MioChar));
	printf("Dimensioni di Pippo = %d\n",sizeof(MiaStr));
}

