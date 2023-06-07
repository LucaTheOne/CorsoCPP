#include <time.h>
#include "stringa.h"

int main()
{
	const int iter = 100000000;
	int i,inizio_intervallo;

	using spazio_stringa::stringa;
	stringa bella("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
	stringa belle;
	cout << "Tempo per " << iter << " copie con handle: " << flush;
	inizio_intervallo = time(NULL);
	for (i=0; i < iter; i++) belle = bella;
	cout << time(NULL) - inizio_intervallo << " secondi" << '\n';

	using spazio_stringa::bruttacopia;
	bruttacopia brutta("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
	bruttacopia brutte;
	cout << "Tempo per " << iter << " copie dirette: " << flush;
	inizio_intervallo = time(NULL);
	for (i=0; i < iter; i++) brutte = brutta;
	cout << time(NULL) - inizio_intervallo << " secondi\n";

	return 0;
}