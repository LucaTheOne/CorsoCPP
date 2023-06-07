namespace My_region
{
	class Bin;
	class Bins
	{
		int nBin;
		int ntot;
		int maxmax;
		Bin** pBin;
	public:
		Bins(const int&);
		~Bins();
		void insert(const int&);
		void show();
	};

	struct Error
	{
		const char* descr;
		Error(); 
	};
}

