#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class String
{
	int size; // размер строки в байтах
	char* str; // адрес строки в динамической пам€ти
public:
	int get_size()const
	{
		return size;
	}
	// constructor

	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	explicit String(int size = 80) :size(size), str(new char [size] {})
	{
		//this->size = size;
		//this->str = new char[size] {};
		cout << "DefaultConstructor: \t" << this << endl;
	}
	String(const char str[]):String(strlen(str)+1)
	{
		//this->size = strlen(str) + 1;
	//	this->str = new char[size]{};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor: \t\t" << this << endl;

	}
	String(const String& other) : String(other.str)
	{
		//Deep copy
		//this->size = other.size;
		//this-> str = new char [size] {};
		//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}
	// Methods
	String& operator = (const String& other)
	{
		/*int a = 2;
		int b = 3;
		a = b;*/
		if (this == &other)return *this;
		delete[] str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	void print() const
	{
		
		cout << "Obj:\t"  << this  <<  "\t";
		cout << "Size:\t" << size <<  "\t";
		cout << "Addr:\t" << &str <<  "\t";
		cout << "Str:\t"  << str   <<  "\n";
	}
};
std::ostream& operator << (std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String buffer (left.get_size() + right.get_size() - 1); // from int to string
	for (int i = 0; i < left.get_size(); i++)	
		buffer.get_str()[i] = left.get_str()[i];
	for(int i = 0; i < right.get_size(); i++)
		buffer.get_str()[i + left.get_size() -1] = right.get_str()[i];
	buffer.print();
	return buffer;
}

#define CONSTRUCTORS_CHECK
//#define CAT_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str1;
	str1.print();

	String str2(8);
	str2.print();

	String str3 = "Hello";
	str3.print();

	//String str4(); //здесь не вызываетс€ конструктор и не создаетс€ объект, создаетс€ объект,в этом выражении объ€вл€етс€ функци€ str4(), 
	//котора€ ничего не принимает и возвращает объект класса 'String'.
	//str4.print();

	String str5{}; // явный вызов конструктора по умолчанию
	str5.print();

	String str6{ str3 };//copy constructor
	str6.print();

#endif 

#ifdef CAT_CHECK
	//String str;
//str.print();
	String str1 = "Hello";
	String str2 = "World";
	str1 = str1;

	cout << str1 << endl;
	cout << str2 << endl;

	String str3 = str1 + str2; // copy constr
	str3 = str1 + " " + str2;
	//str3.print();
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
#endif // CAT_CHECK

}