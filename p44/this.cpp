#include <iostream.h>

class Oggetti
{
	int ns;
  public:
	void zero() { ns = 0; }
	Oggetti& accesso()  { ns++; return *this; }
	void show() const;
} ;

void Oggetti::show()  const
{
	cout << "\t\t" ;
	if ( ns == 1 ) 	cout << "1 accesso\n" ;
	else            cout << ns << " accessi\n"; 
}


int main()
{
	Oggetti obj[10];
	int i;
	for (i=0; i<10; i++)   obj[i].zero() ;
	cout << "Oggetto num.: " ;  cin >> i ;
	while ( i >= 0 && i < 10 )  
	{
	    obj[i].accesso().show() ;
	    cout << "Oggetto num.: " ;  cin >> i ;
	}
	return 0;
}
