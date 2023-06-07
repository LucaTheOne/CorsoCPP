namespace mini_graphics
{
	struct Point
	{
		double x;
		double y;
		Point() { }
		Point(double x0, double y0) : x(x0), y(y0) { }
	};

	struct Shape_Error
	{
		enum errind {INV_FNC,BAD_IND,INV_CPY,IMP_LIN,IMP_TRI,
			IMP_REC,IMP_SQR,IMP_CIR,INP_ERR};
		Shape_Error(errind,int); 
		char msg[50];
	};

	ostream& operator<<(ostream&, const Point&);
	istream& operator>>(istream&, Point&);
	void INVF();

	class Shape
	{
	public:
		virtual void set(const Point*) = 0;
		virtual void set(const Point&) = 0;
		virtual void set(const Point&, const Point&) = 0;
		virtual void set(const Point&, const Point&, const Point&) = 0;
		virtual int get_nump() const = 0;
		virtual Point get_corner(int) const = 0;
		virtual void set(const Point&, const double&) = 0;
		virtual Point get_center() const = 0;
		virtual double get_side() const = 0;
		virtual void display(bool=false) = 0;
		virtual void copy_from(const Shape*) = 0;
		virtual ~Shape() { }
	};

	class Polygon : virtual public Shape
	{
	protected:
		int nump;
		Point* pp;
		Polygon(const int&);
	public:
		int get_nump() const { return nump; }
		void set(const Point*);
		Point get_corner(int) const;
		void display(bool=false);
		void copy_from(const Shape*);
		~Polygon();
		void set(const Point&) { INVF(); }
		void set(const Point&, const Point&) { INVF(); }
		void set(const Point&, const Point&, const Point&) { INVF(); }
		void set(const Point&, const double&) { INVF(); }
		Point get_center() const{ INVF(); return Point(0.,0.); }
		double get_side() const {  INVF(); return 0; }
	};

	class Dot : public Polygon
	{
	public:
		using Polygon::set;
		Dot();
		void set(const Point&);
		void display(bool=false);
	};

	class Line : public Polygon
	{
	public:
		using Polygon::set;
		Line();
		void set(const Point&, const Point&);
		void display(bool=false);
	};

	class Triangle : public Polygon
	{
	public:
		using Polygon::set;
		Triangle();
		void set(const Point&, const Point&, const Point&);
		void display(bool=false);
	};

	class Rect : public Polygon
	{
	public:
		using Polygon::set;
		Rect();
		void set(const Point&, const Point&);
		void display(bool=false);
	};

	class Regular : virtual public Shape
	{
	protected:
		double side;
		Point center;
	public:
		Point get_center() const { return center; }
		double get_side() const { return side; }
		void copy_from(const Shape*);
		int get_nump() const { INVF(); return 0; }
		void set(const Point*)  { INVF(); }
		Point get_corner(int) const { INVF(); return Point(0.,0.);}
		void set(const Point&)  { INVF(); }
		void set(const Point&, const Point&) { INVF(); }
		void set(const Point&, const Point&, const Point&) { INVF(); }
	};

	class Square : public Polygon, public Regular
	{
	public:
		Square();
		void copy_from(const Shape*);
		void set(const Point&, const double&); 
		void display(bool=false);
		Point get_center() const { return Regular::get_center(); }
		double get_side() const { return Regular::get_side(); }
		int get_nump() const { return Polygon::get_nump(); }
		void set(const Point* pd) { Polygon::set(pd); }
		Point get_corner(int i) const { return Polygon::get_corner(i); }
		void set(const Point&) { INVF(); }
		void set(const Point&, const Point&) { INVF(); }
		void set(const Point&, const Point&, const Point&) { INVF(); }
	};

	class Circle : public Regular
	{
	public:
		Circle();
		void set(const Point&, const double&);
		void display(bool=false);
	};
}

