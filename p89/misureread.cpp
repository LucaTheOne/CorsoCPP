#include <fstream>
#include "misure.h"


int main()
{
	using DISTRIBUZIONE_GAUSSIANA::Gauss;

	ifstream filein;
	string filename;
	bool loop = true;
	while(loop)
	{
		filein.clear();
		cout << "\nInserisci il nome del file di input: ";
		cin >> filename;
		filein.open(filename.c_str(),ios_base::in|ios_base::binary);
		if ( loop = !filein ) // nota: =, non ==
			cout << filename << " non esiste\n";
	}
	try
	{
		Gauss gd;
		int len;
		while ( filein.read((char*)&len,sizeof(int)) )
		{
			string label;
			if ( len < 15 ) throw Gauss::Error(Gauss::Error::DIM);
			char* s = new char [len+1];
			filein.read(s,len);
			s[len] = '\0';
			label = s;
			delete s;
			cout << label;
			gd.read(filein);
			cout << " - media: " << gd.getav() << 
				" - sigma: " << gd.getsq() << '\n';
		}
		cout << "Premere enter per l'istogramma dell'ultimo gruppo ";
		cin.ignore(); 
		cin.get();
		Gauss::Histogram h(gd,22);
		h.print(75);
	}
	catch(Gauss::Error e)
	{
		cout << '\n' << e.msg << '\n';
	}
	return 0;
}