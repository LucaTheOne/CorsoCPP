#include <iostream.h>
#include "oggarr.h"

using Oggetto_array::A;
using Oggetto_array::Error;

A::A(int n)
{
	if ( n < 2 ) n = 2;
	arr = new int [n];
	for (int k=0; k < n; k++) arr[k] = 0;
	dim = n;
}

A::~A()
{
	delete [] arr;
}

int& A::operator[](const int& i)
{
	if ( i < 0 || i >= dim ) throw Error(i);
	return arr[i];
}

void A::setdim(int n)
{
	if ( n < 2 ) n = 2;
	if ( n > dim )
	{
		int* newarr = new int [n];
		int k;
		for (k=0; k < dim; k++) newarr[k] = arr[k];
		while (k < n) newarr[k++] = 0;
		delete [] arr;
		arr = newarr;
	}
	dim = n;
}

void A::operator&()
{
	cout << "Oggetto: " << *this << " di " << dim << 
		" elementi\n";
}

ostream& Oggetto_array::operator<<(ostream& out, const A& a)
{
	out << '(';
	for (int k=0; k < a.dim-1; k++) out << a.arr[k] << ',';
	out << a.arr[a.dim-1] << ')';
	return out;
}
