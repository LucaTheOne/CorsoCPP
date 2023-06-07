#include <stdlib.h>
#include <time.h>
#include "except.h"

namespace My_exception
{
	double conversione = 10./RAND_MAX;
}

void My_exception::ricors(int lev, int rantot)
{
	if ( lev == 0 ) srand(time(NULL));
	lev++;
	rantot += int(rand()*conversione);
	if ( rantot >= 100 )
	{
		Exception exobj;
		exobj.casual = rantot;
		exobj.level = lev;
		throw exobj;
	}
	ricors(lev,rantot);
}
