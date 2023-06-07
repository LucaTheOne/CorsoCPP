#include <iostream.h>

class CArea
{
	int dim;
	int* ptr;
public:
	CArea(int);
	~CArea()  { delete [] ptr; }
	CArea& operator=(const CArea&);
	void operator&();
};

CArea::CArea(int num)
{
	num = num < 2 ? 2 : num > 10 ? 10 : num;
	ptr = new int [num];
	cout << "Inserisci " << num << " numeri interi: ";
	for (int i=0; i<num; i++) cin >> *(ptr+i) ;
	dim = num;
}

CArea& CArea::operator=(const CArea& ar)
{
	if (this==&ar) return *this;
	if (dim != ar.dim)
	{
		delete [] ptr;
		dim = ar.dim;
		ptr = new int [dim];
	}
	for (int i=0; i < dim ; i++) *(ptr+i) = *(ar.ptr+i) ;
	return *this;
}

void CArea::operator&()
{
	for(int i=0; i < dim; i++) cout << 	*(ptr+i) << "   ";
	cout << '\n';
}

int main()
{
	int n;
	cout << "Numero elementi del primo oggetto: "; cin >> n;
	CArea* parea = new CArea (n);
 	cout << "Numero elementi del secondo oggetto: "; cin >> n;
	CArea ar2(n);
	ar2 = *parea;
	delete parea;
	cout << "Secondo oggetto dopo la copia:\n\t";
	&ar2;
	return 0;
}
