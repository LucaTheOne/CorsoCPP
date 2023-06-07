#include <iostream.h>

class arri
{
	int m1;
	int m2;
public:
	arri() : m1(1), m2(2)
		{ cout << "Costruttore di default\n";}
	arri(const int& i, const int& j=4) : m2(i), m1(j)
		{ cout << "Costruttore con argomenti\n";}
	static void show(const int&, const arri*);
};

void arri::show(const int& n, const arri* a)
{
	int i;
	cout << "Membro m1: ";
	for (i=0; i<n; i++) cout << (a+i)->m1 << ' ';
	cout << '\n';
	cout << "Membro m2: ";
	for (i=0; i<n; i++) cout << (a+i)->m2 << ' ';
	cout << '\n';
}

int main()
{
	cout << " .......... singolo di default .............\n";
	arri sd;
	arri::show(1,&sd);

	cout << "\n .......... singolo con argomenti .............\n";
	arri sa(23,47);
	arri::show(1,&sa);

// ---------------------------------------------------------
// troppo output: pausa per consentire la lettura .........
	cout << "\npremi Invio ....";
	char niente;
	cin.get(niente);
// ---------------------------------------------------------

	cout << "\n .......... array di default .............\n";
	arri ad[3];
	arri::show(3,ad);

	cout << "\n .......... array con argomenti .............\n";
	arri aa[3] = {7,8,9};
	arri::show(3,aa);

	return 0;
}
