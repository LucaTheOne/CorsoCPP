#include "date.h"

namespace My_date
{
	const char* mesi[] = {"Gen","Feb","Mar","Apr","Mag","Giu",
		"Lug","Ago","Set","Ott","Nov","Dic"};
	int giorni[] = {31,28,31,30,31,30,31,31,30,31,30,31} ;
	enum Erlev {good, erg, erm, era=4};
	const char Erg[] = "Errore: giorno non valido\n";
	const char Erm[] = "Errore: mese non valido\n";
	const char Era[] = "Errore: anno non valido\n";
	void test(const int&, const int&, const int&);
}

void My_date::date::set(const int& g, const int& m, const int& a)
{
	test(g,m,a);
	giorno = g;
	mese = m;
	anno = a;
}

void My_date::date::get(int& g, const char*& mes, int& a) const
{
	g = giorno;
	mes = mesi[mese-1];
	a = anno;
}

void My_date::test(const int& g, const int& m, const int& a)
{
	Erlev erlev = good;
	if ( a < 1 || a > 3000 ) erlev = era;
	if ( m < 1 || m > 12 )
	{
		erlev = Erlev(erlev|erm);
		if ( g < 1 || g > 31 ) erlev = Erlev(erlev|erg);
	}
	else if ( g < 1 || g > 
		( (m==2 && a%4==0 && (a%100!=0 || a%400==0)) ? 29 : giorni[m-1] )
			 ) erlev = Erlev(erlev|erg);
	if ( erlev != good )
	{
		static Error err;
		err.message[0] = '\0';
		if ( erlev & erg ) err.copymsg(Erg);
		if ( erlev & erm ) err.copymsg(Erm);
		if ( erlev & era ) err.copymsg(Era);
		throw err;
	}
}

void My_date::Error::copymsg(const char* msg)
{
	char* pmes = message;
	while (*pmes++);
	pmes--;
	while (*pmes++ = *msg++);
}