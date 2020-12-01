// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

void upper(string & answer, int pos)
{
	if (answer[pos] == '0')
	{
		if (pos < 0)
			return;

		if (pos - 1 == 0)
		{
			if (answer[pos - 1] == '2')
			{
				answer[pos - 1] = '1';
				answer[pos] = '4';
			}
			else if (answer[pos - 1] == '1')
			{
				answer[pos - 1] = '0';
				answer[pos] = '4';
			}
		}
		else
		{
			if (answer[pos - 1] == '4')
			{
				answer[pos - 1] = '2';
				answer[pos] = '4';
			}
			else if (answer[pos - 1] == '2')
			{
				answer[pos - 1] = '1';
				answer[pos] = '4';
			}
			else if (answer[pos - 1] == '1')
			{
				answer[pos - 1] = '0';
				upper(answer, pos - 1);
				answer[pos] = '4';
			}
		}
	}
}

int main()
{
	int nLast = -1;
	int n = 27;
	string answer = "";

	//n에서 1뺀 값을 3진수로 표현한 것
	//0 => 1
	//1 => 2
	//2 => 4

	string temp = "";

	string number012[3];
	number012[0] = "0";
	number012[1] = "1";
	number012[2] = "2";

	string number124[3];
	number124[0] = "1";
	number124[1] = "2";
	number124[2] = "4";

//	for (int i = 1; i <= 9000; i++)
	{
		temp = "";
		n = 12;

		while (true)
		{
			temp = number012[n % 3] + temp;
			n /= 3;
			if (n == 0)
				break;
		}

		for (int i = 1; i < temp.size(); ++i)
		{

			if (temp[i] == '0')
				upper(temp, i);
		}

		for (int i = 0; i < temp.size(); ++i)
		{
			if (temp[i] == '0')
				temp.erase(0, 1);
			else
				break;
		}

		//cout << i << " : " << temp << endl;
	}

	

    return 0;
}

