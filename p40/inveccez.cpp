#include <iostream.h>
#include "Interfaccia.h"

int main()
{
	char ch;
	cout << "Inserisci stringa: ";
	using namespace Stack;
	try
	{
		while ( cin.get(ch), ch != '\n' ) push(ch);
	}
	catch (Overflow)
	{
		cout << "Stop : troppi caratteri\n";
	}
	while ( ch = pop() ) cout << ch;
	cout << "\n\n\n";
	return 0;
}
		
