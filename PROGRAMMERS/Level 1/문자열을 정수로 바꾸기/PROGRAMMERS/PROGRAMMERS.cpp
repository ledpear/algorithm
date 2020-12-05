// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int nLast = -1;
	string s;
	int answer = 0;


	string temp;
	if (s[0] == '-')
	{
		temp = s.substr(1);
		answer = stoi(temp);
		answer = -answer;
	}
	else if(s[0] == '+')
	{
		temp = s.substr(1);
		answer = stoi(temp);
	}
	else
	{
		answer = stoi(s);
	}

    return 0;
}

