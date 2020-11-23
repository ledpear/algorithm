#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int nScoreMin = UINT16_MAX;
int nTotalScore = 0;
int dmap[100][100] = { {0,}, };

int min(int a, int b)
{
	return a < b ? a : b;
}

void Maping(int x, int y, int MaxX, int MaxY, int score, bool bmap[100][100])
{
	if (x < 0 || x >= MaxX || y < 0 || y >= MaxY)
		return;
	if (dmap[y][x] == UINT16_MAX)
		return;
	//if (bmap[y][x] == true)	return;

	if (x == MaxX - 1 && y == MaxY - 1)
	{
		if (nScoreMin > score)
		{
			nScoreMin = score;
			nTotalScore = 0;
			return;
		}
		else if (nScoreMin == score)
		{
			nTotalScore++;
			return;
		}
		else
			return;
	}

	//bmap[y][x] = true;
	if (dmap[y][x] == 0)	dmap[y][x] = score + 1;
	else
	{
		if (dmap[y][x] < score + 1)
			return;
		else
			dmap[y][x] = score + 1 ;
	}

	Maping(x + 1, y, MaxX, MaxY, score + 1, bmap);
	Maping(x, y + 1, MaxX, MaxY, score + 1, bmap);
// 	Maping(x - 1, y, MaxX, MaxY, score + 1, bmap);
// 	Maping(x, y - 1, MaxX, MaxY, score + 1, bmap);
}

int main()
{
	vector<int> vtemp;


	int m = 4;
	int n = 3;
	int answer = 0;
	vector<vector<int>> puddles;

	vtemp.push_back(2);
	vtemp.push_back(2);
	puddles.push_back(vtemp);

// 	vtemp.push_back(4);
// 	vtemp.push_back(1);
// 	puddles.push_back(vtemp);
// 	vtemp.clear();
// 	vtemp.push_back(2);
// 	vtemp.push_back(2);
// 	puddles.push_back(vtemp);
// 	vtemp.clear();
// 	vtemp.push_back(5);
// 	vtemp.push_back(3);
// 	puddles.push_back(vtemp);
// 	vtemp.clear();
// 	vtemp.push_back(3);
// 	vtemp.push_back(4);
// 	puddles.push_back(vtemp);
// 	vtemp.clear();
// 	vtemp.push_back(4);
// 	vtemp.push_back(4);
// 	puddles.push_back(vtemp);
// 	vtemp.clear();
// 	vtemp.push_back(1);
// 	vtemp.push_back(5);
// 	puddles.push_back(vtemp);
// 	vtemp.clear();
// 	vtemp.push_back(6);
// 	vtemp.push_back(5);
// 	puddles.push_back(vtemp);
// 	vtemp.clear();
// 	vtemp.push_back(2);
// 	vtemp.push_back(7);
// 	puddles.push_back(vtemp);
// 	vtemp.clear();

// 	int **dmap;
// 
// 	dmap = new int *[n];
// 	for (int i = 0; i < n; i++)
// 	{
// 		dmap[i] = new int[m];
// 		memset(dmap[i], 200, sizeof(int) * m);
// 	}

	bool bmap[100][100] = { 0, };

	for (int i = 0; i < puddles.size(); i++)
	{
		dmap[puddles[i][1] - 1][puddles[i][0] - 1] = UINT16_MAX;
	}

	//¸ÊÇÎ
	dmap[0][0] = 0;

	Maping(0, 0, m, n, 0, bmap);
	
	system("pause");

	return nTotalScore + 1;
}