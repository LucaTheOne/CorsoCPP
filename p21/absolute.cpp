#include <iostream.h>

int abs(int n) {  return n >= 0 ? n : -n ; }
double abs(double f) {  return f >= 0.0 ? f : -f ; }

int main()
{
	int intero;
	double floating;
	cout << "Scrivi un numero int e uno double: " ;
	cin >> intero >> floating ;
	cout << "Il valore assoluto di " << intero 
		<< " e': " << abs(intero) << '\n';
	cout << "Il valore assoluto di " << floating 
		<< " e': " << abs(floating) << '\n';
	return 0;
}

