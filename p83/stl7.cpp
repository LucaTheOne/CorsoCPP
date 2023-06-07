#include <iostream>
#include <algorithm>
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

	struct Error
	{
		int first, last, out;
		Error(int f, int l, int o) : first(f), last(l), out (o) {}
	};

	template <class C> void move(C& c, int first, int last, int out)
	{
		if ( first < 0 || last <= first || last > c.size() ||
			out < 0 || out > c.size() ) throw(Error(first,last,out));
		if ( first == out ) return;

		int range = last-first;
		int out_last = out+range;
		bool backward = false;
		typename C::iterator first_erase;
		typename C::iterator last_erase;
		typename C::iterator first_copy;
		typename C::iterator last_copy;
		typename C::iterator out_copy;

		if ( out_last > c.size() )  // inserire nuovi elementi
		{
			int d = out_last-c.size();
			first_copy = c.begin();
			advance(first_copy,last-d);
			last_copy = first_copy;
			advance(last_copy,d);
			copy(first_copy,last_copy,back_inserter(c));
			c.erase(first_copy,last_copy);
			last -= d;
			out -= d;
			if ( last == first || out == first ) return;
			range -= d;
			out_last = out+range;
		}
		first_copy = c.begin();
		if ( first > 0 ) advance(first_copy,first);
		last_copy = first_copy;
		advance(last_copy,range);
		first_erase = first_copy;
		last_erase = last_copy;
		out_copy = c.begin();
		if ( out > 0 ) advance(out_copy,out);
		if ( first > out && first < out_last )
			//sequenze sovrapposte con seq. di uscita prima
		{
			first_erase = c.begin();
			advance(first_erase,out_last);
		}
		else if ( out > first && out < last ) 
			//sequenze sovrapposte con seq. di uscita dopo
		{
			last_erase = c.begin();
			advance(last_erase,out);
			backward = true;
			advance(out_copy,range);
		}
		if ( backward ) copy_backward(first_copy,last_copy,out_copy);
		else copy(first_copy,last_copy,out_copy);
		c.erase(first_erase,last_erase);
	}
}

int main()
{
	using My_region::show;
	using My_region::move;
	using My_region::Error;
	list<int> list_origin, list_mv;
	int i = 0;
	while ( i < 10 ) list_origin.push_back(i++);
try
{
	show("\nOggetto originale",list_origin);
	list_mv = list_origin;
	move(list_mv,1,3,6);
	show("Mossa sequenza 1-3 in 6 - sequenze non sovrapposte\n  con seq. di\
 uscita dopo",list_mv);

	show("\nOggetto originale",list_origin);
	list_mv = list_origin;
	move(list_mv,7,10,2);
	show("Mossa sequenza 7-10 in 2 - sequenze non sovrapposte\n  con seq. di\
 uscita prima",list_mv);

	show("\nOggetto originale",list_origin);
	list_mv = list_origin;
	move(list_mv,1,4,3);
	show("Mossa sequenza 1-4 in 3 - sequenze sovrapposte\n  con seq. di\
 uscita dopo",list_mv);

	show("\nOggetto originale",list_origin);
	list_mv = list_origin;
	move(list_mv,6,9,5);
	show("Mossa sequenza 6-9 in 5 - sequenze sovrapposte\n  con seq. di\
 uscita prima",list_mv);

	show("\nOggetto originale",list_origin);
	list_mv = list_origin;
	move(list_mv,3,6,9);
	show("Mossa sequenza 3-6 in 9 - sequenze non sovrapposte\n  con\
 inserimento in coda",list_mv);

	show("\nOggetto originale",list_origin);
	list_mv = list_origin;
	move(list_mv,2,7,6);
	show("Mossa sequenza 2-7 in 6 - sequenze sovrapposte\n  con\
 inserimento in coda",list_mv);

	show("\nOggetto originale",list_origin);
	list_mv = list_origin;
	move(list_mv,0,4,10);
	show("Mossa sequenza 0-4 in 10 - spostamento\n\
 primi 4 elementi in coda",list_mv);

	show("\nOggetto originale",list_origin);
	list_mv = list_origin;
	cout << "Mossa sequenza con .... ";
	move(list_mv,4,4,11);
}
catch (Error e)
{
	cout << "dati non validi: " << e.first << "  " << e.last <<
		"  " << e.out << '\n';
}
	return 0;
}
