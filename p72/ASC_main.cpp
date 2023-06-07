#include <iostream.h>
#include "AscInterf.h"

int main()
{
#include "ASC_using.h"
	ASC_Screen* pts[24];
	Shape* pth[24];
	try {
	ASC_Screen::set_Screen_corners(Point(-10.,0.),Point(10.,10.));
	ASC_Rect R[7];
	ASC_Triangle T[2];
	ASC_Line L[8];
	ASC_Dot D[5];
	ASC_Circle C;
	ASC_Square S;
	int i=0, j;
	for (j=0; j<7; j++) pth[i]=&R[j], pts[i++]=&R[j]; 
	for (j=0; j<2; j++) pth[i]=&T[j], pts[i++]=&T[j]; 
	for (j=0; j<8; j++) pth[i]=&L[j], pts[i++]=&L[j]; 
	for (j=0; j<5; j++) pth[i]=&D[j], pts[i++]=&D[j];
	pth[i]=&C; pts[i++]=&C;
	pth[i]=&S; pts[i]=&S;

	pth[0]->set(Point(-5.,2.),Point(5.,7.)); // facciata
	pth[1]->set(Point(-0.8,2.),Point(0.,3.8));  // porta ( prima anta)
	pth[2]->set(Point(0.,2.),Point(0.8,3.8)); // porta (seconda anta)
	pth[3]->set(Point(-4.,5.),Point(-3.5,6.2)); // finestra sinistra (prima anta)
	pth[4]->set(Point(-3.5,5.),Point(-3.,6.2)); // finestra sinistra (seconda anta) 
	pth[5]->set(Point(4.,5.),Point(3.5,6.2)); // finestra destra (prima anta)
	pth[6]->set(Point(3.5,5.),Point(3.,6.2)); // finestra destra (seconda anta)
	pth[7]->set(Point(-0.8,3.8),Point(0.8,3.8),Point(0.,5.)); // tettuccio porta
	pth[8]->set(Point(-5.,7.),Point(5.,7.),Point(0.,10.)); // tetto
	pth[9]->set(Point(-5.,2.),Point(-5.75,0.8)); // linea sin. piazz. di ingresso
	pth[10]->set(Point(5.,2.),Point(5.75,0.8)); // linea ds. piazz. di ingresso
	pth[11]->set(Point(-5.75,0.8),Point(5.75,0.8)); // linea davanti piazz. di ingresso
	pth[12]->set(Point(-1.,0.8),Point(-3.,-2.4)); // linea sinistra strada
	pth[13]->set(Point(1.,0.8),Point(3.,-2.4)); // linea destra strada
	pth[14]->set(Point(3.,8.2),Point(3.,9.2)); // linea sinistra camino
	pth[15]->set(Point(4.,7.6),Point(4.,8.6)); // linea destra camino
	pth[16]->set(Point(3.,9.2),Point(4.,8.6)); // linea superiore camino
	pth[17]->set(Point(4.,9.2)); // fumo camino
	pth[18]->set(Point(4.2,9.6)); // fumo camino
	pth[19]->set(Point(4.5,10.)); // fumo camino
	pth[20]->set(Point(4.8,10.)); // fumo camino
	pth[21]->set(Point(1.5,4.)); // targhetta numero civico
	pth[22]->set(Point(0.,8.5),0.8); // lucernaio
	pth[23]->set(Point(0.,6.),0.8); // finestrina centrale

	Point cen;
	char zoom;
	while (true)
	{
		ASC_Screen::clear();
		for (j=0; j<24; j++) pts[j]->draw();
		ASC_Screen::OnScreen();
		cout << "Zoom aumenta(+), riduci(-) o cambia punto centrale(p) ";
		cin >> zoom;
		if ( zoom == 'p' )
		{
			cin >> cen ;
			ASC_Screen::move_center(cen);
		}
		else if ( zoom != '+' && zoom != '-' ) break;
		else if ( zoom == '+' ) ASC_Screen::zoom();
		else ASC_Screen::zoom(false);
	}
	}
	catch (Shape_Error e)
	{
		cout << e.msg;
	}
	catch (Screen_Error e)
	{
		cout << e.msg;
	}
	return 0;
}