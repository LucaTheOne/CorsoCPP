#include <iostream.h>

class Nonna 
{
private: int n1;
protected: int n2;
public: int n3;
		Nonna() : n1(0),n2(0), n3(0) {}
		void scrivi_Nonna() const;
} ;

class Mamma : protected  Nonna
{
private: int m1;
protected: int m2;
public: int m3;
		Mamma() : m1(0),m2(0), m3(0) {}
		void scrivi_Mamma() const;
} ;

class Figlia : Mamma    // accesso private di default
{
private: int f1;
protected: int f2;
public:	int f3;
		Figlia() : f1(0),f2(0), f3(0) {}
		void scrivi_Figlia() const;
};

void Nonna::scrivi_Nonna() const
{
	cout << "\nFunzione-membro scrivi_Nonna:\n";
	cout << "n1 = " << n1 << '\n';
	cout << "n2 = " << n2 << '\n';
	cout << "n3 = " << n3 << '\n';
}

void Mamma::scrivi_Mamma() const
{
	cout << "\nFunzione-membro scrivi_Mamma:\n";
//	cout << "n1 = " << n1 << '\n';  // errore
	cout << "n1 e' privato: non si eredita\n";
	cout << "n2 = " << n2 << '\n';
	cout << "n3 = " << n3 << '\n';
	cout << "m1 = " << m1 << '\n';
	cout << "m2 = " << m2 << '\n';
	cout << "m3 = " << m3 << '\n';
}

void Figlia::scrivi_Figlia() const
{
	cout << "\nFunzione-membro scrivi_Figlia:\n";
//	cout << "n1 = " << n1 << '\n';  // errore
	cout << "n1 e' privato: non si eredita\n";
	cout << "n2 = " << n2 << '\n';
	cout << "n3 = " << n3 << '\n';
//	cout << "m1 = " << m1 << '\n';  // errore
	cout << "m1 e' privato: non si eredita\n";
	cout << "m2 = " << m2 << '\n';
	cout << "m3 = " << m3 << '\n';
	cout << "f1 = " << f1 << '\n';
	cout << "f2 = " << f2 << '\n';
	cout << "f3 = " << f3 << '\n';
}

void scrivi_Figlia(const Figlia& f)
{
	cout << "\nFunzione globale scrivi_Figlia:\n";
//	cout << "n1 = " << f.n1 << '\n';  // errore
	cout << "n1 e' privato: inaccessibile\n";
//	cout << "n2 = " << f.n2 << '\n';  // errore
	cout << "n2 e' protetto: inaccessibile\n";
//	cout << "n3 = " << f.n3 << '\n';  // errore
	cout << "n3 e' protetto (in Mamma): inaccessibile\n";
//	cout << "m1 = " << f.m1 << '\n';  // errore
	cout << "m1 e' privato: inaccessibile\n";
//	cout << "m2 = " << f.m2 << '\n';  // errore
	cout << "m2 e' protetto: inaccessibile\n";
//	cout << "m3 = " << f.m3 << '\n';  // errore
	cout << "m3 e' privato (in Figlia): inaccessibile\n";
//	cout << "f1 = " << f.f1 << '\n';  // errore
	cout << "f1 e' privato: inaccessibile\n";
//	cout << "f2 = " << f.f2 << '\n';  // errore
	cout << "f2 e' protetto: inaccessibile\n";
	cout << "f3 = " << f.f3 << '\n';
}

int main()
{
	{
		Nonna n;
		n.scrivi_Nonna();
	}
	{
		Mamma m;
		m.scrivi_Mamma();
	}
	cout << "\nPremi return per visualizzare il secondo blocco ";
	char c;
	cin.get(c);
	Figlia f;
	f.scrivi_Figlia();
	scrivi_Figlia(f);
	return 0;
}
