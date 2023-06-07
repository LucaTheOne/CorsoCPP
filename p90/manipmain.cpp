#include "manip.h"

int main()
{
	using mio_manip::format;

// prima parte
{
	double d;
	char ch;
	string formstring;
	cin.exceptions(ios_base::badbit|ios_base::failbit);
	while (true)
	{
		try
		{
			cout << "\nInserisci un numero e un formato: ";
			cin >> d >> noskipws >> ch >> skipws;
			if ( d == 0.0 ) break;
			if ( ch == '\n' ) cout << "     /" << format(d) << "/" << endl;
			else
			{
				cin >> formstring;
				cin.ignore(1000,'\n');
				cout << "     /" << format(d,formstring) << "/" << endl;
			}
		}
		catch(ios_base::failure f)
		{
			cout << "ERRORE DI INPUT\n";
			cin.clear();
			cin.ignore(1000,'\n');
		}
		catch(mio_manip::fmt_error)
		{
			cout << "STRINGA DI FORMATO ERRATA\n";
		}
	}
}

// seconda parte
{
	cout << format("f6.0") << "\n\n";
	for (int i=0; i < 100;)
	{
		cout << format(i++);
		if ( i % 10 == 0 ) cout << '\n';
	}
}
	return 0;
}
