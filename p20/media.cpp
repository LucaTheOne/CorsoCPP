#include <iostream.h>

double average(int , double []);

int main()
{
	int num,i;
	double valori[10];
	cout << "Quanti dati ? " ;    cin >> num;
	cout << "Inseriscili : ";
	for (i =0; i<num && i <10 ; i++ ) cin >> valori[i];
	num = i;
	cout << "Valore medio: " << average(num,valori) << '\n';
	cout << "Per fortuna i dati sono rimasti: "<< num << '\n';
	cout << "Pero' i loro valori sono diventati:\n\t" ;
	for ( i=0; i < num; i++ ) cout << valori[i] << ' ';
	cout << '\n';
	return 0;
}

double average(int num, double dati[])
{
	double s = 0.;
	for ( int i=0; i<num; i++ ) 
	{
		s += dati[i];
		dati[i] = 0.;
	}
	s /= num;
	num = 1000 ;
	cout << "Aiuto, i dati sono diventati " << num 
		<< " !!!\n" ;
	return s;
}