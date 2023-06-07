#include <iostream.h>
void main()
{
	char Nome[] = "                               ";
	char Cognome[] = "                               ";
	int anni;    
	float altezza;
	cout << "Come ti chiami?  ";
	cin >> Nome >> Cognome;
	cout << "Quanti anni hai ?  ";   cin >> anni;
	cout << "Quanto sei alto ?  ";   cin >> altezza;
	cout << '\n' << Nome << ' ' << Cognome  << ",   eta': "
		<< anni << " anni,   altezza: " << altezza << " m.\n\n\n\n";
}