#include <iostream.h>

class A
{
protected:
	int ma;
public:
	int getA() const { return ma; }
	void setA(int a) { ma = a; }
	void showA() const
	{
		cout << "A: " << ma << '\n';
	}
};

class B : public A
{
	int mb;
public:
	void setB(int a, int b)
	{
		ma = a;
		mb = b;
	}
	void showB() const
	{
		cout << "A: " << ma << "    B: " << mb << '\n';
	}
};

class C : public A
{
public:
	C(const A& a)
	{
		setA(a.getA());
	}
};

void main()
{
	char ans;

	cout << "sizeof(A) = " << sizeof(A) << '\n';
	cout << "sizeof(B) = " << sizeof(B) << '\n';  // comprende anche A

	cout << "\nSezione puntatori -------------------\n";
	A* pa = new A;
	B* pb = new B;
	pa->setA(60);
	pb->setB(23,87);
	cout << "pa->   ";
	pa->showA();
	cout << "pb->   ";
	pb->showB();
	A* ppa;
	cout << "Assegno il puntatore ppa a classe A? (s/altro) ";
	cin >> ans;
	if ( ans == 's' ) ppa = pa;
	else ppa = pb;
	ppa->showA();
	B* ppb;
	cout << "Assegno il puntatore ppb a classe B? (s/altro) "; cin >> ans;
	if ( ans == 's' ) ppb = pb;
	else ppb = (B*)pa; //casting obbligatorio
	ppb->showA();  // ok, showA è membro di B ereditato da A
	ppb->showB();  // se usa pa, il membro mb è a caso
	delete pa;
	delete pb;

	cout << "\nSezione riferimenti --------------------------\n";
	A a;
	B b;
	a.setA(29);
	b.setB(14,38);
	cout << "a =   ";
	a.showA();
	cout << "b =   ";
	b.showB();
	A& ra = b;   // ok
	cout << "A& ra = b ---> ";
	ra.showA();
	B& rb = (B&)a; // casting obbligatorio
	cout << "B& rb = (B&)a ---> ";
	rb.showB();  // mb è a caso

	cout << "\nSezione oggetti --------------------------\n";
	B bb;
	bb.setB(56,58);
	cout << "bb =   ";
	bb.showB();
	A aa = bb;     // ok, conversione implicita
	cout << "aa =   ";
	aa.showA();
//	B bc = aa;  // errore
//	B bc = (B)aa;  // neanche questo gli piace
	C cc = aa; // questo si perchè è definito il costruttore
	cout << "cc =   ";
	cc.showA();

	cout << "\nEccezione classe derivata? (s/altro) "; cin >> ans;
	if ( ans == 's' ) 
	{
		try
		{
			throw B();
		}
		catch(A)
		{
			cout << "Eccezione catturata!!!\n" ;   // ok
		}
	}
	else
	{
		try
		{
			throw A();
		}
		catch(B)
		{
			cout << "Eccezione catturata!!!\n" ;   // non è vero !!!
		}
	}
}
