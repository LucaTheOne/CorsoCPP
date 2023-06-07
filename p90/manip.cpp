#include "manip.h"

namespace mio_manip
{
	sformat::floatfmt sformat::ffmt = sformat::n;
	int sformat::width;
	int sformat::precision;
	bool sformat::left;

	void sformat::setformat(const string& s)
	{
		floatfmt tmp1;
		switch(s[0])
		{
		case 'f': tmp1 = f; break;
		case 'e': tmp1 = e; break;
		case 'g': tmp1 = g; break;
		default: throw fmt_error();
		}
		string::size_type pp = s.find('.',1);
		if ( pp >= s.length()-1 ) throw fmt_error();
		int tmp2 = atoi(s.substr(pp+1).c_str());
		if ( tmp2 < 0 ) throw fmt_error();
		ffmt = tmp1;
		precision = tmp2;
		int tmp3 = atoi(s.substr(1,pp-1).c_str());
		left = tmp3 < 0;
		width = tmp3 >= 0 ? tmp3 : -tmp3;
	}

	ostream& operator<<(ostream& os, const sformat& sf)
	{
		if ( !sf.write ) return os;
		ostringstream ostr;
		if ( sformat::ffmt != sformat::n ) 
		{
			if ( sformat::ffmt == sformat::f ) ostr << fixed;
			else if ( sformat::ffmt == sformat::e ) ostr << scientific;
			ostr << setprecision(sformat::precision);
			if ( sformat::left ) ostr << left;
			ostr << setw(sformat::width);
		}
		ostr << sf.dat;
		return os << ostr.str();
	}
}
