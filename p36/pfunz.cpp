#include <iostream.h>
typedef void (*tpf)(int&, int&);
void fsel1(tpf);
void fsel2(tpf);
void funz1(int&, int&);
void funz2(int&, int&);

int main()
{
	fsel1(funz1);
	fsel1(funz2);
	fsel2(funz1);
	fsel2(funz2);
	return 0;
}

void fsel1(tpf pf)
{
	cout << "Funzione chiamante 1" << '\n';
	int a =27;
	int b = 45;
	pf(a,b);
	cout << "a = " << a << "    b = " << b << '\n';
}

void fsel2(tpf pf)
{
	cout << "Funzione chiamante 2" << '\n';
	int a =14;
	int b = 32;
	pf(a,b);
	cout << "a = " << a << "    b = " << b << '\n';
}

void funz1(int& a, int& b)
{
	cout << "Funzione vera 1" << '\n';
	a++;
	b--;
}

void funz2(int& a, int& b)
{
	cout << "Funzione vera 2" << '\n';
	a--;
	b++;
}

