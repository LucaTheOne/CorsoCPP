#include <iostream.h>

void funz(int, int*);

int main()
{
	int a=10,b=10 ;
	cout << '\n' ;
	cout << "Prima della chiamata:\ta=" << a 
		<< "   b=" << b << '\n'  ;
	funz(a,&b);
	cout << "Dopo la chiamata:    \ta=" << a 
		<< "   b=" << b << '\n'  ;
	return 0;
}

void funz(int val, int* add)
{
	val += 5 ;
	*add += 5 ;
	cout << "Nella funzione:     \ta=" << val 
		<< "   b=" << *add << '\n'   ;
}
	