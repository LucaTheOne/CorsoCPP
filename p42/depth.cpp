#include <iostream.h>
#include "except.h"

int main()
{
	char ans;
	using My_exception::Exception;
	using My_exception::ricors;
	do
	{
		try
		{
			ricors(0,0);
		}
		catch ( Exception obj )
		{
			cout << "Eccezione a livello " << obj.level
				<< " - valore: " << obj.casual << '\n';
		}
		cout << "continui (s/n) ? ";  cin >> ans;
	} while ( ans == 's' );
	return 0;
}

