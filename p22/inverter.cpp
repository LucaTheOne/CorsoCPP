#include <stdio.h>

void inverti(char [], int );

int main()
{
	char dato[80];
	do
	{
		printf("Stringa diritta   : ");
		gets(dato);
		printf("Stringa invertita : ");
		inverti(dato,0);
		printf("\n");
	} while ( dato[0] != '0' ) ;
	return 0;
}

void inverti(char stringa[], int index)
{
	if ( stringa[index] )
	{
		inverti(stringa, index+1);
		printf("%c",stringa[index]);
	}
}
