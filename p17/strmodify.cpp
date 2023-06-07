#include <iostream.h>
void main()
{
// Prima parte
	char array[] = { 'C', 'i', 'a', 'o' };
	char stringa[] = "Ciao";
	cout << "La lunghezza dell'array Ciao e': " 
		 << sizeof(array) << '\n';
	cout << "La lunghezza della stringa Ciao e': " 
		 << sizeof(stringa) << "\n\n\n";

// Seconda parte
	char frase[] = "Questa e' una variabile stringa inizializzata";
	char save_char = frase[0];
	int save_ind = 0;
	int Lfrase = sizeof(frase);
	int ind;
	cout << frase << '\n' 
		<< "(la cui lunghezza e': " << Lfrase << ")\n\n";
	for (;;)
	{
		cout << "Nuovo indice del terminator: ";
		cin >> ind;
		if ( ind >= Lfrase || ind < 0 ) break;
		frase[save_ind] = save_char;
		save_ind = ind;
		save_char = frase[ind];
		frase[ind] = '\0';
		cout << frase << '\n';
	}
	cout << "\n\n\n\n";
}