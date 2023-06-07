namespace My_date
{
	class date 
	{
		int giorno;
		int mese;
		int anno;
	  public:
		void set(const int&, const int&, const int&);
		void get(int&, const char*&, int&) const;
	} ;

	struct Error
	{
		void copymsg(const char*);
		char message[90];
	} ;
}

