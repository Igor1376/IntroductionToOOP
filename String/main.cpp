#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class String
{
	int size; // размер строки в байтах
	char* str; // адрес строки в динамической памяти
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
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor: \t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size]{};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor: \t\t" << this << endl;

	}
	String(const String& other)
	{
		//Deep copy
		this->size = other.size;
		this-> str = new char [size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
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
	String buffer = left.get_size() + right.get_size() - 1; // from int to string
	for (int i = 0; i < left.get_size(); i++)	
		buffer.get_str()[i] = left.get_str()[i];
	for(int i = 0; i < right.get_size(); i++)
		buffer.get_str()[i + left.get_size() -1] = right.get_str()[i];
	buffer.print();
	return buffer;
}

void main()
{
	setlocale(LC_ALL, "");
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
}