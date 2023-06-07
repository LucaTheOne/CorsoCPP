#include <iostream>
#include <algorithm>
using namespace std;

namespace My_region
{
	bool Nocase(const char& c1, const char& c2)
	{
		char nc1 = c1 >= 'a' && c1 <= 'z' ? c1-32 : c1;
		char nc2 = c2 >= 'a' && c2 <= 'z' ? c2-32 : c2;
		return nc1 < nc2;
	}
}

int main()
{
	using My_region::Nocase;
	int i;
	char stringa[] = "ACbd";
	cout << "\nsort normale -------------\n";
	stable_sort(stringa,stringa+4);
	cout << stringa << ' ';
	i = 1;
	while ( next_permutation(stringa,stringa+4) )
	{
		if ( i % 10 == 0 ) cout << '\n';
		cout << stringa << ' ';
		i++;
	}
	cout << "\n Num. permutazioni = " << i << '\n';

	cout << "\nsort nocase -------------\n";
	stable_sort(stringa,stringa+4,Nocase);
	cout << stringa << ' ';
	i = 1;
	while ( next_permutation(stringa,stringa+4,Nocase) )
	{
		if ( i % 10 == 0 ) cout << '\n';
		cout << stringa << ' ';
		i++;
	}
	cout << "\n Num. permutazioni = " << i << '\n';
	return 0;
}
