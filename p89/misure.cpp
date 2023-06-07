#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include "misure.h"

namespace DISTRIBUZIONE_GAUSSIANA
{
	void Gauss::setstat()
	{
		int i;
		double d;
		dim = val.size();
		average = sqm = 0.0;
		for (i=0; i < dim; i++) average += val[i];
		average /= dim;
		for (i=0; i < dim; i++)
		{
			d = val[i]-average;
			sqm += d*d;
		}
		sqm = sqrt(sqm/(dim-1));
	}

	Gauss::Gauss(const int& n, const double& av, const double& sq)
	{
		if ( n < 3 ) throw Error(Error::DIM);
		if ( sq <= 0.0 ) throw Error(Error::SQM);
		const double conv = 2.0/RAND_MAX;
		for ( int i=0; i < n; i+=2 )
		{
			double fac, rsq, v1, v2;
			do
			{
				v1 = conv*rand() - 1.0;
				v2 = conv*rand() - 1.0;
				rsq = v1*v1+v2*v2;
			}  while ( rsq >= 1.0 || rsq == 0.0 ) ;
			fac = sq * sqrt(-2.0*log(rsq)/rsq);
			val.push_back(fac*v1+av);
			if ( i+1 < n ) val.push_back(fac*v2+av);
		}
		setstat();
	}

	void Gauss::read(istream& inp)
	{
		ios_base::iostate em = inp.exceptions();
		inp.exceptions(ios_base::badbit|ios_base::failbit);
		int n;
		try
		{
			inp.read((char*)&n,sizeof(int));
			if ( n < 3 ) throw Error(Error::DIM);
			val.resize(n);
			for (int i=0; i <n; i++) inp.read((char*)&val[i],sizeof(double));
		}
		catch(ios_base::failure)
		{
			throw Error(Error::READ);
		}
		setstat();
		inp.exceptions(em);
	}

	void Gauss::write(ostream& out) const
	{
		int n = val.size();
		out.write((char*)&n,sizeof(int));
		for (int i=0; i <n; i++) out.write((char*)&val[i],sizeof(double));
	}

	Gauss::Histogram::Histogram(const Gauss& gd, int nb)
	{
		if ( nb < 3 ) throw Error(Error::DIM);
		const vector<double>& val = gd.getval();
		double tresigma = gd.getsq() * 3.0;
		double vmin = gd.getav()-tresigma;
		double vmax = gd.getav()+tresigma;
		if ( vmin == vmax ) throw Error(Error::SQM);
		count.resize(nb);
		int vsize = gd.size();
		double bsize = (vmax-vmin)/nb;
		int off = 0;
		for ( int i=0; i < vsize; i++)
		{
			double v = val[i];
			if ( v == vmax ) count[nb-1]++;
			else if ( v >= vmin && v < vmax ) count[int((v-vmin)/bsize)]++;
			else off++;
		}
		offper = int(1000.0*off/vsize+0.5);
	}

	void Gauss::Histogram::print(int norm)
	{
		if ( norm < 10 || norm > 80 ) return;
		int hmax = *max_element(count.begin(),count.end());
		cout << "\n\tFuori da 3 sigma = " << offper << "/1000\n";
		for (int i=0; i < count.size(); i++)
		{
			int n = count[i]*norm/hmax + 1;
			cout << string(n,'*') << '\n';
		}
		cout << '\n';
	}

	Gauss::Error::Error(erflg ef)
	{
		switch(ef)
		{
		case DIM : msg = "Errore: la dimensione del vettore e' < 3"; break;
		case SQM : msg = "Errore: sqm <= 0"; break;
		case READ : msg = "Errore in lettura di oggetto Gauss";
		default:;
		}
	}
}
