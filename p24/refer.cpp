#include <iostream.h>

int& cambia(int&, int, bool=false);

int globale;

int main()
{
	int a=10, b=20;
	cout << "Valori di a e b prima: " << a << ' ' << b << '\n';
	cout << "Vede statica : " << cambia(a,b) << '\n' ;
//	cout << "Vede statica : " << statica << '\n' ;
//          errore: statica non è dichiarato nell'ambito del main
	cout << "Valori di a e b  dopo: " << a << ' ' << b << '\n';
	cambia(a,b) = globale;
	cambia(a,b,true);
	return 0;
}

int& cambia(int& refer, int value, bool show_static)
{
	static int statica = 30;
	if (show_static) cout << "Valore di statica : " 
		<< statica << '\n';
	refer++;
	value++;
	globale++;
	return statica;
}
