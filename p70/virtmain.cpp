#include "virtuali.h"

int main()
{
	namespace N = per_non_duplicare_nomi;
	using N::Base;
	using N::A;
	using N::B;
	using N::X;
	using N::Y;
	Base* pnew;
	Base* pst[5];
	pst[0] = new Base(0);
	pst[1] = new A(10);
	pst[2] = new B(20);
	pst[3] = new X(30);
	pst[4] = new Y(40);
	while (true) 
	{
		char ch;
		cout << "\nTipo dell'oggetto da clonare:\n";
		cout << "   0   = Base\n";
		cout << "   1   = A\n";
		cout << "   2   = B\n";
		cout << "   3   = X\n";
		cout << "   4   = Y\n";
		cout << "   else EXIT";
		cout << "        ? "; cin >> ch;
		int id = ch-48;
		if ( id < 0 || id > 4 ) break;
		pnew = pst[id]->clone();
		pnew->where();
		delete pnew;
	}
	for (int i=0; i<5; i++)
	{
		cout << '\n';
		delete pst[i];
	}
	cout << "\n\n\n";
	return 0;
}

