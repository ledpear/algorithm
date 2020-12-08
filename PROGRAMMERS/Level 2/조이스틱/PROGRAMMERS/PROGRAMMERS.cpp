// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int nLast = -1;
	string name ="ASDFAIEDSFAJ";
	int answer = 0;

	string temp = "";
	int nSize = name.size();

	for (int i = 0; i < name.size(); i++)
		temp += 'A';
	int pos = 0;
	while (true)
	{
		if (name == temp)	break;

		if (temp[pos] == name[pos])
		{
			int nMove = 1;
			int nLeft, nRight;

			while (true)
			{
				nLeft = pos - nMove;
				nRight = pos + nMove;
				if (nLeft < 0)		nLeft = nSize + nLeft;
				if ((nSize - 1) < nRight)	nRight = nRight - nSize;

				if (temp[nRight] != name[nRight])
				{
					pos = nRight;
					answer += nMove;
					break;
				}
				else if (temp[nLeft] != name[nLeft])
				{
					pos = nLeft;
					answer += nMove;
					break;
				}
				else
					nMove++;
			}
		}
		else
		{
			int up = name[pos] - temp[pos];
			int down = 26 - up;

			if (up <= down)
				answer += up;
			else
				answer += down;

			temp[pos] = name[pos];
		}
	}

    return 0;
}

