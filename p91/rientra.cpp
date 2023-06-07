#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> vs;
	vector<double> vd;
	string digit = "0123456789";
	cout << "Inserisci una frase:\n";
	double num;
	string str;
	bool isnum;
	char c = cin.get();
	int ninbuf = 1;
	while(ninbuf > 0)
	{
		while(c < 33 && (ninbuf=cin.rdbuf()->in_avail()) > 0) c = cin.get();
		if ( ninbuf > 0 )
		{
			isnum = false;
			if ( c == '+' || c == '-' || c == '.' )
			{
				char cp = cin.peek();
				if ( c != '.' && cp == '.' )
				{
					cp = cin.get();
					char cpp = cin.peek();
					isnum = digit.find(cpp) != string::npos;
					cin.putback(cp);
				}
				else isnum = digit.find(cp) != string::npos;
			}
			else isnum = digit.find(c) != string::npos;
			cin.putback(c);
			if ( isnum )
			{
				cin >> num;
				vd.push_back(num);
			}
			else
			{
				cin >> str;
				vs.push_back(str);
			}
			c = cin.get();
		}
	}
	sort(vs.begin(),vs.end());
	sort(vd.begin(),vd.end());
	cout << "Trovati i numeri: ";
	int i;
	for (i=0; i < vd.size(); i++ ) cout << vd[i] << "  ";
	cout << "\n\nTrovate le stringhe:\n";
	for (i=0; i < vs.size(); i++ ) cout << "\t\t" << vs[i] << '\n';;

	return 0;
}