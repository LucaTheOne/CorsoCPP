#include <iostream.h>

namespace Date_and_Time
{
	class Ident
	{
	protected:
		int ident;
		Ident(int);
	};

	class Date : virtual protected Ident
	{
		int Year;
		int Month;
		int Day;
		void write();
	protected:
		char descr[12];
		Date (int);
		Date& operator+=(int);
		bool operator<(const Date&) const;
		bool operator==(const Date&) const;
	};

	class Time : virtual protected Ident
	{
		int Hour;
		int Min;
		int Sec;
		int DayOver;
	protected:
		char descr[9];
		int over() const { return DayOver; }
		void reset() { DayOver = 0; }
		Time(int);
		Time& operator+=(const int&);
		bool operator<(const Time&) const;
	};

	class Date_Time :  Date, Time  // accesso private di default
	{
		Date_Time(int);
		Date_Time& operator+=(const int&);
		bool operator<(const Date_Time&) const;
		void write() const;
		Date_Time* pnext;
		friend class Manage;
	};

	struct Error
	{
		char msg[50];
		Error(int);
	};
}