#include "ShapeInterf.h"

namespace mini_graphics
{
	struct Screen_Error
	{
		enum errind {INV_SIZ,INV_SCR,NOB_CRE,ALR_CRE};
		Screen_Error(errind); 
		char msg[60];
	};

	class ASC_Screen
	{
		static int objcount;
		static char bigpix;
		static char bkgnd;
		static char* pixel;
		static int nSx;
		static int nSy;
		static Point Sh_blc;
		static Point Sh_trc;
		static Point Sc_coe;
		static Point Sc_off;
		static void set_conversion();
		static Point ToScreen(const Point&);
		static void draw_Screen_Line(const Point&, const Point&);
		static void draw_Screen_Dot(const Point&);
		static void draw_Screen_Ellipse(const Point&, double&, double&);
	protected:
		ASC_Screen();
		static void draw_Line(const Point&, const Point&);
		static void draw_Polygon(int, const Point*);
		static void draw_Dot(const Point&);
		static void draw_Square(const Point&, const double&);
		static void draw_Circle(const Point&, const double&);
	public:
		~ASC_Screen();
		static void set_Screen_size(const int&, const int&); 
		static void set_Screen_corners(const Point&, const Point&);
		static void get_Screen_corners(Point&, Point&);
		static void clear();
		static void move_center(const Point&);
		static void zoom(const bool& =true);
		static void OnScreen();
		virtual void draw() = 0;
	};

	class ASC_Dot : public ASC_Screen, public Dot
	{
	public:
		void draw();
	};

	class ASC_Line : public ASC_Screen, public Line
	{
	public:
		void draw();
	};

	class ASC_Triangle : public ASC_Screen, public Triangle
	{
	public:
		void draw();
	};

	class ASC_Rect : public ASC_Screen, public Rect
	{
	public:
		void draw();
	};

	class ASC_Square : public ASC_Screen, public Square
	{
	public:
		void draw();
	};

	class ASC_Circle : public ASC_Screen, public Circle
	{
	public:
		void draw();
	};
}
