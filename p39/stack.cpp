#include "Interfaccia.h"

namespace Stack
{
	const int max_size = 100;
	char v[max_size ];
	int top = 0;
}

void Stack::push(char c)
{
	if ( top == max_size ) return;
	v[top++] = c;
}

char Stack::pop( )
{
	if ( top == 0 ) return '\0';
	return v[--top];
}

