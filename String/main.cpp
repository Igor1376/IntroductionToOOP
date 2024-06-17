#include<iostream>
#include"String.h"

//#define CONSTRUCTORS_CHECK
#define CAT_CHECK

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