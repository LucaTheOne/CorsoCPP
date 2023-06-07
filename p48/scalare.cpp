#include <iostream.h>

namespace My_region
{
	class point
	{
		double x;
		double y;
		static int cont;
		int objnum;
	public:
		point(const double& =0.0, const double& =0.0);
		~point();
		static double scalar(const point&, const point&);
	};

	int point::cont;

	point::point(const double& x0, const double& y0)
	{
		x = x0;
		y = y0;
		cout << "Costruito oggetto " << ++cont << "  con i valori: "
			<< x0 << " e " << y0 << '\n' ;
		objnum = cont;
	}

	point::~point()
	{
		cout << "Distrutto oggetto " << objnum << '\n';
		cont--;
	}

	double point::scalar(const point& p1, const point& p2)
	{
		return p1.x*p2.x + p1.y*p2.y ;
	}
}

int main()
{
	using My_region::point;
	char answer;
	do
	{
		point* ptr[2];
		for (int i=0; i<2; i++)
		{
			cout << "Inserisci coordinate del punto " << i+1 << ": ";
			double x,y;
			cin >> x >> y;
			ptr[i] = new point (x,y);
		}
		cout << "Prodotto scalare: " << point::scalar(*ptr[0],*ptr[1])
			<< '\n' ;
		delete ptr[0];
		delete ptr[1];
		cout << "\nContinui (s/...) ? "; cin >> answer;
		cout << '\n' ;
	} while ( answer == 's' );
	{
		point origine;
		cout << "Per ora l'oggetto e' ancora vivo\n";
	}
	cout << "Adesso ha proprio finito!\n\n";
	return 0;
}