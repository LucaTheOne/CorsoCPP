#include <iostream.h>
#include "Interfaccia.h"

int main()
{
	char ch;
	cout << "Inserisci stringa: ";
	using namespace Stack;
	while ( cin.get(ch), ch != '\n' ) push(ch);
	while ( ch = pop() ) cout << ch;
	cout << "\n\n\n";
	return 0;
}
		
