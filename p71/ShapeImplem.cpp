#include <iostream.h>
#include <stdio.h>
#include <math.h>
#include "ShapeInterf.h"

namespace mini_graphics
{
	extern const double epsp = 1e-6;
	extern const double epsm = -epsp;

	ostream& operator<<(ostream& out, const Point& p)
	{
		out << '(' << p.x << ',' << p.y << ')';
		return out;
	}

	istream& operator>>(istream& inp, Point& p)
	{
		inp >> p.x >> p.y;
		if ( inp.rdstate() > 0  )
			throw Shape_Error(Shape_Error::INP_ERR,0);
		return inp;
	}

	void INVF()
	{
		throw Shape_Error(Shape_Error::INV_FNC,0);
	}

	Polygon::Polygon(const int& n) : nump(n)
	{ 
		pp = new Point [nump];
	}

	void Polygon::set(const Point* pd)
	{
		for(int i=0; i<nump; i++) pp[i] = pd[i];
	}

	Point Polygon::get_corner(int i) const
	{
		if ( i < 0 || i >= nump ) 
			throw Shape_Error(Shape_Error::BAD_IND,i);
		return pp[i];
	}

	void Polygon::display(bool)
	{
		cout << pp[0];
		for(int i=1; i<nump; i++) cout << " - " << pp[i];
		cout << '\n';
	}

	void Polygon::copy_from(const Shape* from)
	{
		if ( nump != from->get_nump() )
			throw Shape_Error(Shape_Error::INV_CPY,0);
		for(int i=0; i<nump; i++) pp[i] = from->get_corner(i);
	}

	Polygon::~Polygon()
	{
		if ( nump == 1 ) delete pp;
		else delete [] pp;
	}

	Dot::Dot() : Polygon(1)
	{
		set(Point(0.,0.));
	}

	void Dot::set(const Point& p)
	{
		set(&p);
	}

	void Dot::display(bool)
	{
		cout << "Dot :      ";
		Polygon::display();
	}

	Line::Line() : Polygon(2)
	{
		set(Point(0.,0.),Point(1.,1.));
	}

	void Line::set(const Point& p1, const Point& p2)
	{
		Point pr[2];
		pr[0] = p1;
		pr[1] = p2;
		set(pr);
		double dx = pp[0].x -  pp[1].x;
		double dy = pp[0].y -  pp[1].y;
		if ( dx > epsm && dx < epsp && dy > epsm && dy < epsp )
			throw Shape_Error(Shape_Error::IMP_LIN,0);
	}
		
	void Line::display(bool)
	{
		cout << "Line :     ";
		Polygon::display();
	}

	Triangle::Triangle() : Polygon(3)
	{
		set(Point(0.,0.),Point(0.,1.),Point(1.,0.));
	}

	void Triangle::set(const Point& p1, const Point& p2, 
		const Point& p3)
	{
		Point corner[3];
		corner[0] = p1;
		corner[1] = p2;
		corner[2] = p3;
		set(corner);
		double norma[3];
		int i,j;
		for (i=0; i < 3; i++)
		{
			double px = pp[i].x-pp[(i+1)%3].x;
			double py = pp[i].y-pp[(i+1)%3].y;
			norma[i] = sqrt(px*px+py*py);
			if ( norma[i] < epsp )
				throw Shape_Error(Shape_Error::IMP_TRI,0);
		}
		int num = 3; // il blocco che segue ordina num numeri
		for (i=0; i < num-1; i++) for(j=0; j < num-1-i; j++)
		{
			if ( norma[j] > norma[j+1] )
			{
				double n = norma[j];
				norma[j] = norma[j+1];
				norma[j+1] = n;
			}
		}
		if ( norma[0] + norma[1] - norma[2] < epsp )
				throw Shape_Error(Shape_Error::IMP_TRI,0);
	}
		
	void Triangle::display(bool)
	{
		cout << "Triangle : ";
		Polygon::display();
	}

	Rect::Rect() : Polygon(4)
	{
		set(Point(0.,0.),Point(1.,1.));
	}

	void Rect::set(const Point& p1, const Point& p2)
	{
		Point blc,trc;
		if ( p1.x < p2.x )
		{
			blc.x = p1.x;
			trc.x = p2.x;
		}
		else 
		{
			blc.x = p2.x;
			trc.x = p1.x;
		}
		if ( p1.y > p2.y )
		{
			trc.y = p1.y;
			blc.y = p2.y;
		}
		else
		{
			trc.y = p2.y;
			blc.y = p1.y;
		}
		Point corner[4];
		corner[0] = blc;
		corner[1] = Point(blc.x,trc.y);
		corner[2] = trc;
		corner[3] = Point(trc.x,blc.y);
		set(corner);
		double dx = trc.x -  blc.x;
		double dy = trc.y -  blc.y;
		if ( dx < epsp || dy < epsp )
				throw Shape_Error(Shape_Error::IMP_REC,0);
	}
		
	void Rect::display(bool)
	{
		cout << "Rect :     ";
		Polygon::display();
	}

	void Regular::copy_from(const Shape* from)
	{
		center = from->get_center();
		side = from->get_side();
	}

	Square::Square() : Polygon(4)
	{
		set(Point(0.5,0.5),1.);
	}

	void Square::set(const Point& p, const double& s)
	{
		if ( s < epsp ) throw Shape_Error(Shape_Error::IMP_SQR,0);
		center = p;
		side = s;
		double hs = side*0.5;
		pp[0] = Point(p.x-hs,p.y-hs);
		pp[1] = Point(p.x-hs,p.y+hs);
		pp[2] = Point(p.x+hs,p.y+hs);
		pp[3] = Point(p.x+hs,p.y-hs);
	}

	void Square::copy_from(const Shape* from)
	{
		Regular::copy_from(from);
		set(get_center(),get_side());
	}

	void Square::display(bool spec)
	{
		cout << "Square :   ";
		if ( spec ) cout << "center = " << center << "     side = " <<
			side << '\n';
		else Polygon::display();
	}

	Circle::Circle()
	{
		set(Point(0.5,0.5),1.);
	}

	void Circle::set(const Point& p, const double& r)
	{
		center = p;
		side = r;
		if ( r < epsp ) throw Shape_Error(Shape_Error::IMP_CIR,0);
	}
		
	void Circle::display(bool)
	{
		cout << "Circle :   center = " << center << 
			"     diameter = " << side << '\n';
	}

	Shape_Error::Shape_Error(errind e, int item)
	{
		switch (e)
		{
		case INV_FNC : 
			sprintf(msg,"INVALID FUNCTION CALL\n"); break;
		case BAD_IND : 
			sprintf(msg,"Bad index %d\n",item); break;
		case INV_CPY :
			sprintf(msg,"Invalid copy request\n"); break;
		case IMP_LIN : 
			sprintf(msg,"Improper Line\n"); break;
		case IMP_TRI :
			sprintf(msg,"Improper Triangle\n"); break;
		case IMP_REC :
			sprintf(msg,"Improper Rectangle\n"); break;
		case IMP_SQR :
			sprintf(msg,"Improper Square\n"); break;
		case IMP_CIR :
			sprintf(msg,"Improper Circle\n"); break;
		case INP_ERR : 
			cin.clear();
			cin.ignore(1000,'\n');
			sprintf(msg,"Input Error\n");
		}
	}

}
