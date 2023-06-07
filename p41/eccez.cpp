#include <iostream.h>

// Non scrivete mai un programma del genere !!!
// Serve per capire come funziona il meccanismo di gestione
// delle eccezioni nei vari casi di blocchi "innestati".
// La scelta "assurda" dei tipi delle eccezioni sollevate
// dimostra che tale scelta e'  assolutamente arbitraria.
// In un "buon programma", invece, bisognerebbe, per
// ogni eccezione, creare un tipo specifico (e anche il
// il piu' possibile "mnemonico")

struct Gestore
{
	char ch;
};

void Livello1();
void Livello2();

int main()
{
	while (true) 
	{
		try
		{
			Livello1();
		    cout << "Non ha sollevato eccezioni (main)\n";
		}
		catch (double)
		{
			cerr << "Abortire ? No, per questa volta (main)\n";
		}
		catch (char)
		{
			cerr << "Ma che cosa vuoi ? (main)\n";
		}
		catch (Gestore p)
		{
			if (p.ch >= 'A' && p.ch <= 'Z' )
				cerr << "Hai scritto una lettera maiuscola (main)\n";
			else
				cerr << "Hai scritto il carattere: " 
				<< p.ch << " (main)\n";
		}
		catch (const int)
		{
			try
			{
				cerr << "Confermi l'uscita ? (s/n/(abort)) ";
				char ch; cin >> ch;
				if ( ch == 'n' ) throw 10.4f;
				else if ( ch != 's' ) throw 10.4;
				break;
			}
			catch (float)
			{
				cerr << "Ci hai ripensato (main)\n";
			}
			cerr << "Prima pero' completa il blocco catch esterno (main)\n";
		}
		catch (const char* str)
		{
			cerr <<  str << " (main)\n";
		}
		cerr << '\n';
	}
	cout << "Uscita regolare\n\n\n\n" ;
	return 0;
}

void Livello1()
{
	try          
	{            
		Livello2();
	}
	catch (double)
	{
		cerr << "Ma che cosa vuoi ? (Livello1)\n";
		throw 'A';
	}
	catch (const char* str)
	{
		cerr <<  str << " (Livello1)\n";
		throw;
	}
	catch (char)
	{
		cerr << "da qui non deve passare mai" << '\n';
	}
	char ch;
	try
	{
		cerr << "Cosa hai scritto ? "; cin >> ch;
		if ( ch == 'A' ) throw 1.5;
		if ( ch != 'N' ) throw 'A';
		throw Gestore();
	}
	catch (char)
	{
		cerr << "Allora ti contraddici !!! (Livello1)" << '\n';
	}
	catch (Gestore)
	{
		cerr << "Bene !!! (Livello1)\n";
	}
}

void Livello2()
{
	char ch;
	cerr << "Scrivi un carattere :  " ; cin >> ch ;
	switch(ch)
	{
	case 'E' : throw 0;
	case 'A' : throw 0L;
	case '!' : throw "Eccezionale !";
	case '?' : throw 10.4;
	default :	if ( ch != 'N' )
				{
					Gestore any;
					any.ch = ch;
					throw any;
				}
	}
	cout << "Non ha sollevato eccezioni (Livello2)\n";
}
