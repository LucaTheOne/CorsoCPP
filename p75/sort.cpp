#include <stdlib.h>
#include "sort.h"

namespace My_region
{

	double conversione = 20.0/RAND_MAX;
	int num_cicli;
	int num_scambi;

	vector::vector()
	{
		num = rand() % 10 + 20;
		v = new double [num];
		varianza = 0.0;
		for ( int i=0; i < num; i++)
		{
			v[i] = rand()*conversione-10.0;
			varianza += v[i]*v[i];
		}
		varianza /= num;
	}

	vector::vector(const vector& vec)
	{
		num = vec.num;
		varianza = vec.varianza;
		v = new double [num];
		for ( int i=0; i < num; i++) v[i] = vec.v[i];
	}

	vector::~vector()
	{
		delete [] v;
	}

	vector& vector::operator =(const vector& vec)
	{
		if (this == &vec) return *this; //in caso di auto-assegnazione
		if ( num != vec.num )
		{
			delete [] v;
			num = vec.num;
			v = new double [num];
		}
		varianza = vec.varianza;
		for ( int i=0; i < num; i++) v[i] = vec.v[i];
		return *this;
	}

	bool operator<(const vector& vec1, const vector& vec2)
	{
		return vec1.varianza < vec2.varianza;
	}

	bool operator==(const vector& vec1, const vector& vec2)
	{
		if ( vec1.varianza != vec2.varianza ) return false;
		if ( vec1.num != vec2.num ) return false;
		int i=0;
	    while( i < vec1.num && vec1.v[i] == vec2.v[i] ) i++;
		return i == vec1.num;
 	}
}
