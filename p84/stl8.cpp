#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

namespace My_region
{
	template <class T> class Vec : public vector<T>
	{
		T varianza;
		void setvar()
		{
			unsigned i=0, n=size();
			varianza = T(0);
			for (; i < n; i++ )
			{
				T v = (*this)[i];
				varianza += v*v;
			}
			varianza /= size();
		}
	public:
		T getvar() const { return varianza; }
		Vec() : vector<T>() { varianza = T(0); }
		Vec(const vector<T>& v) : vector<T>(v) { setvar(); }
	};

	template <class T> struct Order
	{
		bool operator()(const Vec<T>& v1, const Vec<T>& v2)
		{
			return v1.getvar() < v2.getvar();
		}
	};

	template <class Iter, class Pred>
		void comb_sort(Iter first, Iter last, Pred pr)
	{
		unsigned i, n = last-first;
		int offset = n;
		while ( offset > 1 )
		{
			offset = 8*offset/11;
			for (i=0; i<n-offset; i++ )
				if ( pr(*(first+i+offset),*(first+i)) )
					swap(*(first+i),*(first+i+offset));
		}

		bool ordered;
		for (i=0; i < n-1; i++) 
		{
			ordered = true;
			for(int j=0; j < n-i-1; j++)
				if ( pr(*(first+j+1),*(first+j)) )
				{
					ordered = false; 
					swap(*(first+j+1),*(first+j));
				}
			if ( ordered ) break;
		}
	}

	template <class C, class Pred> void riprova(C d, Pred pr)
	{
		int n = d.end() - d.begin();
		int j;
		for (j=0; j < n-1 && !pr(d[j+1],d[j]); j++);
		if ( j == n-1 )	cout << "OK !!!\n";
		else cout << "NON IN ORDINE !!! (nella posizione " << j
			<< ")\n";
	}

	template <class C, class Pred> void confronta(C d1, C d2, Pred pr)
	{
		int num_secondi;
		cout << "stable_sort : " << flush;
		num_secondi = time(NULL);
		stable_sort(d1.begin(),d1.end(),pr);
		num_secondi = time(NULL) - num_secondi;
		cout << num_secondi << " secondi  ";
		riprova(d1,pr);
		cout << "comb_sort : " << flush;
		num_secondi = time(NULL);
		comb_sort(d2.begin(),d2.end(),pr);
		num_secondi = time(NULL) - num_secondi;
		cout << num_secondi << " secondi  ";
		riprova(d2,pr);
		int n = d1.end() - d1.begin();
		int i = 0;
		while( i<n && d1[i]==d2[i] ) i++;
		if ( i == n ) cout << "RISULTATI IDENTICI\n";
		else cout << "CHE STRANO .... RISULTATI DIVERSI!\n";
	}
}

int main()
{
	using My_region::confronta;
	srand(time(NULL));
	int i;
{
	const int numel = 200000;
	cout << "\nvector di " << numel << " double -----------------\n";
	vector<double> d1(numel), d2(numel);
	for (i=0; i < numel; i++)
	{
		d1[i] = rand()/1000.;
		d2[i] = d1[i];
	}
	confronta(d1,d2,less<double>());
}
{
	using My_region::Vec;
	using My_region::Order;
	const int numel = 70000;
	const double conversione = 20.0/RAND_MAX;
	cout << "\nvector di " << numel << " Vec -----------------\n";
	vector<Vec<double> > d1(numel), d2(numel);
	for (i=0; i < numel; i++)
	{
		int num = rand() % 10 + 30;
		vector<double> vt(num);
		for (int j=0; j<num; j++) vt[j] = rand()*conversione-10.0;
		Vec<double> vc = vt;
		d1[i] = vc;
		d2[i] = vc;
	}
	confronta(d1,d2,Order<double>());
}
	return 0;
}
