// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	string s;

	int nP = 0;




	int nY = 0;






	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'p' || s[i] == 'P')
			nP++;
		if (s[i] == 'y' || s[i] == 'Y')
			nY++;



	}




    return nP == nY;
}

