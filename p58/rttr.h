namespace RotoTraslazione
{
	class rttr;
}

namespace Punto_sul_piano
{
	namespace RT = RotoTraslazione;
	class point
	{
		double x,y;
	public:
		point(const double&, const double&);
		friend point operator *(const point&, const RT::rttr&);
		friend void operator/(const char*, const point&);
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
		friend PP::point PP::operator *(const point&, const rttr&);
		friend void operator/(const char*, const rttr&);
	};
}



