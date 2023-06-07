#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

namespace My_region
{
	template <typename C> void show(char* titolo,const C& c)
	{
		cout << titolo << " (size=" << c.size() << "): ";
		typename C::const_iterator cit = c.begin();
		while(cit != c.end()) cout <<  *cit++ << "  ";
		cout << '\n';
	}

	void test(const vector<int>&, const list<double>&, bool);
}

int main()
{
	using My_region::show;
	using My_region::test;

	vector<int> vi(5);
	vi[0] = 5; vi[1] = 0; vi[2] = -7; vi[3] = 6; vi[4] = -1;
	show("Vettore vi",vi);

	list<double> ld;
	ld.push_back(5.1);
	ld.push_back(0.8);
	ld.push_back(3.2);
	ld.push_back(6.0);
	ld.push_back(-1.2);
	show("Lista   ld",ld);

	test(vi,ld,false);
	test(vi,ld,true);

	return 0;
}

namespace My_region
{
	struct Predic
	{
		bool operator()(int i, double x) { return int(x)==i;}
	};

	void test(const vector<int>& vi, const list<double>& ld, bool ispr)
	{
		if ( ispr )	cout <<
			"\nCon predicato (conversioni forzate da double a int):\n";
		else  cout <<
			"\nSenza predicato (conversioni naturali da int a double):\n";
		char* Ordinal[] = {"Primo","Secondo","Terzo","Quarto","Quinto"};
		int num = 0;
		typedef vector<int>::const_iterator VI;
		VI it = vi.begin();
		while ( it != vi.end() )
		{
			if ( ispr )	it = find_first_of(it,vi.end(),ld.begin(),ld.end(),
				Predic());
			else it = find_first_of(it,vi.end(),ld.begin(),ld.end());
			if ( it != vi.end() ) cout << Ordinal[num++] << 
				" elemento di vi trovato in ld: " << *it++ << '\n';
		}
		cout << "Numero di elementi di vi trovati in ld: " << num << '\n';

		typedef list<double>::const_iterator LI;
		pair<VI,LI> coppia;
		num = 0;
		it = vi.begin();
		LI itl = ld.begin();
		while ( it != vi.end() )
		{
			if ( ispr )	coppia = mismatch(it,vi.end(),itl,Predic());
			else coppia = mismatch(it,vi.end(),itl);
			it = coppia.first;
			itl = coppia.second;
			if ( it != vi.end() ) cout << Ordinal[num++] << 
				" elemento di vi = " << *it++ << 
				"  diverso da elemento di ld = " << *itl++ << '\n';
		}
		cout << "Numero di elementi diversi in vi e ld: " << num << '\n';
	}
}

