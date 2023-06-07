#include <iostream.h>
#include "static.h"

namespace My_region
{
	double Valori::defval = 0.45;
	void Valori::changedef(const double& newdef)
	{
		defval = newdef;
	}
	void Valori::init()
	{
		for (int i=0; i < 5; i++) val[i] = defval;
	}
	double& Valori::access(int index)
	{
		if ( index < 0 || index > 4 ) throw Error();
		return *(val+index);
	}
}

