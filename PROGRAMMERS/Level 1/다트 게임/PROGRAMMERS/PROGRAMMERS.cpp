// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int ScoreParsing(string strScore)
{
	int nScore = 0;

	if (strScore.size() == 2)
	{
		nScore = strScore[0] - '0';

		if (strScore[1] == 'S')
		{
			return nScore;
		}
		else if (strScore[1] == 'D')
		{
			return nScore * nScore;
		}
		else if (strScore[1] == 'T')
		{
			return nScore * nScore * nScore;
		}
	}
	if (strScore.size() == 3)
	{
		nScore = 10;

		if (strScore[2] == 'S')
		{
			return nScore;
		}
		else if (strScore[2] == 'D')
		{
			return nScore * nScore;
		}
		else if (strScore[2] == 'T')
		{
			return nScore * nScore * nScore;
		}
	}
}

int main()
{
	int nLast = -1;
	string dartResult = "1S2D*3T";
	int answer = 0;

	string strTemp = "";
	vector<int> vScore;
	int pos = 0;
	while (true)
	{
		//可记贸府
		if (dartResult[pos] == '*')
		{
			if (vScore.size() < 2)
			{
				vScore[0] *= 2;
			}
			else
			{
				int vPos = vScore.size() - 1;
				vScore[vPos - 1] *= 2;
				vScore[vPos] *= 2;
			}
		}
		else if (dartResult[pos] == '#')
		{
			vScore[vScore.size() - 1] *= -1;
		}
		else
		{
			//痢荐 殿废
			if (dartResult[pos] == 'S' || dartResult[pos] == 'D' || dartResult[pos] == 'T')
			{
				strTemp += dartResult[pos];
				vScore.push_back(ScoreParsing(strTemp));
				strTemp = "";
			}
			else
			{
				strTemp += dartResult[pos];
			}
		}
		
		pos++;

		if (dartResult.size() == pos) break;
	}

	for (int i = 0; i < vScore.size(); i++)
	{
		answer += vScore[i];
	}

    return 0;
}

