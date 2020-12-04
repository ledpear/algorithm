// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

void SetData(vector<int> &answer, int x, int y, int value, vector<int> RowPosition)
{
	answer[RowPosition[x] + y] = value;
}

int main()
{
	int nLast = -1;
	int n = 6;

	int nSize = 0;
	vector<int> RowPosition(n);
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			RowPosition[i] = 0;
		else
			RowPosition[i] = RowPosition[i - 1] + i;

		nSize = nSize + (i + 1);
	}
	vector<int> answer(nSize);

	int nType = 0;
	int x = 0;
	int y = 0;
	for (int i = 1; i <= nSize; i++)
	{
		answer[RowPosition[y] + x] = i;

		switch (nType)
		{
		case 0:
			y++;
			if (y >= n || answer[RowPosition[y] + x] != 0)
			{
				--y;
				++x;
				nType = 1;
			}
			break;
		case 1:
			x++;
			if (x >= n || answer[RowPosition[y] + x] != 0)
			{
				x = x - 2;
				--y;
				nType = 2;
			}
			break;
		case 2:
			x--;
			y--;
			if (x < 0 || answer[RowPosition[y] + x] != 0 || y < 0)
			{
				y = y + 2;
				++x;
				nType = 0;
			}
			break;
		}
	}


    return 0;
}

