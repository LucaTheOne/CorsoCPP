#include <iostream.h>
#include <stdlib.h>
#include <time.h>
#include "listin.h"

int main()
{
	using My_region::Bins;
	using My_region::Error;
	srand(time(NULL));
	Bins* pBins;
	int num;
	while(true)
	{
		cout << "Inserisci num. intervalli: ";  cin >> num;
		try
		{
			pBins = new Bins(num);
			break;
		}
		catch(Error err)
		{
			cout << err.descr;
		}
	}
	for(int i=0; i<100000; i++) pBins->insert(rand());
	pBins->show();
	delete pBins;
	return 0;
}
