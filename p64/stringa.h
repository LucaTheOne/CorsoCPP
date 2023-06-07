#include <iostream.h>

namespace spazio_stringa
{
	class stringa
	{
		struct rappr;
		rappr* prappr;
		struct rifc
		{
			stringa& srif;
			int ind;
			rifc(stringa& str, int i) : srif(str), ind(i) { }
			void operator=(char c) { srif.inserisci(ind,c); }
			operator char() const { return srif.estrai(ind); }
		};
		void ricrea(char*, int);
	public:
		stringa();
		stringa(const char*);
		stringa(const stringa&);
		stringa& operator=(const stringa&);
		~stringa();
		char estrai(int) const;
		void inserisci(int, char);
		int dimensione() const;
		char operator [](int) const;
		rifc operator[](int); //Nota: restituisce un oggetto di rifc
		void ridimensiona(int);
		stringa& operator+=(const stringa&);
		friend bool operator==(const stringa&, const stringa&);
		friend ostream& operator<<(ostream&, const stringa&);
		friend istream& operator>>(istream&, stringa&);
	};

	struct Errore { };  //Per le eccezioni

	stringa operator+(const stringa&, const stringa&);
	bool operator!=(const stringa&, const stringa&);

	class bruttacopia
	{
		char* s;
		int dim;
	public:
		bruttacopia();
		bruttacopia(const char*);
		~bruttacopia();
		bruttacopia& operator=(const bruttacopia&);
	};
}


