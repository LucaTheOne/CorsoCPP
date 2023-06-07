#include <iostream.h>

class Persona
{     
	char* nome;
	char* cognome;
	static int strlen(const char*);
	static void strcpy(const char*, char*);
public:
	Persona(const char*, const char*);
	~Persona();
	void show();
};

Persona::Persona(const char* no, const char* co)
{
   nome = new char [strlen(no)];
   cognome = new char [strlen(co)];
   strcpy(no,nome);
   strcpy(co,cognome);
   cout << "Ho costruito l'oggetto:     " ;
}

Persona::~Persona()
{
   delete [] nome;
   delete [] cognome;
   cout << "Ho distrutto l'oggetto !!!!" << '\n';
}

void Persona::show()
{
	cout << "Nome: " << nome << 
		    "   Cognome: " << cognome << '\n';
}

int Persona::strlen(const char* str)
{
	int len = 0;
	while(*(str+len)) len++;
	return len+1;
}

void Persona::strcpy(const char* inpstr, char* outstr)
{
	while (*outstr++ = *inpstr++);
}

int main()
{
	char no[30];
	char co[30];
	char answer;
	do   
	{
		cout << "Nome e Cognome: "; cin>>no>>co;
		Persona uno (no,co);
		uno.show();
		cout << "Continui (s/...) ? "; cin >> answer;
		// l'oggetto "uno" esce dal suo ambito di visibilita'
	} while ( answer == 's' );
	return 0;
}
