#include <iostream>
#include <map>
#include <vector>
using namespace std;

namespace My_region
{
	class Valori
	{
		int num;
		const char * descr;
		friend bool operator<(const Valori&, const Valori&);
		friend bool operator==(const Valori&, const Valori&);
		friend ostream& operator<<(ostream&, const Valori&);
	public:
		Valori() : num(27), descr("eccomi qua!!") {}
		Valori(int n, char* m) : num(n), descr(m) {}
	};

	bool operator<(const Valori& val1, const Valori& val2)
	{
		return val1.num < val2.num;
	}

	bool operator==(const Valori& val1, const Valori& val2)
	{
		return val1.num == val2.num;
	}

	ostream& operator<<(ostream& out, const Valori& val)
	{
		out << "(" << val.num << "-" << val.descr << ")";
		return out;
	}

	template <class T, class U> 
		ostream& operator<<(ostream& out, const pair<T,U>& pr)
	{
		out << "Chiave: " << pr.first << "   Valore mappato: " <<
			pr.second;
		return out;
	}

	template <class T> 
		ostream& operator<<(ostream& out, const vector<T>& vec)
	{
		typename vector<T>::const_iterator cit = vec.begin();
		out << "(";
		if (vec.size() > 0 ) out << *cit++;
		while(cit!=vec.end()) out << "," << *cit++;
		out << ")";
		return out;
	}

	template <class T, class U> void show(const char* titolo,
		const map<T,U>& mp)
	{
		cout << titolo << ":\n";
		typename map<T,U>::const_iterator cit = mp.begin();
		while(cit!=mp.end()) cout << '\t' << *cit++ << '\n';
	}
}

int main()
{
	using My_region::Valori;
	using My_region::show;

	Valori v1(5,"aaaaaaaa");
	Valori v2(3,"bbbbbbbb");
	Valori v3(9,"cccccccc");
	Valori v4(2,"dddddddd");

	vector<int> i1(3);
	i1[0] = 5; i1[1] = 1; i1[2] = 8;
	vector<int> i2(4);
	i2[0] = 5; i2[1] = 0; i2[2] = 7; i2[3] = 6;
	vector<int> i3(2);
	i3[0] = 4; i3[1] = 2;
	vector<int> i4;
	i4.push_back(6);

	cout << '\n';
	map<vector<int>,Valori> mvi;
	mvi[i1] = v1;
	mvi[i2] = v2;
	mvi[i3] = v3;
	mvi[i4];
	show("Mappa mvi di Valori su vector<int>",mvi);

	cout << '\n';
	map<Valori,vector<int> > miv;
	miv[v1] = i1;
	miv[v2] = i2;
	miv[v3] = i3;
	miv[v4];
	show("Mappa miv di vector<int> su Valori",miv);

	cout << '\n';
	map<Valori,vector<int> > miv2 = miv;
	miv2.erase(v2);
	show("Mappa miv2 di vector<int> su Valori, copiata da miv\
 e un elemento cancellato",miv2);
	if ( miv2 == miv ) cout << "\nmiv2 e miv sono uguali !\n";
	else cout << "\nmiv2 e miv non sono uguali !\n";
	if ( miv2 > miv ) cout << "miv2 e' maggiore di miv !\n\n";
	else cout << "miv2 non e' maggiore di miv !\n\n";
	return 0;
}
