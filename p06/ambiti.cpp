#include <stdio.h>
int MiaVar = 100;
void main()
{
	int MiaVar = 30;
	{
		int MiaVar = 20;
		printf("\"MiaVar\" globale : %d\n",::MiaVar);
		printf("\"MiaVar\" locale interna : %d\n",MiaVar);
	}
	printf("\"MiaVar\" locale esterna : %d\n",MiaVar);
}
