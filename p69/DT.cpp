#include <stdio.h>
#include "DT.h"

namespace Date_and_Time
{
	inline int bis(int year)
	{
		return (year % 4 || !(year % 100) && year % 400) ? 28 : 29;
	}

	Ident::Ident(int id) : ident(id) {	}

	Date::Date(int id) : Ident(id)
	{
		if ( id != 2 )
		{
			int d,m,y;
			cin >> d >> m >> y;
			if ( cin.rdstate() > 0 ) throw Error(-1000000000);
			if ( y < 1000 ) throw Error(y);
			if ( m < 1 || m > 12 ) throw Error(m);
			int dpm[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
			dpm[1] = bis(y);
			if ( d < 1 || d > dpm[m-1] ) throw Error(d); 
			Day = d;
			Month = m;
			Year = y;
			write();
		}
	}

	Date& Date::operator+=(int ndays)
	{
		int dpm[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		dpm[1] = bis(Year);
		while (ndays > 0 )
		{
			int temp = Day+ndays;
			if ( temp > dpm[Month-1] )
			{
				ndays += Day-dpm[Month-1]-1;
				Day = 1;
				Month++;
				if ( Month > 12 )
				{
					Month = 1;
					Year++;
					dpm[1] = bis(Year);
				}
			}
			else
			{
				Day = temp;
				ndays = 0;
			}
		}
		write();
		return *this;
	}

	bool Date::operator<(const Date& D) const
	{
		if ( Year < D.Year ) return true;
		if ( Year > D.Year ) return false;
		if ( Month < D.Month ) return true;
		if ( Month > D.Month ) return false;
		return Day < D.Day;
	}

	bool Date::operator==(const Date& D) const
	{
		return Year == D.Year && Month == D.Month && Day == D.Day;
	}

	void Date::write()
	{
		char* mese[12] ={"Gen","Feb","Mar","Apr","Mag","Giu",
			"Lug","Ago","Set","Ott","Nov","Dic"} ;
		sprintf(descr,"%02d-%s-%04d",Day,mese[Month-1],Year);
	}

	Time::Time(int id) : Ident(id), DayOver(0)
	{
		if ( id != 1 )
		{
			int h,m,s;
			cin >> h >> m >> s;
			if ( cin.rdstate() > 0 ) throw Error(-1000000000);
			if ( h < 0 || h > 23 ) throw Error(h);
			if ( m < 0 || m > 59 ) throw Error(m);
			if ( s < 0 || s > 59 ) throw Error(s);
			Hour = h;
			Min = m;
			Sec = s;
			sprintf(descr,"%02d:%02d:%02d",Hour,Min,Sec);
		}
	}

	Time& Time::operator+=(const int& sec)
	{
		int nsecs = Hour*3600+Min*60+Sec+sec;
		DayOver = nsecs/86400;
		nsecs %= 86400;
		Hour = nsecs/3600;
		nsecs %= 3600;
		Min = nsecs/60;
		Sec = nsecs % 60;
		sprintf(descr,"%02d:%02d:%02d",Hour,Min,Sec);
		return *this;
	}

	bool Time::operator<(const Time& T) const
	{
		if ( Hour < T.Hour ) return true;
		if ( Hour > T.Hour ) return false;
		if ( Min < T.Min ) return true;
		if ( Min > T.Min ) return false;
		return Sec < T.Sec;
	}

	Date_Time::Date_Time(int id) : Ident(id), Date(id), Time(id),
		pnext(NULL)
	{
	}

	Date_Time& Date_Time::operator+=(const int& add)
	{
		if ( ident == 1 ) Date::operator +=(add);
		else
		{
			Time::operator +=(add);
			if ( ident != 2 && over() > 0 )
			{
				Date::operator +=(over());
				reset();
			}
		}
		return *this;
	}

	bool Date_Time::operator<(const Date_Time& DT) const
	{
		if ( ident < DT.ident ) return true;
		if ( ident > DT.ident ) return false;
		const Date& D = (const Date&)DT;
		const Time& T = (const Time&)DT;
		switch( ident )
		{
		case 1 :
			return Date::operator<(D);
		case 2 :
			return Time::operator<(T);
		default :
			if ( Date::operator<(D) ) return true;
			if ( Date::operator==(D) ) return Time::operator<(T);
			return false;
		}
	}

	void Date_Time::write() const
	{
		switch( ident )
		{
		case 1 : cout << Date::descr; break;
		case 2 : cout << Time::descr; break;
		default: 
			cout << Date::descr << ' ' << Time::descr;
		}
		cout << '\n';
	}

	Error::Error(int n)
	{
		if ( n == -1000000000 )
		{
			cin.clear();
			cin.ignore(1000,'\n');
			sprintf(msg,"Errore di input\n");
		}
		else sprintf(msg,"Errore: il dato %d non e' valido\n",n);
	}
}