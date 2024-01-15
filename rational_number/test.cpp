#include<iostream>
#include<sstream>
#include"rational_number.h"

int main()
{
	using namespace std;
	rational_number z;
	z += rational_number(8);
	cout << z << endl;
	test_parse("{3/4}");
	test_parse("{3,4}");
	cout << endl;
	rational_number x(20, 15);
	cout << x << endl;
	cout << x + z << endl;

	cout << endl;
	rational_number rnum(3.4);
	cout << rnum << endl;
	return(0);
}