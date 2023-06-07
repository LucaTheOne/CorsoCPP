#include <iostream.h>
#include <stdio.h>
#include <math.h>
#include "frttr.h"

namespace Punto_sul_piano
{
	point::point() : x(0.0), y(0.0)
	{
	}

	point::point(const double& x0, const double& y0) : x(x0), y(y0)
	{
	}

	ostream& operator<<(ostream& out, const point& p)
	{
		double x = p.x > -1e-6 && p.x < 1e-6 ? 0.0 : p.x;
		double y = p.y > -1e-6 && p.y < 1e-6 ? 0.0 : p.y;
		char str[22];
		sprintf(str,"(%9.6f,%9.6f)",x,y);
		out << str;
		return out;
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
	
	ostream& operator<<(ostream& out, const rttr& rt)
	{
		out << "[rotazione " << rt.deg << " gradi,  "<< 
			"origine in (" << rt.xtr << ',' << rt.ytr << ")]\n";
		return out;
	}

	PP::point rttr::operator()(const PP::point& p)
	{
		double x = p.getx();
		double y = p.gety();
		return PP::point(	x*co+y*si-xtr   ,
							y*co-x*si-ytr   );
	}

	rttr rttr::operator!()  // calcola trasf. inversa
	{
		rttr rti(0.0);
		rti.deg = -deg;
		rti.xtr = -xtr*co+ytr*si;
		rti.ytr = -xtr*si-ytr*co;
		rti.co = co;
		rti.si = -si;
		return rti;
	}
}



