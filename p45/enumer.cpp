#define IDA 10
#define IDB 20

#include <iostream.h>

class A
{ 
public:	 
	enum tipo1 { ID1=IDA,ID2 } membro1;
	enum tipo2 { ID2 } membro2;   // errore: ridefinizione di ID2
};

class B	 
{
public:
	 enum { ID1=IDB,ID2 };  
};

int main()
{
	cout << A::ID1 << ' ' << A::ID2 << '\n' <<
	   B::ID1 << ' ' << B::ID2 << '\n';
	return 0;
}
