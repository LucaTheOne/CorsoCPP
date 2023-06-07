namespace Oggetto_array
{
	class A
	{
		int dim;
		int* arr;
	public:
		A(int);
		~A();
		int& operator[](const int&);
		void operator&();
		void setdim(int);
		int getdim() const { return dim; };
		friend ostream& operator<<(ostream&, const A&);
	};
	struct Error
	{
		int e;
		Error(const int& i) : e(i) { }
	};
}
