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
	// constructor
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor: \t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}
	// Methods
	void print() const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//String str;
	//str.print();
	String str1 = "Hello";
	String str2 = "World";

	cout << str1 << endl;
	cout << str2 << endl;

	String str3 = str1 + str2;
	cout << str3 << endl;
}