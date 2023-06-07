#include "DT.h"

namespace Date_and_Time
{
	class Manage
	{
		Date_Time* pfirst;
		void display(const int&, Date_Time*&) const;
		void sort(Date_Time*);
	public:
		Manage();
		~Manage();
		bool Loop();
	};
}

int main()
{
	Date_and_Time::Manage m;
	while ( m.Loop() );
	return 0;
}

Date_and_Time::Manage::Manage() : pfirst(NULL)
{
}

Date_and_Time::Manage::~Manage()
{
	Date_Time* ptemp;
	while ( pfirst )
	{
		ptemp = pfirst->pnext;
		delete pfirst;
		pfirst = ptemp;
	}
}

bool Date_and_Time::Manage::Loop()
{
	char ch;
	cout << "\nInserisci oggetto:\n";
	cout << "   1   = Date\n";
	cout << "   2   = Time\n";
	cout << "   3   = Date_Time\n";
	cout << "   else EXIT";
	cout << "        ? "; cin >> ch;
	int id = ch-48;
	if ( id < 1 || id > 3 ) return false;
	Date_Time* pnew;
	int add;
	try  
	{ 
		switch (id)
		{
		case 1 : 
			cout << "Inserisci giorno, mese, anno :\n\t"; break;
		case 2 : 
			cout << "Inserisci ore, minuti, secondi :\n\t"; break;
		default : 
			cout << "Inserisci giorno, mese, anno, " <<
					"ore, minuti, secondi :\n\t";
		}
		pnew = new Date_Time(id);
		if ( id == 1 ) cout << "\nSomma a oggetto giorni :  ";
		else cout << "\nSomma a oggetto secondi :  ";
		cin >> add;
		if ( cin.rdstate() > 0  )
		{
			delete pnew;
			throw Error(-1000000000);
		}
		if ( add < 0 ) 
		{
			delete pnew;
			throw Error(add);
		}
	}
	catch (Error e)
	{
			cout << e.msg;
			return true;
	}
	*pnew += add;
	cout << "Risultato: ";
	pnew->write();
	sort(pnew);
	Date_Time* pcurr = pfirst;
	cout << "\nLista oggetti:\n";
	display(1,pcurr);
	display(2,pcurr);
	display(3,pcurr);
	return true;
}

void Date_and_Time::Manage::sort(Date_Time* pnew)
{
	Date_Time* pprev = NULL;
	Date_Time* pcurr = pfirst;
	while ( pcurr && *pcurr < *pnew )
	{
		pprev = pcurr;
		pcurr = pcurr->pnext;
	}
	if ( pprev == NULL ) pfirst = pnew;
	else pprev->pnext = pnew;
	pnew->pnext = pcurr;
}

void Date_and_Time::Manage::display(const int& id, Date_Time*& pcurr) const
{
	switch( id )
	{
	case 1 : cout << "Date      :  "; break;
	case 2 : cout << "Time      :  "; break;
	default: cout << "Date_Time :  ";
	}
	bool bf = true;
	while ( pcurr && pcurr->ident == id )
	{
		if ( bf ) bf = false;
		else cout << "             ";
		pcurr->write();
		pcurr = pcurr->pnext;
	}
	if ( bf ) cout << "  (nessuno)\n";
}
