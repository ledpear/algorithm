// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int n = 4;
	string answer = "";
	for (int i = 0; i < n; i++)
	{
		if(i % 2 == 0)
			answer += "¼ö";
		else
			answer += "¹Ú";
	}

    return 0;
}

