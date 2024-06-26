#define USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter				"\n-------------------------------------------------\n"
#define double_delimiter		"\n=================================================\n"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
		
	}
	int get_numerator()const
	{
		return numerator;

	}
	int get_denominator()const
	{
		return denominator;

	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this -> denominator = denominator;
	}
	//Constructors
	Fraction()
	{
		integer = 0;
		numerator = 0;
		denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(double decimal)
	{
		decimal += 1e-10;
		integer = decimal; 
		decimal -= integer;
		denominator = 1e+9;
		numerator = decimal * denominator;
		reduce();
		cout << "Constructor: \t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;

	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}

	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//Operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return* this;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this*other;
			
	}

	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;

	}

	Fraction& operator++()
	{
		integer++;
		return *this;
	
	}
	Fraction& operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;

	}
	
	/*
	--------------------------------------------------------------------------
	operator type()
	{
	.........;
	.........;
	return value;
	}
	---------------------------------------------------------------------------
	*/
	explicit operator int()
	{
		return integer;
	}
	operator double()
	{
		return integer + (double)numerator / denominator;
	}

	//Methods:
	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator) more = numerator, less = denominator;
		else more = denominator, less = numerator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;

		} while (rest);
		int GCD = more; // GCD - Greatest Common Divesor
		numerator /= GCD;
		denominator /= GCD;
		return *this;

	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;

	}
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
			
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}
};
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();

}
Fraction operator / (const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}

bool operator == (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() == 
		right.get_numerator() * left.get_denominator();
}
bool operator !=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

bool operator >(Fraction left, Fraction right)
{
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator()* left.get_denominator();
}
bool operator <(Fraction left, Fraction right)
{
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}

bool operator <=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
	//return left < right || left == right;
}

bool operator >=(const Fraction& left, const Fraction& right)
{
	
	return !(left < right);
	//return left > right || left == right;
}
//stream -  �����
// std - standart namespace
// ostream - oitput stream (����� ������)
//:: - scope operator (�������� ���������� ��������� - ��������� ����� � ������������ ����)
// ��� �� ���� '::' ������� ��� � globalscope (���������� ������������ ����)
//namespace (������������) ��� ����� � ���, ������������ � ��� - ��� ����
std::ostream& operator << (std::ostream& os, const Fraction& obj)
//cout - console out
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		cout << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0) cout << 0;
	return os;
	
}
//istream = input stream (����� �����)
std::istream& operator >> (std::istream& is, Fraction& obj)
//cin - Console in
{
	const int SIZE = 32;
	char buffer[SIZE]{};
	//is >> buffer;
	is.getline(buffer, SIZE);
	int number[3];
	int n = 0;
	const char delimiters[] = "(/ ) +";
	for(char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		//������� strtok() ��������� ������ �� ������
		//
		number[n++] = atoi(pch);
	//������� atoi() - ASCII string to int ��������� ������ � ���������� �������� ���� int ��������� � ���� ������
	//pch - Pointer to Character (��������� �� ������)
		//for (int i = 0; i < n; i++)cout << number[i] << "\t"; cout << endl;
	switch(n)
	{
		case 1: obj = Fraction(number[0]); break;
		case 2: obj = Fraction(number[0], number[1]); break;
		case 3: obj = Fraction(number[0], number[1], number[2]); break;
		
	}
	return is;
}
//#define CONSTRUCTOR_CHECK
//#define ARITHMETICALS_OPERATORS_CHEK
//#define COMPARISON_OPERATORS_CHEK
//#define STREAMS_CHECK
//#define TYPE_COVERTIONS_BASICS
//#define CONVERTIONS_FROM_OTHER_TO_CLASS
#define CONVERTIONS_FROM_CLASS_TO_OTHER
//#define CONVERTIONS_TASK_1
#define CONVERTIONS_TASK_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHEK
	Fraction A; // Default constructor
	A.print();
	Fraction B = 5; // Single-argument constructor
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
	Fraction E = D;
	E.print();
	Fraction F;
	F = E;
	F.print();
#endif 
#ifdef ARITHMETICALS_OPERATORS_CHEK
	Fraction A(2, 3, 4);
	A.to_improper();
	A.print();

	A.to_proper();
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	/*Fraction C = A / B;
	C.print();
	(++C).print();
	C.print();

	A.print();
	B.print();*/

	A *= B;
	A.print();

	A /= B;
	A.print();
#endif //ARITHMETICALS_OPERATORS_CHEK
#ifdef COMPARISON_OPERATORS_CHEK
	//cout << (2 == 3) << endl;
	cout << (Fraction(1, 2) >= Fraction(5, 10)) << endl;
#endif COMPARISON_OPERATORS_CHEK

#ifdef STREAMS_CHECK
	Fraction A(2, 3, 4);
	cout << "������� ���������� ������� �����: "; cin >> A;
	cout << A << endl;
#endif // STREAMS_CHECK
#ifdef TYPE_COVERTIONS_BASICS
	int a = 2; //No conversions
	double  b = 3; //Conversions from less to more
	int c = b; // Conversions from more to less without data loss
	int d = 2.5; // Conversions from more to less with data loss
	cout << sizeof(int) << endl;
	cout << sizeof(double) << endl;
#endif TYPE_COVERTIONS_BASICS

#ifdef CONVERTIONS_FROM_OTHER_TO_CLASS


	Fraction A = (Fraction)5;
	cout << A << endl;
	
	cout << double_delimiter << endl;

	Fraction B; //default constructer
	cout << delimiter << endl;
	B = Fraction(8); //CopyAssignment
	cout << delimiter << endl;
	cout << B << endl;

	cout << double_delimiter << endl;
#endif // CONVERTIONS_FROM_OTHER_TO_CLASS
#ifdef CONVERTIONS_TASK_1

	Fraction A(2, 3, 4);
	cout << A << endl;
	double a = A;
	cout << a << endl;

#endif // CONVERTIONS_TASK_1
#ifdef CONVERTIONS_TASK_2

	Fraction B = 2.58;
	cout << B << endl;


#endif // CONVERTIONS_TASK_2


}