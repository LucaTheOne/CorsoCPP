namespace Punto_sul_piano
{
	class point
	{
		double x,y;
	public:
		point();
		point(const double&, const double&);
		friend ostream& operator<<(ostream&, const point&);
		double getx() const { return x; }
		double gety() const { return y; }
	};
}

namespace RotoTraslazione
{
	namespace PP = Punto_sul_piano;
	class rttr
	{
		double deg, co, si, xtr, ytr;
	public:
		rttr(const double&, const double& =0.0, const double& =0.0);
		PP::point operator()(const PP::point&);
		rttr operator!();  // calcola matrice inversa
		friend ostream& operator<<(ostream&, const rttr&);
	};
}



