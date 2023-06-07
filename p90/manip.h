#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

namespace mio_manip
{
	struct sformat
	{
		enum floatfmt {n,f,e,g};
		static floatfmt ffmt;
		static int width;
		static int precision;
		static bool left;
		double dat;
		bool write;
		void setformat(const string&);
		sformat(const double& d, const string& s) : dat(d), write(true)
			{ setformat(s); }
		explicit sformat(const string& s) : write(false)
			{ setformat(s); }
		explicit sformat(const double& d) : dat(d), write(true) 
			{ }
	};

	inline sformat format(const double& d, const string& s)
	{
		return sformat(d,s);
	}

	inline sformat format(const string& s)
	{
		return sformat(s);
	}

	inline sformat format(const double& d)
	{
		return sformat(d);
	}

	ostream& operator<<(ostream&, const sformat&);

	struct fmt_error { };
}
