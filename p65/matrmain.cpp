#include <stdlib.h>
#include <time.h>
#include "matr.h"

int main()
{
	const int cicli = 100000000;
	int i,ini;
	using spazio_matrici::Matrix;
	using spazio_matrici::Matrice;
	srand(time(NULL));
	Matrix Mx1,Mx2,Mx3;
	Matrice Me1(Mx1),Me2(Mx2),Me3(Mx3);

	Matrix Mx(false);
	cout << "Tempo impiegato con le operazioni ottimizzate: " << flush;
	ini = time(NULL);
	for (i=0; i < cicli; i++) Mx = Mx1*Mx2+Mx3;
	cout << time(NULL) - ini << " secondi\n";

	Matrice Me;
	cout << "Tempo impiegato con le operazioni non ottimizzate: " << flush;
	ini = time(NULL);
	for (i=0; i < cicli; i++) Me = Me1*Me2+Me3;
	cout << time(NULL) - ini << " secondi\n";

	cout << "Valori medi: Mx = " << Mx << "    Me = " << Me << "\n\n\n";

	cout << "Numero oggetti Matrix creati:  " << Matrix::nog
		<< '\n';
	cout << "Numero operazioni Matrix:  " << Matrix::nop
		<< "\n\n";
	cout << "Numero oggetti Matrice creati di default: " 
		<< Matrice::def	<< '\n';
	cout << "Numero oggetti Matrice creati per copia da Matrix: " 
		<< Matrice::cmx	<< '\n';
	cout << "Numero oggetti Matrice creati per copia : " 
		<< Matrice::cop	<< '\n';
	cout << "Numero oggetti Matrice assegnati: " 
		<< Matrice::ass	<< '\n';
	cout << "Numero moltiplicazioni Matrice: " 
		<< Matrice::mul	<< '\n';
	cout << "Numero addizioni Matrice: " 
		<< Matrice::sum	<< "\n\n\n";
	return 0;
}
