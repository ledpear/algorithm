// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

void MakeNumber(int pos, vector<bool> bDontUsePostion, int SetCount, int &Max, int size, string Original, string &answer)
{
	pos++;
	if (SetCount == size)
	{
		string temp = "";
		for (int i = 0; i < Original.size(); i++)
		{
			if (bDontUsePostion[i] != true)
				temp += Original[i];
		}

		if (temp > answer)
		{
			//Max = stoi(temp);
			answer = temp;
		}
	}
	else
	{
		for (int i = pos; i < Original.size() - (size - SetCount) + 1; i++)
		{
			vector<bool> bTemp = bDontUsePostion;
			bTemp[i] = true;
			MakeNumber(i, bTemp, SetCount + 1, Max, size, Original, answer);
		}
	}
}

int main()
{
	int nLast = -1;
	string answer = "";
	string number = "1924";
	int k = 2;

	int Max;
	Max = -1;
	int size = number.size() - k;

	for (int i = 0; i < k; i++)
	{
		answer += '0';
	}
	
	for (int i = 0; i < size + 1; i++)
	{
		vector<bool> bDontUsePostion(number.size());
		bDontUsePostion[i] = true;
		MakeNumber(i, bDontUsePostion, 1, Max, k, number, answer);
	}

    return 0;
}

