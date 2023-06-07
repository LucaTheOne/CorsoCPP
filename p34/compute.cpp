#include <iostream.h>

double somma(double d1, double d2) { return d1+d2;}
double differenza(double d1, double d2) { return d1-d2;}
double prodotto(double d1, double d2) { return d1*d2;}
double rapporto(double d1, double d2) { return d1/d2;}

double (*calc)(double, double);

int main()
{
	char s;
	double dati1[] = { 3.4, 1.7, 0.6, 4.3, 3.8 } ;
	double dati2[] = { 1.6, 7.3, 4.5, 1.7, 3.8 } ;
	cout << "Operazione: " ;  cin >> s;
	switch(s)
	{
		case '-' : calc = differenza; break;
		case '*' : calc = prodotto; break;
		case '/' : calc = rapporto; break;
		default  : calc = somma;  s = '+' ;
	}
	for (int i=0; i < 5; i++)
		cout << '\t' << dati1[i] << ' ' << s  << ' '
		     << dati2[i] << "  =\t" << calc(dati1[i],dati2[i])
			 << '\n' ;
	return 0;
}