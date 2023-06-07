# include <stdio.h>
void main()
{
	printf("La lunghezza del tipo char e' %d byte\n",sizeof(char));
	printf("La lunghezza del tipo short e' %d byte\n",sizeof(short));
	printf("La lunghezza del tipo int e' %d byte\n",sizeof(int));
	printf("La lunghezza del tipo long e' %d byte\n",sizeof(long));
	printf("La lunghezza del tipo float e' %d byte\n",sizeof(float));
	printf("La lunghezza del tipo double e' %d byte\n",sizeof(double));
	printf("La lunghezza del tipo long double e' %d byte\n",
		sizeof(long double));
	printf("La lunghezza del tipo bool e' %d byte\n",sizeof(bool));
}
