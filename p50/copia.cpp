#include <iostream.h>

class Coppia
{
	double x;
	double y;
  public:
	Coppia(const double& x0, const double& y0)
		{  x = x0;  y = y0;  }
// provare a commentare la prossima istruzione e vedere cosa succede
	Coppia(const Coppia& A)	{  x = A.y;  y = A.x; }
	void show() { cout << x << "  " << y << '\n' ; }
} ;

int main()
{
	Coppia c1 (13.4,2.7);
	Coppia c2 = c1;
	c1.show();
	c2.show();
	return 0;
}
