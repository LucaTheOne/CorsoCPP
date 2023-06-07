namespace My_region
{
	class Valori
	{
		static double defval;
		double val[5];
	public:
		static void changedef(const double&);
		void init();
		double& access(int);
	};
	struct Error
	{
	};
}