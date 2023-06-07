#include "stringa.h"

namespace SS = spazio_stringa;

SS::stringa prova(SS::stringa str1, SS::stringa str2)
{
	str1[3] = '?';
	char c = str2[2];
	cout << "in prova: " << str1 << ' ' << str2 << ' ' << c << '\n';
	return str1+str2;
}

int main()
{
	using SS::stringa;
	stringa str1,str2;
	cerr << "Inserire 2 stringhe: ";  cin >> str1 >> str2;
	stringa str0 = str1;
	cout << "nel main: " << str1 << ' ' << str2 << ' ' << '\n';
	try
	{
		cout << "Risultato: " << prova(str1,str2) << '\n';
		cout << "nel main: " << str1 << ' ' << str2 << ' ' << '\n';
		if ( str0 != str1 )
			cout << "\nLa prima stringa e' cambiata !!!\n";
		if ( str0 == str1 )
			cout << "\nLa prima stringa non e' cambiata !!!\n";
#ifdef _DEBUG
		stringa debug;
		debug = "Che bella stringa letterale!";
		debug += " .... con aggiunta";
		stringa totale = "Totale: " + debug;
#endif
	}
	catch (SS::Errore)
	{
		cout << "Indice fuori dal range\n";
	}
	return 0;
}