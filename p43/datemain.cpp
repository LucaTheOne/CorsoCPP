#include <iostream.h>
#include "date.h"

int main()
{
	using My_date::date;
	using My_date::Error;
	date oggi[5];
	int g,m,a,i;
	for (i = 0; i < 5; i++ )
		while(true)
		{
			cout << "Entra giorno,mese,anno (" << i << "): ";
			cin >> g >> m >> a ;
			try
			{
				oggi[i].set(g,m,a);
				break;
			}
			catch (Error& err)
			{
				cout << err.message;
			}
		}
	for (i = 0; i < 5; i++ )
	{
		const char* mese;
		oggi[i].get(g,mese,a);
		cout << "Data(" << i << ") = "
			<< g << "-" << mese << "-" << a << '\n';
	}
	return 0;
}
