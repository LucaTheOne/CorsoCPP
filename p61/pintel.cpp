#include <iostream.h>
#include <stdio.h>
#include "pintel.h"

tipodouble* Ptr::operator->()
{
	if ( newval == 0.0 )
	{
		if ( plast == NULL ) throw
			Error("Non ci sono dati inseriti\n");
		else return plast;
	}
	tipodouble* pcur = pfirst, * pprev;
	while ( pcur && pcur->valore < newval )
	{
		pprev = pcur;
		pcur = pcur->next;
	}
	if ( pcur && pcur->valore == newval )
	{
		char erm[80];
		sprintf(erm,"Valore %f duplicato\n",newval);
		newval = 0.0;
		throw Error(erm);
	}
	tipodouble* pnew = new tipodouble;
	pnew->next = pcur;
	if ( pcur == pfirst )
	{
		if ( pfirst == NULL ) plast = pnew;
		pfirst = pnew;
	}
	else
	{
		pprev->next = pnew;
		if ( pcur == NULL ) plast = pnew;
	}
	newval = 0.0;
	return pnew;
}

double Ptr::operator()(int rw)
{
	switch(rw)
	{
	case READ :
		cin >> newval;
		if ( newval == 0.0 ) throw Error("0");
		return newval;
	case WRITE :
		cout << "\nNumeri inseriti: ";
		tipodouble* pcur = pfirst;
		while (pcur)
		{
			cout << pcur->valore << ' ';
			pcur = pcur->next;
		}
		cout << "\n\n\n";
	}
	return 0.0;
}

Ptr::~Ptr()
{
	tipodouble* pnext;
	while ( pfirst )
	{
		pnext = pfirst->next;
		delete pfirst;
		pfirst = pnext;
	}
}
