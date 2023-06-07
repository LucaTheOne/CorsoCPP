#include <iomanip.h>
#include <time.h>

namespace My_region
{
	extern int num_cicli;
	extern int num_scambi;

	template<class T> void swap(T& a, T& b)
	{
		num_scambi++;
		T temp = a;
		a = b;
		b = temp;
	}

	template<class T> struct Shift
	{
		static void shift_sort(int n, T* p)
		{
			bool ordered;
			for (int i=0; i < n-1; i++) 
			{
				ordered = true;
				for(int j=0; j < n-i-1; j++)
				{
					num_cicli++;
					if ( p[j+1] < p[j] ) 
					{
						ordered = false; 
						swap(p[j],p[j+1]);
					}
				}
				if ( ordered ) break;
			}
		}
		static void sort(int n, T* p)
		{
			cout << "Shift sort :" << flush;
			shift_sort(n,p);
		}
	private:
		Shift() { }
	};

	template<class T> struct Shell
	{
		static void sort(int n, T* p)
		{
			cout << "Shell sort :" << flush;
            for (int gap=n/2; gap > 0; gap/=2)
                for (int i=gap; i<n; i++)
                    for (int j=i-gap; j>=0; j-=gap)
                    {
                        num_cicli++;
                        if(p[j+gap]<p[j]) swap(p[j+gap],p[j]);
                    }
		}
	private:
		Shell() { }
	};

	template<class T> struct Comb
	{
		static void sort(int n, T* p)
		{
			cout << "Comb  sort :" << flush;
			int offset = n;
			while ( offset > 1 )
			{
				offset = 8*offset/11;
				for (int i=0; i<n-offset; i++ )
				{
					num_cicli++;
					if ( p[i+offset] < p[i] ) swap(p[i],p[i+offset]);
				}
			}
			Shift<T>::shift_sort(n,p);
	    }
	private:
		Comb() { }
	};

	template<class O,class T> void sort(int n, T* p)
	{
		if ( n < 2 )
		{
			cout << "numero dati insufficiente\n";
			return;
		}
		int num_secondi = time(NULL);
		O::sort(n,p);
		num_secondi = time(NULL) - num_secondi;
		cout << setw(4) << num_secondi << " secondi," << 
			    setw(10) << num_cicli << " cicli," << 
				setw(10) << num_scambi << " scambi - ";
		int j;
		for (j=0; j < n-1 && !(p[j+1] < p[j]); j++);
		if ( j == n-1 )	cout << "OK !!!\n";
		else cout << "NON IN ORDINE !!! (nella posizione " << j
			<< ")\n";
		num_cicli = num_scambi = 0;
	}

	class vector
	{
		int num;
		double* v;
		double varianza;
	public:
		vector();
		vector(const vector&);
		~vector();
		vector& operator=(const vector&);
		friend bool operator<(const vector&, const vector&);
		friend bool operator==(const vector&, const vector&);
	};
}

