#include <stdio.h>
void main()
{
	int result,a=2,b=3,c=3;
	result = 3*a+++ ++b/2-2*c--;
	printf("\n\nRisultato: %d (in a,b,c: %d,%d,%d)\n\n\n",result,a,b,c);
}