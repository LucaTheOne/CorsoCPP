#include <iostream.h>
#include "ident.h"

void main()
{
	persona tizio;
	data nascita;
	tizio.pnascita = &nascita;
	get_ident(&tizio);
	print_ident(tizio);
}

void get_ident(persona* ptr)
{
  cout << "Nome: " ;    cin >> ptr->nome;
  cout << "Cognome: ";	cin >> ptr->cognome;
  cout << "Data di nascita: " ;
  cin >> ptr->pnascita->giorno >> ptr->pnascita->mese >>
	  ptr->pnascita->anno ;
}

void print_ident(const persona& tale)
{
	char* mesi[13] = {"Gennaio","Febbraio","Marzo","Aprile",
		"Maggio","Giugno","Luglio","Agosto","Settembre",
		"Ottobre","Novembre","Dicembre","???"} ;
	int mese = tale.pnascita->mese-1;
	if (mese < 0 || mese > 11) mese = 12;
	cout << '\n' << tale.nome << ' ' << tale.cognome 
		<< "  nato il " << tale.pnascita->giorno << ' '
		<< mesi[mese] << ' ' 
		<< tale.pnascita->anno  	<< '\n' ;
}
