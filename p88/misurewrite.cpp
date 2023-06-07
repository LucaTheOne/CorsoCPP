#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "misure.h"

int main()
{
	using DISTRIBUZIONE_GAUSSIANA::Gauss;
	srand(time(NULL));

	ofstream fileout;
	string filename;
	bool loop = true;
	while(loop)
	{
		fileout.clear();
		cout << "\nInserisci il nome del file di output: ";
		cin >> filename;
		ifstream filein(filename.c_str());
		if ( loop = filein ) // nota: =, non ==
		{
			filein.close();
			cout << filename << " esiste gia', vuoi cancellarlo? ";
			string ans;  cin >> ans;
			if ( ans != "si" ) continue;
		}
		fileout.open(filename.c_str(),ios_base::out|ios_base::trunc|
			ios_base::binary);
		if ( loop = !fileout )
			cout << "Errore: " << filename << " non si puo' aprire\n";
	}
	cin.exceptions(ios_base::badbit|ios_base::failbit);
	unsigned int ngruppi;
	const int dim = 10000;
	try
	{
		cout << "Quanti gruppi di " << dim 
			<< " misure ciascuno (da 1 a 10) ? ";
		cin >> ngruppi;
		ngruppi = (ngruppi-1) % 10 + 1;
		cout << '\n';
		for (int ng=1; ng <= ngruppi; ng++)
		{
			ostringstream ostr;
			ostr << "Gruppo di misure n." << ng;
			string label = ostr.str();
			cout << label << "- inserisci media e sigma: ";
			double av,sq;
			cin >> av >> sq;
			Gauss gd(dim,av,sq);
			cout << "\tvalori calcolati: " << gd.getav() << "  " 
				<< gd.getsq() << '\n';
			int len = label.length();
			fileout.write((char*)&len,sizeof(int));
			fileout.write(label.data(),len);
			gd.write(fileout);
			if ( ng == ngruppi )
			{
				cout << "Premere enter per l'istogramma dell'ultimo gruppo ";
				cin.ignore(); 
				cin.get();
				Gauss::Histogram h(gd,22);
				h.print(75);
			}
		}
	}
	catch(Gauss::Error e)
	{
		cout << e.msg << '\n';
	}
	catch(ios_base::failure)
	{
		cout << "Errore di input\n";
	}
	return 0;
}