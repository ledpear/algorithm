// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int nLast = -1;
	int a;
	int b;
	cin >> a >> b;

	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < a; j++)
		{
			cout << '*';
		}
		cout << endl;
	}

    return 0;
}

