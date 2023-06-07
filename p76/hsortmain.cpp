#include <stdlib.h>
#include <time.h>
#include "hsort.h"

template <class T> void riprova(int n, T* d1, T* d2)
{
	int i=0;
	while( i<n && d1[i]==d2[i] ) i++;
	if ( i == n ) cout << "RISULTATI IDENTICI\n";
	else cout << "CHE STRANO .... RISULTATI DIVERSI!\n";
}
	      
int main()
{
	using My_region::sort;
	using My_region::vector;
	using My_region::hvector;
	using My_region::Shell;
	using My_region::Comb;
	srand(time(NULL));
	int i;
{
	const int numel = 6000;
	cout << "\nArray di " << numel << " vector -----------------" << endl;
	vector d1[numel], d2[numel];
	for (i=0; i < numel; i++) d2[i] = d1[i];
	sort<Shell<vector> >(numel,d1);
	sort<Comb<vector> >(numel,d2);
	riprova(numel,d1,d2);
}
	const int numel = 6000;
	cout << "\nArray di " << numel << " hvector -----------------" << endl;
	hvector d1[numel], d2[numel];
	for (i=0; i < numel; i++) d2[i] = d1[i];
	sort<Shell<hvector> >(numel,d1);
	sort<Comb<hvector> >(numel,d2);
	riprova(numel,d1,d2);

	return 0;
}


