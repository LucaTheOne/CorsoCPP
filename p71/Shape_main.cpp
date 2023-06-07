#include <iostream.h>
#include "ShapeInterf.h"

int main()
{
#include "Shape_using.h"
	Shape* ptr[6];
	Shape* pdf[6];
	pdf[0] = new Dot;			ptr[0] = new Dot;
	pdf[1] = new Line;			ptr[1] = new Line;
	pdf[2] = new Triangle;		ptr[2] = new Triangle;
	pdf[3] = new Rect;			ptr[3] = new Rect;
	pdf[4] = new Square;		ptr[4] = new Square;
	pdf[5] = new Circle;		ptr[5] = new Circle;
	int i, id;
	Point p1,p2,p3;
	double d;
	while (true) 
	{
		try
		{
			cout << "\n\n";
			for (i=0; i<6; i++) ptr[i]->display();
			char ch;
			cout << "\nModify Shape:\n";
			cout << "   0   = Dot\n";
			cout << "   1   = Line\n";
			cout << "   2   = Triangle\n";
			cout << "   3   = Rect\n";
			cout << "   4   = Square\n";
			cout << "   5   = Circle\n";
			cout << "   else EXIT";
			cout << "        ? "; cin >> ch;
			id = ch-48;
			if ( id < 0 || id > 5 ) break;
			switch (id)
			{
			case 0 : cout << "Insert point: ";
					 cin >> p1;
					 ptr[0]->set(p1); break;
			case 1 : cout << "Insert line end-points: ";
					 cin >> p1 >> p2;
					 ptr[1]->set(p1,p2); break;
			case 2 : cout << "Insert triangle vertex-points: ";
					 cin >> p1 >> p2 >> p3;
					 ptr[2]->set(p1,p2,p3); break;
			case 3 : cout << "Insert rectangle bottom-left corner" <<
						 " and top right corner: ";
					 cin >> p1 >> p2;
					 ptr[3]->set(p1,p2); break;
			case 4 : cout << "Insert square center and side: ";
					 cin >> p1 >> d;
					 if ( cin.rdstate() > 0  )
						throw Shape_Error(Shape_Error::INP_ERR,0);
					 ptr[4]->set(p1,d); break;
			case 5 : cout << "Insert circle center and diameter: ";
					 cin >> p1 >> d;
					 if ( cin.rdstate() > 0  )
						throw Shape_Error(Shape_Error::INP_ERR,0);
					 ptr[5]->set(p1,d);
			}
		}
		catch (Shape_Error e)
		{
			cout << e.msg;
			ptr[id]->copy_from(pdf[id]);
		}
	}
	cout << "\n\n";
	for (i=0; i < 6; i++)  ptr[i]->display();
	ptr[4]->display(true);
	for (i=0; i < 6; i++)
	{
		delete pdf[i];
		delete ptr[i];
	}
	return 0;
}
