// CodingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int a = 20;
	char str[] = "test";

	unsigned long addr = 0;

	addr = unsigned long(&a);
	cout << &a << '\n';
	cout << hex << addr << '\n';
	int *pa = (int *)addr;
	cout << *pa << '\n';
	cout << '\n';

	

	addr = unsigned long(str);
	cout << &str << '\n';
	cout << hex << addr << '\n';
	cout << '\n';

	char *pstr = (char *)addr;
	cout << pstr << '\n';

    return 0;
}

