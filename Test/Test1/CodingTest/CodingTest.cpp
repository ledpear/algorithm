// CodingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	auto test = [](int x, int y) {
		return x + y;
	};

	cout << test(10, 20) << endl;

	system("pause");


    return 0;
}

