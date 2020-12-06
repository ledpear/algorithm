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
	string number = "4177252841";
	int k = 9;

	int K = k;
	int pos = 0;
	int nMax = -1;
	int PosTemp = 0;
	int i = 0;
	int size = number.size();
	while (true)
	{
		if (K + pos == size)
		{
			//answer += number.substr(pos);
			break;
		}
		else if (K + pos >= size)
		{
			for (i = pos; i < size; i++)
			{
				if (nMax < (number.at(i) - '0'))
				{
					PosTemp = i;
					nMax = (number.at(i) - '0');
				}
			}
		}
		else
		{
			for (i = pos; i <= K + pos; i++)
			{
				if (nMax < (number.at(i) - '0'))
				{
					PosTemp = i;
					nMax = (number.at(i) - '0');
				}
			}
		}

		K = K - (PosTemp - pos);
		answer += number.at(PosTemp);
		pos = PosTemp + 1;
		PosTemp = -1;
		nMax = -1;

		if (pos == size) break;
		if (K == 0)
		{
			if(pos != number.size())
				answer += number.substr(pos);
			break;
		}
	}

    return 0;
}

