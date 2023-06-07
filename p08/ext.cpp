#include <stdio.h>
void main()
{
	extern int var_senza_ini;
	extern int var_con_ini;
	extern const int costante;
	extern int var_static;
	printf("Valore di \"var_senza_ini\" = %d\n",var_senza_ini);
	printf("Valore di \"var_con_ini\" = %d\n",var_con_ini);
	printf("Valore di \"costante\" = %d\n",costante);
	printf("Valore di \"var_static\" = %d\n",var_static);
}
