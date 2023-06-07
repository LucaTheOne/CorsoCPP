#include <iostream.h>
#include <stdio.h>
#include <math.h>
#include "ASCInterf.h"

namespace mini_graphics
{
	extern const double epsp;
	extern const double epsm;

	int ASC_Screen::objcount = 0;
	char ASC_Screen::bigpix = '*';
	char ASC_Screen::bkgnd = ' ';
	char* ASC_Screen::pixel = NULL;
	int ASC_Screen::nSx = 78;
	int ASC_Screen::nSy = 24;
	Point ASC_Screen::Sh_blc = Point(0.,0.);
	Point ASC_Screen::Sh_trc = Point(31.8,15.6);
	Point ASC_Screen::Sc_coe = Point(2.421,-1.474);
	Point ASC_Screen::Sc_off = Point(0.,23.);

	ASC_Screen::ASC_Screen()
	{
		if ( pixel == NULL )
		{
			pixel = new char [nSy*(nSx+1)];
			clear();
		}
		objcount++;
	}

	ASC_Screen::~ASC_Screen()
	{
		if ( --objcount == 0 ) 
		{
			delete [] pixel;
			pixel = NULL;
		}
	}

// metodi privati di ASC_Screen

	void ASC_Screen::set_conversion()
	{
		Sc_coe.x = double(nSx-1)/(Sh_trc.x-Sh_blc.x);
		Sc_coe.y = double(nSy-1)/(Sh_blc.y-Sh_trc.y);
		Sc_off.x = -Sc_coe.x * Sh_blc.x;
		Sc_off.y = -Sc_coe.y * Sh_trc.y;
	}

	Point ASC_Screen::ToScreen(const Point& pSh)
	{
		Point pSc;
		pSc.x = pSh.x * Sc_coe.x + Sc_off.x;
		pSc.y = pSh.y * Sc_coe.y + Sc_off.y;
		return pSc;
	}

	void ASC_Screen::draw_Screen_Line(const Point& pSc1,
		const Point& pSc2)
	{
		double varx = pSc2.x - pSc1.x;
		double avarx = varx >= 0.0 ? varx : -varx;
		double vary = pSc2.y - pSc1.y;
		double avary = vary >= 0.0 ? vary : -vary;
		Point p1 = pSc1;
		Point p2 = pSc2;
		if ( avarx > avary )
		{
			double slope = vary / varx;
			double offs = pSc1.y - pSc1.x*slope;
			if ( pSc2.x < pSc1.x )
			{
				p1 = pSc2;
				p2 = pSc1;
			}
			while ( p1.x < p2.x )
			{
				draw_Screen_Dot(p1);
				p1.y = ++p1.x * slope + offs;
			}
		}
		else
		{
			double slope = varx / vary;
			double offs = pSc1.x - pSc1.y*slope;
			if ( pSc2.y < pSc1.y )
			{
				p1 = pSc2;
				p2 = pSc1;
			}
			while ( p1.y < p2.y )
			{
				draw_Screen_Dot(p1);
				p1.x = ++p1.y * slope + offs;
			}
		}
		draw_Screen_Dot(p2);
	}

	void ASC_Screen::draw_Screen_Dot(const Point& pSc)
	{
		if ( pSc.x < -0.5 || pSc.y < -0.5 ) return;
		int nx = int(pSc.x+0.5);
		int ny = int(pSc.y+0.5);
		if ( nx >= nSx || ny >= nSy ) return;
		*(pixel+ny*(nSx+1)+nx) = bigpix;
	}

	void ASC_Screen::draw_Screen_Ellipse(const Point& pSc,
		double& rx, double& ry)
	{
		double aq = rx*rx;
		double bq = ry*ry;
		double abq = sqrt(aq+bq);
		Point p(0.,sqrt(bq));
		draw_Screen_Dot(Point(pSc.x,pSc.y-p.y));
		draw_Screen_Dot(Point(pSc.x,pSc.y+p.y));
		double xlim = aq/abq;
		p.x++;
		while ( p.x < xlim )
		{
			p.y = sqrt(bq*(1.0-p.x*p.x/aq));
			draw_Screen_Dot(Point(pSc.x-p.x,pSc.y-p.y));
			draw_Screen_Dot(Point(pSc.x-p.x,pSc.y+p.y));
			draw_Screen_Dot(Point(pSc.x+p.x,pSc.y-p.y));
			draw_Screen_Dot(Point(pSc.x+p.x,pSc.y+p.y));
			p.x++;
		}
		p = Point(sqrt(aq),0.);
		draw_Screen_Dot(Point(pSc.x-p.x,pSc.y));
		draw_Screen_Dot(Point(pSc.x+p.x,pSc.y));
		double ylim = bq/abq;
		p.y++;
		while ( p.y < ylim )
		{
			p.x = sqrt(aq*(1.0-p.y*p.y/bq));
			draw_Screen_Dot(Point(pSc.x-p.x,pSc.y-p.y));
			draw_Screen_Dot(Point(pSc.x-p.x,pSc.y+p.y));
			draw_Screen_Dot(Point(pSc.x+p.x,pSc.y-p.y));
			draw_Screen_Dot(Point(pSc.x+p.x,pSc.y+p.y));
			p.y++;
		}
		draw_Screen_Dot(Point(pSc.x-xlim,pSc.y-ylim));
		draw_Screen_Dot(Point(pSc.x-xlim,pSc.y+ylim));
		draw_Screen_Dot(Point(pSc.x+xlim,pSc.y-ylim));
		draw_Screen_Dot(Point(pSc.x+xlim,pSc.y+ylim));
	}

// metodi protetti di ASC_Screen

	void ASC_Screen::draw_Line(const Point& pSh1, const Point& pSh2)
	{
		draw_Screen_Line(ToScreen(pSh1),ToScreen(pSh2));
	}

	void ASC_Screen::draw_Polygon(int np, const Point* ppSh)
	{
		for(int i=0; i < np-1; i++) draw_Line(ppSh[i],ppSh[i+1]);
		draw_Line(ppSh[np-1],ppSh[0]);
	}

	void ASC_Screen::draw_Dot(const Point& pSh)
	{
		draw_Screen_Dot(ToScreen(pSh));
	}

	void ASC_Screen::draw_Square(const Point& cen, const double& sid)
	{
		double sx = Sc_coe.x > 0.0 ? Sc_coe.x : -Sc_coe.x;
		double sy = Sc_coe.y > 0.0 ? Sc_coe.y : -Sc_coe.y;
		double s = sid*(sx+sy)*0.25;
		double rx = s*1.28;
		double ry = s*0.78;
		Point c = ToScreen(cen);
		draw_Screen_Line(Point(c.x-rx,c.y-ry),Point(c.x-rx,c.y+ry));
		draw_Screen_Line(Point(c.x-rx,c.y+ry),Point(c.x+rx,c.y+ry));
		draw_Screen_Line(Point(c.x+rx,c.y+ry),Point(c.x+rx,c.y-ry));
		draw_Screen_Line(Point(c.x+rx,c.y-ry),Point(c.x-rx,c.y-ry));
	}

	void ASC_Screen::draw_Circle(const Point& cen, const double& diam)
	{
		double sx = Sc_coe.x > 0.0 ? Sc_coe.x : -Sc_coe.x;
		double sy = Sc_coe.y > 0.0 ? Sc_coe.y : -Sc_coe.y;
		double s = diam*(sx+sy)*0.25;
		double rx = s*1.28;
		double ry = s*0.78;
		draw_Screen_Ellipse(ToScreen(cen),rx,ry);
	}

// metodi pubblici di ASC_Screen

	void ASC_Screen::set_Screen_size(const int& nx, const int& ny)
	{
		if ( pixel != NULL )
			throw Screen_Error(Screen_Error::ALR_CRE);
		if ( nx <20 || ny < 10 || nx > 130 || ny > 50 )
			throw Screen_Error(Screen_Error::INV_SIZ);
		nSx = nx;
		nSy = ny;
		set_conversion();
	}

	void ASC_Screen::set_Screen_corners(const Point& blc,
		const Point& trc)
	{
		double dx = trc.x -  blc.x;
		double dy = trc.y -  blc.y;
		if ( dx > epsm && dx < epsp || dy > epsm && dy < epsp )
				throw Screen_Error(Screen_Error::INV_SCR);
		Sh_blc = blc;
		Sh_trc = trc;
		set_conversion();
	}

	void ASC_Screen::get_Screen_corners(Point& blc, Point& trc)
	{
		blc = Sh_blc;
		trc = Sh_trc;
	}

	void ASC_Screen::clear()
	{
		if ( pixel == NULL )
			throw Screen_Error(Screen_Error::NOB_CRE);
		int n = 0;
		for (int i=0; i < nSy; i++)
		{
			for (int j=0; j < nSx; j++) *(pixel+n++) = bkgnd;
			*(pixel+n++) = '\0';
		}
	}

	void ASC_Screen::move_center(const Point& cen)
	{
		// cen e' in unita' di schermo (0,0) - (1,1)
		if ( pixel == NULL )
			throw Screen_Error(Screen_Error::NOB_CRE);
		Point size(Sh_trc.x-Sh_blc.x,Sh_trc.y-Sh_blc.y);
		Point cenSh((Sh_trc.x+Sh_blc.x)/2.,(Sh_trc.y+Sh_blc.y)/2.);
		Point c((cen.x-0.5)*size.x+cenSh.x,(cen.y-0.5)*size.y+cenSh.y);
		Sh_trc = Point(c.x+0.5*size.x,c.y+0.5*size.y);
		Sh_blc = Point(c.x-0.5*size.x,c.y-0.5*size.y);
		set_conversion();
	}

	void ASC_Screen::zoom(const bool& in)
	{
		if ( pixel == NULL )
			throw Screen_Error(Screen_Error::NOB_CRE);
		Point size(Sh_trc.x-Sh_blc.x,Sh_trc.y-Sh_blc.y);
		Point cenSh((Sh_trc.x+Sh_blc.x)/2.,(Sh_trc.y+Sh_blc.y)/2.);
		if ( in  )
		{
			Sh_trc = Point(cenSh.x+0.45*size.x,cenSh.y+0.45*size.y);
			Sh_blc = Point(cenSh.x-0.45*size.x,cenSh.y-0.45*size.y);
		}
		else
		{
			Sh_trc = Point(cenSh.x+0.55*size.x,cenSh.y+0.55*size.y);
			Sh_blc = Point(cenSh.x-0.55*size.x,cenSh.y-0.55*size.y);
		}
		set_conversion();
	}

	void ASC_Screen::OnScreen()
	{
		if ( pixel == NULL )
			throw Screen_Error(Screen_Error::NOB_CRE);
		int nSxt = nSx+1;
		int ntot = nSy*nSxt;
		for (int n=0; n < ntot; n+=nSxt) cout << pixel+n << '\n';
	}

	void ASC_Dot::draw()
	{
		draw_Dot(pp[0]);
	}

	void ASC_Line::draw()
	{
		draw_Line(pp[0],pp[1]);
	}

	void ASC_Triangle::draw()
	{
		draw_Polygon(nump,pp);
	}

	void ASC_Rect::draw()
	{
		draw_Polygon(nump,pp);
	}

	void ASC_Square::draw()
	{
		draw_Square(center,side);
	}

	void ASC_Circle::draw()
	{
		draw_Circle(center,side);
	}

	Screen_Error::Screen_Error(errind e)
	{
		switch (e)
		{
		case INV_SIZ : 
			sprintf(msg,"Invalid screen size\n"); break;
		case INV_SCR :
			sprintf(msg,"Invalid screen corners\n"); break;
		case NOB_CRE : 
			sprintf(msg,"No object created\n"); break;
		case ALR_CRE :
			sprintf(msg,
		"Screen coordinates should be set before creating objects\n"); break;
		}
	}
}