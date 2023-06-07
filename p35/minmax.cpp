#include <iostream.h>

bool max_compare(double a, double b) { return a > b  ; }
bool min_compare(double a, double b) { return a < b  ; }

bool get_value(double*&);
double get_min_max( double*, int, bool (*)(double,double) );

int main()
{
	double valori[100] ;
	double* pval = valori;
	cout << "Inserisci i valori (termina con /):\n\t" ;
	while ( pval-valori < 100 )  if (!get_value(pval)) break;
	int dim = pval-valori;
	cout << "Il massimo dei " << dim << " valori inseriti e': "
		 << get_min_max(valori,dim,max_compare) << '\n';
	cout << "Il minimo  dei " << dim << " valori inseriti e': "
		 << get_min_max(valori,dim,min_compare) << '\n' << '\n';
	return 0;
}

bool get_value(double*& pval)
{
	int status;
	char extrach;
	do
	{
		cin >> *pval;
		status = cin.rdstate();
		if ( status )
		{
			cin.clear();
			cin >> extrach;
			if ( extrach == '/' )  return false;
		}
	}  while (status) ;
	pval++;                        return true;
}

double get_min_max( double* pval, int dim, 
				  bool (*comp)(double,double) )
{
	double ris = *pval++;
	for(int i=1; i < dim; i++,pval++) 
		ris = comp(*pval,ris)? *pval : ris;
	return ris;
}
		
		
