#include <iostream.h>
void main()
{
	int i = 0;

	while ( i < 10 ) cout << i++ << ' ';
	cout << '\n';

	i = 0;
	while (i < 10 )
	{
		if ( i % 2 )  cout << i << ' ';
		i++;
	}
 	cout << '\n';

	i= 0;
	while ( cout << i << ' ' , i++ < 10 );
	cout << "\n\n\n\n";

}