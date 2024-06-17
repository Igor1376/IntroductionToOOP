#pragma once
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
	int get_size()const;
	// constructor

	const char* get_str()const;
	char* get_str();

	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	~String();
	// Methods
	String& operator = (const String& other);
	void print() const;
};
std::ostream& operator << (std::ostream& os, const String& obj);
String operator+(const String& left, const String& right);
