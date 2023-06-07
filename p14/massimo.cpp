#include <iostream.h>
void main()
{
	int num,max = 0;
	do
	{
		cout << "Inserisci un numero (termina con 0):  ";
		cin >> num;
		max = num > max ?  num : max;
	} while (num);
	cout << "\nIl massimo numero inserito e': " << max << "\n\n\n\n";
}
