#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <list>
using namespace std;

namespace My_region
{
	template <typename C> void show(const char* titolo,const C& c)
	{
		cout << titolo << " (size=" << c.size() << "): ";
		typename C::const_iterator cit = c.begin();
		while(cit != c.end()) cout <<  *cit++ << "  ";
		cout << '\n';
	}

	template <typename T> void show(const char* titolo,priority_queue<T> c)
	{
		cout << titolo << " (size=" << c.size() << "): ";
		while(!c.empty()) 
		{
			cout <<  c.top() << "  ";
			c.pop();
		}
		cout << '\n';
	}

	template <typename C> typename C::const_iterator
		find(const C& c, typename C::const_reference val)
	{
		typename C::const_iterator cit = c.begin();
		while ( cit != c.end() && val != *cit ) ++cit;
		return cit;
	}

	template <typename C> typename C::const_iterator
		find_last(const C& c, typename C::const_reference val)
	{
		typename C::const_reverse_iterator crit = c.rbegin();
		while ( crit != c.rend() && val != *crit ) ++crit;  // notare: ++
		if ( crit == c.rend() ) return c.end();
		typename C::const_iterator cit = crit.base();
		return --cit;
	}
}
int main()
{
	using My_region::show;
	using My_region::find;
	using My_region::find_last;

	cout << "\n\n";
	vector<int> vi(10);
	{
		int arrint[] = {37,29,48,19,10,82,43,29,10,31};
		for(int i=0; i < 10; i++) vi[i] = arrint[i];
	}
	show("Vettore vi",vi);
	int num_comp=0;
	vector<int>::const_iterator cit;
	while(true)
	{
		cout << "Cerca il numero: ";  cin >> num_comp;
		if ( num_comp == 0 ) break;
		if ( (cit = find(vi,num_comp)) == vi.end() )
			cout << "Numero non trovato\n" ;
		else
		{
			cout << "Trovata la prima occorrenza all'indice: " <<
				cit - vi.begin() << '\n';
			cit = find_last(vi,num_comp);
			cout << "Trovata l'ultima occorrenza all'indice: " <<
				cit - vi.begin() << '\n';
		}
	}

	cout << '\n';
	set<int> si(vi.begin(),vi.end());
	show("Set si copiato da vi",si);
	set<int>::const_iterator csit;
	while(true)
	{
		cout << "Cerca il numero: ";  cin >> num_comp;
		if ( num_comp == 0 ) break;
		if ( (csit = find(si,num_comp)) == si.end() )
			cout << "Numero non trovato\n" ;
		else
			cout << "Trovata la prima (e ultima) occorrenza all'indice: " <<
				distance(si.begin(),csit) << '\n';
	}

	cout << '\n';
	priority_queue<int> pi;
	for(cit=vi.begin(); cit!=vi.end(); cit++) pi.push(*cit);
	show("Priority_queue pi copiato da vi",pi);

	cout << '\n';
	list<int> li;
	li.push_back(100);
	li.push_front(-100);
	show("Lista li iniziale",li);
	vector<int>::const_iterator cbit = vi.begin()+2;
	vector<int>::const_iterator ceit = vi.end()-2;
	cout << "Inserisce da vi: ";
	for(cit=cbit; cit!=ceit; cit++) cout << *cit << "  ";
	cout << " (dopo " << *li.begin() << ")\n";
	li.insert(++li.begin(),cbit,ceit);
	show("Lista li dopo ins.",li);
	
	cout << '\n';
	vector<vector<int> > vvi(3);
	vvi[0] = vi;
	vvi[1].assign(si.begin(),si.end());
	vvi[2].assign(li.begin(),li.end());
	show("Matrice - riga copiata da vi",vvi[0]);
	show("Matrice - riga copiata da si",vvi[1]);
	show("Matrice - riga copiata da li",vvi[2]);

	return 0;
}
