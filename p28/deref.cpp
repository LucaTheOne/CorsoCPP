#include <iostream.h>

int* pglob;
void funz();
void dummy();

int main()
{
	funz();
	dummy();
	cout << "Nel main la deref. di \"pglob\" e' : " 
	   << *pglob << '\n';
	return 0;
}

void funz()
{
	int val = 10;
	pglob = &val;
    cout << "Nella funzione la deref. di \"pglob\" e' : " 
	   << *pglob << '\n';
	*pglob = 35;
	cout << "....poi e' diventata: " << val << '\n' ;
}

void dummy()
{
	int a[10];
	for (int i=0; i<10; i++) a[i] = i;
}