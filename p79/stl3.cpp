#include <iostream>
#include <map>
#include <set>
using namespace std;

namespace SCRIVI
{
	template <class T, class U> ostream& operator<<(ostream& out,
		pair<T,U> p)
	{
		out << "(" << p.first << "," << p.second << ")";
		return out;
	}

	template <class T, class U> void show(pair<T,U> pr)
	{
		if ( pr.second ) cout << "Inserito elemento " << *pr.first << '\n';
		else cout << "Non inserito elemento " << *pr.first << '\n';
	}

	template <typename C> void show(char* titolo,const C& c)
	{
		cout << titolo << " (size=" << c.size() << "): ";
		typename C::const_iterator cit = c.begin();
		while(cit != c.end()) cout <<  *cit++ << "  ";
		cout << '\n';
	}

	template <class Iter> void show(Iter cit)
	{
		cout << "Inserito elemento " << *cit << '\n';
	}

}

int main()
{
	using SCRIVI::show;
	map<char,int> mp;
	mp[87.18] = 10.34;  // conversioni ammesse con warning
	show("Mappa iniziale",mp);
	show(mp.insert(pair<char,int>('C',32)));
	show(mp.insert(pair<char,int>('C',8)));
	show("Mappa dopo l'inserimento",mp);

	cout << '\n';
	multimap<char,int> mmp;
	mmp.insert(mp.begin(),mp.end());
	show("Multimappa copiata dalla Mappa",mmp);
	show(mmp.insert(pair<char,int>('C',8)));
	show(mmp.insert(pair<char,int>('W',12)));
	show("Multimappa dopo l'inserimento",mmp);

	cout << "\nIn Set copiato da Multimappa:\n";
	set<int> st;
//	st.insert(mmp.begin(),mmp.end); //errore, gli elementi non sono
									// dello stesso tipo
	multimap<char,int>::const_iterator mmpit = mmp.begin();
	for(; mmpit != mmp.end(); ++mmpit) show(st.insert(mmpit->first));
	show("Set copiato da multimappa",st);

	cout << '\n';
	multiset<char> mst;
	mst.insert(st.begin(),st.end());
	show("Multiset copiato da Set",mst);
	show(mst.insert(121));
	show(mst.insert(69));
	show(mst.insert(87.99));
	show("Multiset dopo l'inserimento",mst);
	cout << "Numero elementi con chiave " << char(87) << ": " << 
		mst.count(87) << '\n'; 
	return 0;
}
