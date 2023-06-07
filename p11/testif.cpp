#include <iostream.h>
void main()
{
	int num;
	cout << "Dammi un numero: ";  cin >> num;
	if ( num > 100 || num < -100) 
		cout << "Che numero grande!\n";
	if ( num % 2 ) 
		cout << num << " e' dispari\n";
	else
		cout << num << " e' pari\n";
	if ( num < 0 )
	{
		cout << num << " sara' cambiato di segno\n";
		num = -num;
		cout << "Numero risultante: " << num << "\n";
	}
	else cout << num << " e' positivo\n";
	cout << "\n\n\n\n";
}
