#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cout << "Inserisci dimensione: ";  cin >> n;
	if ( n < 3 ) n = 3;
	string stringa(n,' ');
	cout << "Massima lunghezza stringa: " << stringa.max_size()
		<< '\n';
	cout << "Inserisci i caratteri: ";
	cin >> stringa[0];
	char ch;
	int i = 1;
	while ( i < n )
	{
		cin.get(ch);
		if ( ch == '\n' ) break;
		stringa[i++] = ch;
	}
	if ( i < n ) stringa.resize(i);
	cout << "Lunghezza della stringa inserita: " << stringa.length() << '\n';
	string::reverse_iterator rit = stringa.rbegin();
	cout << "Stringa invertita: ";
	while ( rit != stringa.rend() ) cout << *rit++;
	cout << "\nIl carattere 'a' compare nella stringa " <<
		count(stringa.begin(),stringa.end(),'a') << " volte\n\n\n";
	return 0;
}
