#include <iostream.h>

struct Ident
{
	char nome[20];
	int anno;
	Ident* previous;
	Ident* next;
};

void insert(Ident*&, const char*, const int&);
void remove(Ident* pcurr);
Ident* find(Ident*, const char*);


inline bool isequal(const char* p1, const char * p2)
{
	while( *p1 && *p1 == *p2 ) p1++, p2++;
	return *p1 == *p2;
}

int main()
{
	char * nomi[] = {	"Alessandra", 
						"Antonio",
						"Bruna",
						"Carlo",
						"Francesco",
						"Giuseppe",
						"Luciana",
						"Maria",
						"Roberta",
						"Vittorio" };
	int anni[] = { 10,28,44,50,35,43,19,31,27,15 } ;
	Ident* pfirst;
	Ident* pcurr = NULL;
	for ( int i = 0; i < 10 ; i++) 
	{
		insert(pcurr,nomi[i],anni[i]);
		if ( i == 0 ) pfirst = pcurr;
	}

	char str[20];
	while (true)
	{
		cout << "Nome da rimuovere : ";  cin >> str;
		if ( isequal(str,"FINE") ) break;
		if ( pcurr = find(pfirst,str) )
		{
			if ( pcurr == pfirst ) pfirst = pcurr->next;
			remove(pcurr);
		}
		else
			cout << str << "  non trovato\n";
	}
	cout << "\nNomi superstiti: \n";
	while ( pfirst )
	{
		cout << '\t' << pfirst->nome << ",  anni " << pfirst->anno
		    << '\n';
		Ident* ptemp = pfirst->next;
		delete pfirst;
		pfirst = ptemp;
	}
	return 0;
}

void insert(Ident*& pcurr, const char* nome, const int& anno)
{
	Ident* pnew = new Ident;
	pnew->anno = anno;
	char * idnome = pnew->nome;
	while ( *idnome++ = *nome++ );
	pnew->next = NULL;
	pnew->previous = pcurr;
	if ( pcurr ) pcurr->next = pnew;
	pcurr = pnew;
}

Ident* find(Ident* pcurr, const char* nome)
{
	if ( pcurr == NULL ) return NULL;
	if ( isequal(pcurr->nome,nome) ) return pcurr;
	return find(pcurr->next,nome);
}

void remove(Ident* pcurr)
{
	if ( pcurr->previous ) pcurr->previous->next = pcurr->next;
	if ( pcurr->next ) pcurr->next->previous = pcurr->previous;
	cout << "Rimosso : " << pcurr->nome << ",  anni " << pcurr->anno
		<< '\n';
	delete pcurr;
}