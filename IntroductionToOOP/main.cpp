//IntroductionTOOP
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n*******************************************\n"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		//x = -2; must be a modieble 
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	// Constructor
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	Point operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment: \t\t" << this << endl;
		return *this;
	}
	Point& operator++() //Prefix
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int) // Suffix
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}

	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		//other.x *= 100;
		//this ->x *= 100;
		return distance;
	}
	void print()const
	{
		cout << this << ":X = " << x << "\tY = " << y << endl;
	}
};
double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
	
}

Point operator+(const Point& left, const Point& right)
{ 
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

Point operator-(const Point& left, const Point& right)
{
	Point result
	(
		left.get_x() - right.get_x(),
		left.get_y() - right.get_y()
	);
	return result;
	
}
Point operator*(const Point& left, const Point& right)
{
	return Point
	(
		left.get_x() * right.get_x(),
		left.get_y() * right.get_y()
	);
}
bool operator==(const Point& left, const Point& right)
{
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
	return true;
	else return false;*/
}


//#define STRUCT_POINT
//#define DISTANCE_CHEK
//#define CONSTRUCTOR_CHEK
//#define ASSIGNMENT_CHEK
//#define ARITHMETICAL_OPERATORS_CHEK


void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	cout << "Hello OPP" << endl;
	int a; // объявление переменной 'а' типа 'int'
	Point A; // Объявление перменной 'А' типа 'Point'
	// Создание объекта А структуры 'Point'
	// Создание экземпляра А структуры 'Pont'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	Point* pA = &A; // Pointer to 'A'
	cout << pA->x << "\t" << pA->y << endl;
	cout << sizeof(A) << endl;
	cout << sizeof(Point) << endl;
#endif	// STRUCT_POINT

#ifdef DISTANCE_CHEK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'A' до точки 'B': " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'B' до точки 'A': " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'А' и 'В' : " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'B' и 'A' : " << distance(A, B) << endl;
	cout << delimiter << endl;
#endif 
#ifdef CONSTRUCTOR_CHEK	
	Point A;
	A.print();

	Point B = 5;
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C;
	D.print();
#endif
#ifdef ASSIGNMENT_CHEK


	//Point A(2, 3);//constructor
	//Point B; //default constructor
	//B = A; //Copy assignment
	//B.print();

	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();

#endif // ASSIGNMENT_CHEK
#ifdef ARITHMETICAL_OPERATORS_CHEK


	int a = 2;
	int b = 3;
	int c = a - b;
	
	Point A (2, 3);
	Point B (7, 8);
	A.print();
	B.print();

	Point C;
	C = A * B;
	C.print();

	C++;
	C.print();
#endif // ARITHMETICAL_OPERATORS_CHEK

	//cout << (2 == 3) << endl;
	cout << (Point (2, 3) == Point (3, 3)) << endl;

}