struct data; 

struct persona 
{
	char nome[20];
	char cognome[20];
	data* pnascita;
} ;

struct data 
{
	int giorno;
	int mese;
	int anno;
	persona pippo;
};

void get_ident(persona*);
void print_ident(const persona&);

