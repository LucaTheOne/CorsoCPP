#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

namespace My_region
{
	void minus(int i)
	{
		cout << "L'opposto di " << i << " e' " << -i << '\n';
	}

	template <class T> class Sum
	{
		T res;
	public:
		Sum() : res(T(0)) {}
		void operator()(T x) { res += x;}
		T result()  const { return res; }
	};

	template <class T> ostream& operator<<(ostream& out, const Sum<T>& s)
	{
		out << s.result();
		return out;
	}
}

int main()
{
	using My_region::minus;
	using My_region::Sum;
	vector<int> vi(5);
	vi[0] = 5; vi[1] = 0; vi[2] = -7; vi[3] = 6; vi[4] = -1;

	for_each(vi.begin(),vi.end(),minus);
	cout << "Somma = " << for_each(vi.begin(),vi.end(),Sum<int>()) << '\n';

	return 0;
}

