// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdarg.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int nLast = -1;
	vector<string> seoul;
	string answer = "";
	int pos = 0;
	while (true)
	{
		if (seoul[pos] == "Kim")
			break;
		pos++;
	}
	answer += "�輭���� ";
	answer += to_string(pos);
	answer += "�� �ִ�";

    return 0;
}

