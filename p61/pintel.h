struct tipodouble
{
	double valore;
	tipodouble* next;
};

class Ptr
{
	tipodouble* pfirst;
	tipodouble* plast;
	double newval;
public:
	Ptr() : pfirst(NULL), plast(NULL), newval(0.0) { }
	~Ptr();
	tipodouble* operator->();
	double operator()(int);
};

struct Error 
{
	const char* msg;
	Error(const char* err) : msg(err) { }
};


#define READ  0
#define WRITE 1 