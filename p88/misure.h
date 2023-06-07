#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace DISTRIBUZIONE_GAUSSIANA
{
	class Gauss
	{
		int dim;
		double sqm;
		double average;
		vector<double> val;
		void setstat();
	public:
		Gauss() {}
		Gauss(const int&, const double&, const double&);
		void read(istream&);
		void write(ostream&) const;
		double size() const { return dim; }
		double getav() const { return average; }
		double getsq() const { return sqm; }
		const vector<double>& getval() const { return val; }
		class Histogram;
		struct Error;
	};

	class Gauss::Histogram
	{
		vector<int> count;
		int offper;
	public:
		Histogram(const Gauss&, int);
		void print(int);
	};

	struct Gauss::Error
	{
		enum erflg {DIM,SQM,READ};
		string msg;
		Error(erflg);
	};
}
