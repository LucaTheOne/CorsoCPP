#include <iostream>
#include <string>
#include <set>
using namespace std;

namespace My_region
{
// un oggetto word e' una particolare stringa "depurata" in modo da avere
// solo caratteri alfabetici e numerici, e con le lettere maiuscole
// trasformate in minuscole

	class word : public string
	{
		static string valid_ch;
	public:
		word() {}
		word(const string&);
		static word extract(const string&, size_type&);
	};

	string word::valid_ch = "0123456789abcdefghijklmnopqrstuvwxyz\
ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	word::word(const string& s) : string(s)
	{
		string temp;
		char ch;
		size_type fps = find_first_of(valid_ch);
		while(fps != npos)
		{
			ch = (*this)[fps];
			if ( ch >= 'A' && ch <= 'Z' ) ch += 32;
			temp.append(1,ch);
			if ( ++fps == size() ) break;
			fps = find_first_of(valid_ch,fps);
		}
		assign(temp);
	}

	word word::extract(const string& str, size_type& pos)
	{
		size_type first;
		if ( (first = str.find_first_of(valid_ch,pos)) == npos ) 
			return word();
		pos = str.find_first_not_of(valid_ch,first);
		return word(str.substr(first,pos-first));
	}
}

int main()
{
	using My_region::word;
	word w;
	set<word> setw;
	multiset<word> msetw;
	string str;
	cout << "Inserisci una riga di testo :\n";
	getline(cin,str);
	unsigned pos = 0, maxsz = 0, sz;
	w = word::extract(str,pos);
	while ( (sz = w.size()) > 0 )
	{
		maxsz = sz > maxsz ? sz : maxsz;
		setw.insert(w);
		msetw.insert(w);
		w = word::extract(str,pos);
	}
	for(set<word>::const_iterator it = setw.begin(); it!=setw.end(); it++)
	{
		unsigned k = msetw.count(*it);
		cout << "La parola " << *it << string(maxsz-it->size(),' ') <<
			" compare " << k <<	(k == 1 ? " volta" : " volte") << '\n';
	}
	return 0;
}
