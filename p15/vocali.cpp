#include <iostream.h>
void main()
{
	char lettera;
	const char vocA ='A';
	short vocali=0, consonanti=0;

	for (lettera='A'; lettera<='Z'; lettera++)
		switch (lettera)
		{
			case vocA :
			case 'E' :
			case 'I' :
			case 'O' :
			case 'U' :	vocali++;	break;
			default:	consonanti++;
		}
	cout << "Vocali: " << vocali << "    Consonanti: "
		 << consonanti << "\n\n\n\n\n" ;
}

