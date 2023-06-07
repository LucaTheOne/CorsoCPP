#include <stdio.h>
#include <stdlib.h>
#include "listin.h"

namespace My_region
{
	class Bin
	{
		int min;
		int max;
		int num;
		Bin(const int&, const int&);
		void insert();
		friend class Bins;
	};
}

My_region::Bin::Bin(const int& m, const int& n) 
      : min(m), max(n), num(0)
{ }

void My_region::Bin::insert() { num++; }

My_region::Bins::Bins(const int& n) : nBin(n), ntot(0)
{
	if ( n < 3 || n > 10 ) throw Error();
	pBin = new Bin* [n];
	int max, min=0;
	for (int i=0; i < n; i++)
	{
		max = rand() % 10 + 1 + min;
		*(pBin+i) = new Bin(min,max);
		min = max+1;
	}
	maxmax = min;
}

My_region::Bins::~Bins()
{
	for (int i=0; i < nBin; i++) delete *(pBin+i);
	delete [] pBin;
}

void My_region::Bins::insert(const int& val)
{
	int inval = val % maxmax;
	for (int i=0; inval > (*(pBin+i))->max; i++);
	(*(pBin+i))->insert();
	ntot++;
}

void My_region::Bins::show()
{
	double perc_norm = 100.0*maxmax/ntot/nBin;
	for (int i=0; i < nBin; i++)
	{
		Bin* p = *(pBin+i);
		int min = p->min, max = p->max, num = p->num;
		printf("%2d - %2d%10d (%d%%)\n",min,max,num,
			int(perc_norm*num/(max-min+1)+0.5));
	}
}

My_region::Error::Error() 
	: descr("Il numero deve essere compreso fra 3 e 10\n")
{
}