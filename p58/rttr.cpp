#include <iostream.h>
#include <math.h>
#include "rttr.h"

namespace Punto_sul_piano
{
	point::point(const double& x0, const double& y0) : x(x0), y(y0)
	{
	}

	void operator/(const char* str, const point& p)
	{
		double x = p.x > -1e-6 && p.x < 1e-6 ? 0.0 : p.x;
		double y = p.y > -1e-6 && p.y < 1e-6 ? 0.0 : p.y;
		cout << str << "(" << x << ',' << y << ")\n";
	}

	point operator *(const point& p, const RT::rttr& rt)
	{
		return point(	p.x*rt.co+p.y*rt.si-rt.xtr   ,
						p.y*rt.co-p.x*rt.si-rt.ytr   );
	}
}

namespace RotoTraslazione
{
	const double degtorad = 3.14159265358/180.0;

	rttr::rttr(const double& ang, const double& x0, 
		const double& y0) : xtr(x0), ytr(y0), deg(ang)
	{
		double rad = ang*degtorad;
		co = cos(rad);
		si = sin(rad);
	}
	
	void operator/(const char* str, const rttr& rt)
	{
		cout << str << "[rotazione " << rt.deg << " gradi,  "<< 
			"origine in (" << rt.xtr << ',' << rt.ytr << ")]\n";
	}
}



