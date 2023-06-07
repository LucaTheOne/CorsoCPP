#include <iostream.h>

int main(int argc, char** argv)
{
	if ( argc == 1 )
	{
		cout << "\nSpecificare almeno un parametro\n" ;
		return 0;
	}
	cout << "\nIl programma \"" << *argv++
		<< "\" ha trasmesso i seguenti parametri:\n" ;
	while (*argv) cout << "\t\t\t" << *argv++ << '\n' ;
	return 0;
}
	
