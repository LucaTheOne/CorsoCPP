#include "stringa.h"

// La macro test serve in fase di debug
#ifdef _DEBUG
#define test(msg,ogg) cout << "*********"msg": \"" << ogg.prappr->s << \
"\" aggangiata da " << ogg.prappr->conta << " oggetti\n";
#endif

namespace spazio_stringa
{
// Alcune funzioni inline usate solo dall'implementazione di stringa ....
	inline void controlla(int dim, int ind)
	{
		if ( ind < 0 || ind >= dim ) throw Errore();
	}

// Le funzioni confronta, lunghezza e copia operano su stringhe "in stile
// C" (non si � voluto ricorrere alle funzioni di libreria per rendere
// questo modulo indipendente dalle librerie del C)
	inline bool confronta(const char* str1, const char* str2)
	{
		while( *str1 && *str1 == *str2 ) str1++,str2++;
		return !*str1 && !*str2;
	}

	inline int lunghezza(const char* str)
	{
		int len = 0;
		while(*(str+len)) len++;
		return len;
	}

	inline void copia(const char* inpstr, char* outstr)
	{
		while (*outstr++ = *inpstr++);
	}

	struct stringa::rappr
	{
		char* s;
		int dim;
		int conta;
		rappr() : conta(1) { }
		rappr(const char* str) : conta(1), dim(lunghezza(str))
		{
			s = new char [dim+1]; // una posizione in pi� per il terminator
			copia(str,s);
		}
		~rappr() { delete [] s; }
		rappr* clona()
		{
			if ( conta == 1 ) return this;
			conta--;
			return new rappr(s); // copia se stesso
		}
	};

	stringa::stringa()
	{
		prappr = new rappr("");
	}

	stringa::stringa(const char* str)
	{
		prappr = new rappr(str);
	}

	stringa::stringa(const stringa& str)
	{
		str.prappr->conta++;
		prappr = str.prappr;  // condivide la rappresentazione di str
#ifdef _DEBUG
test("Costruttore di copia",str)
#endif
	}

	stringa& stringa::operator=(const stringa& str)
	{
		str.prappr->conta++;   // prima questa istuzione, per prottegersi 
//                                dalle auto-assegnazioni 
		if ( --prappr->conta == 0 ) delete prappr; //
		prappr = str.prappr;   // condivide la rappresentazione
#ifdef _DEBUG
test("Oper. di assegnazione",str)
#endif
		return *this;
	}

	stringa::~stringa()
	{
#ifdef _DEBUG
test("Distruttore",(*this))
#endif
		if ( --prappr->conta == 0 ) delete prappr;
	}

	char stringa::estrai(int i) const
	{
#ifdef _DEBUG
test("Estrazione",(*this))
#endif
		return  prappr->s[i];
	}

	void stringa::inserisci(int i, char c)
	{
		prappr = prappr->clona();
		prappr->s[i] = c;
#ifdef _DEBUG
test("Inserimento",(*this))
#endif
	}

	int stringa::dimensione() const
	{
		return prappr->dim;
	}

	char stringa::operator[](int i) const
	{
		controlla(dimensione(),i);
		return estrai(i);
	}

	stringa::rifc stringa::operator[](int i)
	{
		controlla(dimensione(),i);
		return rifc(*this,i);
	}

	void stringa::ricrea(char* s, int d)
	{
		if ( --prappr->conta == 0 ) delete prappr;
		prappr = new rappr();
		prappr->s = s;
		prappr->dim = d;
	}

	void stringa::ridimensiona(int d)
	{
		int dim = dimensione();
		if ( d == dim ) return;
		char* s = new char [d+1];
		int i = 0;
		while ( i < dim && i < d ) s[i++] = prappr->s[i];
		while ( i < d ) s[i++] = ' ';
		s[d] = '\0';
		ricrea(s,d);
	}

	stringa& stringa::operator+=(const stringa& str)
	{
		int dim = dimensione();
		int d = dim+str.dimensione();
		ridimensiona(d);
		for (int i=dim; i < d; i++) prappr->s[i] = str.prappr->s[i-dim];
		return *this;
	}

	stringa operator+(const stringa& str1, const stringa& str2)
	{
		stringa temp = str1;
		temp += str2;
		return temp;
	}

	bool operator==(const stringa& str1, const stringa& str2)
	{
		return confronta(str1.prappr->s,str2.prappr->s);
	}

	bool operator!=(const stringa& str1, const stringa& str2)
	{
		return !(str1==str2);
	}

	ostream& operator<<(ostream& out, const stringa& str)
	{
		out << str.prappr->s;
		return out;
	}

	istream& operator>>(istream& inp, stringa& str)
	{
// Per analogia con l'overload di operator>> per le stringhe "in stile C",
// uso i blanks e gli altri caratteri speciali come separatori fra stringhe
// Procedo con allocazioni successive ad incrementi di 10 finch� non ho
// memorizzato tutta la stringa
		const int incremento = 10;
		const char separatore = ' ';
		char ch;
		int dim = incremento;
		char* s = new char [dim+1];
		str.ricrea(s,dim);
		int numc = 0;
		inp >> ch;
		do 
		{
			if ( numc >= dim )
			{
				dim += incremento;
				str.ridimensiona(dim);
			}
			str.prappr->s[numc++] = ch;
			cin.get(ch);
		} while ( ch > separatore );
		str.prappr->s[numc] = '\0';
		if ( numc < dim ) str.ridimensiona(numc);
		return inp;
	}

}


