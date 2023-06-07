#include "Interfaccia.h"

namespace Stack
{
	const int max_size = 20;
	char v[max_size ];
	int top = 0;
}

void Stack::push(char c)
{
	if ( top == max_size )	throw Overflow();
						// equivale a: Overflow o; throw o;
	v[top++] = c;
}

char Stack::pop( )
{
	if ( top == 0 ) return '\0';
	return v[--top];
}

