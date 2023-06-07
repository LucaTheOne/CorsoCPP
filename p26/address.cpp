#include <iostream.h>
int main()
{
	int a, b;
	cout << "Inserisci due numeri interi: " ;
	cin >> a >> b ;
	cout << "All'indirizzo " << &a << 
		" si trova il numero: " << a << '\n';
	cout << "All'indirizzo " << &b << 
		" si trova il numero: " << b << '\n';
	cout << "All'indirizzo " << &(a+1) << 
		" si trova il numero: " << a+1 << '\n';
	cout << "All'indirizzo " << &(a>b?a:b) << 
		" si trova il numero: " << (a>b?a:b) << '\n';
	return 0;
}
