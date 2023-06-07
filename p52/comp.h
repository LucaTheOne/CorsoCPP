class Comp1
{
	int me;
 public:
	Comp1(const int&);
	Comp1(const Comp1&);
	~Comp1();
} ;

class Comp2
{
	int me;
 public:
	Comp2(const int&);
 	~Comp2();
} ;

class Compt 
{
	int me;
	Comp1 me1;
	Comp2 me2;
 public:
	Compt(const int& , const int& , const int& );
	Compt(const int&, const Comp1&, const Comp2&);
	~Compt();
} ;
