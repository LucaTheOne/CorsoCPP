#include <iostream.h>
#include "pintel.h"

int main()
{
	Ptr p;
	try { cout << p->valore; }
	catch(Error err) { cout << err.msg;  }

	cout << "Inserisci numeri (termina con 0): ";
	while(true)
	{
		try { p->valore = p(READ); }
		catch(Error err)
		{
			if (err.msg[0] == '0') break;
			cout << err.msg;
		}
	}
	try
	{
		cout << "Il valore piu' grande e': " << p->valore << '\n';
		p(WRITE);
	}
	catch(Error err) { cout << err.msg;  }
	return 0;
}
