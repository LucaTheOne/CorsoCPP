#include <stdlib.h>
#include <time.h>
#include "sort.h"

template <class T> void riprova(int n, T* d1, T* d2, T* d3)
{
	int i=0;
	while( i<n && d1[i]==d2[i] && d1[i]==d3[i] ) i++;
	if ( i == n ) cout << "RISULTATI IDENTICI\n";
	else cout << "CHE STRANO .... RISULTATI DIVERSI!\n";
}
	      
int main()
{
	using My_region::sort;
	using My_region::vector;
	using My_region::Shift;
	using My_region::Shell;
	using My_region::Comb;
	srand(time(NULL));
	int i;

{
	const int numel = 30000;
	cout << "\nArray di " << numel << " int -----------------\n";
	int d1[numel], d2[numel], d3[numel];
	for (i=0; i < numel; i++)
	{
		d1[i] = rand();
		d2[i] = d1[i];
		d3[i] = d1[i];
	}
    sort<Shift<int> >(numel,d1);
	sort<Shell<int> >(numel,d2);
	sort<Comb<int> >(numel,d3);
	riprova(numel,d1,d2,d3);
}

{
	const int numel = 30000;
	cout << "\nArray di " << numel << " double -----------------\n";
	double d1[numel], d2[numel], d3[numel];
	for (i=0; i < numel; i++)
	{
		d1[i] = rand()/1000.;
		d2[i] = d1[i];
		d3[i] = d1[i];
	}
	sort<Shift<double> >(numel,d1);
	sort<Shell<double> >(numel,d2);
	sort<Comb<double> >(numel,d3);
	riprova(numel,d1,d2,d3);
}

	const int numel = 6000;
	cout << "\nArray di " << numel << " vector -----------------" << endl;
	vector d1[numel], d2[numel], d3[numel];
	for (i=0; i < numel; i++)
	{
		d2[i] = d1[i];
		d3[i] = d1[i];
    }
    sort<Shift<vector> >(numel,d1);
	sort<Shell<vector> >(numel,d2);
	sort<Comb<vector> >(numel,d3);
	riprova(numel,d1,d2,d3);

	return 0;
}


