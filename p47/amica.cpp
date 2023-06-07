#include <iostream.h>

class Prima
{   
    int mp;
    friend  class Seconda;
  public:
    void init(const int&);
} ;

class Seconda
{   
  public:
    static void show(const Prima&);
} ;

void Prima::init(const int& i)
{
	mp = i;
}

void Seconda::show(const Prima& p)
{
   cout <<  "Valore visto dalla classe Seconda: "  << p.mp << '\n';
}

int  main()
{
	int i;
	Prima p;
	cout << "Valore da inserire nella classe Prima: ";  cin >> i;
	p.init(i);
	Seconda::show(p);
	return 0;
}
