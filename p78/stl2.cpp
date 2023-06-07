#include <iostream>
#include <list>
using namespace std;

namespace SCRIVI
{
	template <typename C> void show(char* titolo,const C& c)
	{
		cout << titolo << " (size=" << c.size() << "): ";
		typename C::const_iterator cit = c.begin();
		while(cit != c.end()) cout <<  *cit++ << "  ";
		cout << '\n';
	}
}

int main()
{
	using SCRIVI::show;
	list<int> lp;
	lp.push_back(12);
	lp.push_back(7);
	lp.push_back(9);
	lp.push_back(3);
	lp.push_back(10);
	show("Lista di partenza",lp);
	list<int> ld;
	ld.push_back(8);
	show("Lista di destinazione",ld);

	cout << '\n';
	{
		list<int> lm = lp;
		ld.splice(ld.begin(),lm);
		show("Lista mossa (totale)",lm);
		show("Lista copiata",ld);
	}

	cout << '\n';
	{
		list<int> lm = lp;
		ld.splice(++ld.begin(),lm,----lm.end());
		show("Lista mossa (1 elemento)",lm);
		show("Lista copiata",ld);
	}

	cout << '\n';
	{
		list<int> lm = lp;
		ld.splice(----ld.end(),lm,++++lm.begin(),lm.end());
		show("Lista mossa (parziale)",lm);
		show("Lista copiata",ld);
	}

	cout << "Torniamo alla lista di partenza...\n";
	lp.splice(lp.begin(),lp,------lp.end(),lp.end());
	show("..gli ultimi 3 elementi -> in testa",lp);
	lp.sort();
	show(".... ordinata",lp);
	ld.sort();
	show("Lista di destinazione ordinata",ld);

	cout << '\n';
	ld.merge(lp);
	show("Lista di partenza dopo il merge",lp);
	show("Lista di destinazione dopo il merge",ld);
	ld.unique();
	show("Eliminazione duplicati",ld);

	cout << '\n';
	list<int> lr;
	lr.push_back(2);
	lr.push_back(7);
	lr.push_back(4);
	show("Nuova lista non in ordine",lr);
	ld.merge(lr);
	show("Dopo merge con lista non in ordine",ld);
	ld.insert(--ld.end(),7);
	show("Inserito 7 prima dell'ultimo elemento",ld);
	ld.remove(7);
	cout << "Eliminati elementi = 7\n";
	show("Lista risultante",ld);

	cout << '\n';
	ld.reverse();
	show("Lista invertita",ld);
	return 0;
}
