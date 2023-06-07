#include <iostream.h>
int main()
{
	double val[] = { 1.1, 2.2, 3.3, 4.4, 5.5} ;
	double* dpoint = &val[0];
	cout << '\n';
	for (int i=0; i < 5 ; i++ )
		cout << "Indirizzo dell'elemento con indice " << i << ": " 
			<< dpoint+i << "\tValore: " << val[i] << '\n' ;
	return 0;
}