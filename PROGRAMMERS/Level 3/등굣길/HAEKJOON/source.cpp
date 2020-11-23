#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

void Maping(int dmap[100][100], int x, int y, int MaxX, int MaxY)
{
	dmap[0][0] = 0;
	if (x != 0)
	{
		if (dmap[y][x - 1] != 1000)
		{
			if (dmap[y][x - 1] == 0 || dmap[y][x - 1] > dmap[y][x] + 1)
			{
				dmap[y][x - 1] = dmap[y][x] + 1;
				Maping(dmap, x - 1, y, MaxX, MaxY);
			}
		}
	}

	if (y != 0)
	{
		if (dmap[y - 1][x] != 1000)
		{
			if (dmap[y - 1][x] == 0 || dmap[y - 1][x] > dmap[y][x] + 1)
			{
				dmap[y - 1][x] = dmap[y][x] + 1;
				Maping(dmap, x, y - 1, MaxX, MaxY);
			}
		}
	}

	if (x < MaxX - 1)
	{
		if (dmap[y][x + 1] != 1000)
		{
			if (dmap[y][x + 1] == 0 || dmap[y][x + 1] > dmap[y][x] + 1)
			{
				dmap[y][x + 1] = dmap[y][x] + 1;
				Maping(dmap, x + 1, y, MaxX, MaxY);
			}
		}
	}

	if (y < MaxY - 1)
	{
		if (dmap[y + 1][x] != 1000)
		{
			if (dmap[y + 1][x] == 0 || dmap[y + 1][x] > dmap[y][x] + 1)
			{
				dmap[y + 1][x] = dmap[y][x] + 1;
				Maping(dmap, x, y + 1, MaxX, MaxY);
			}
		}
	}
}

void SearchMap(int dmap[100][100], int x, int y, int MaxX, int MaxY, int&score)
{
	if (x == 0 && y == 0)
		return;
	else if (x == 0 || y == 0)
	{
		if (x == 0)
		{
			SearchMap(dmap, x, y - 1, MaxX, MaxY, score);
		}
		else if (y == 0)
		{
			SearchMap(dmap, x - 1, y, MaxX, MaxY, score);
		}
	}
	else
	{
		if (dmap[y][x - 1] == dmap[y - 1][x])
		{
			score++;
			SearchMap(dmap, x - 1, y, MaxX, MaxY, score);
			SearchMap(dmap, x, y - 1, MaxX, MaxY, score);
		}
		else if (dmap[y][x - 1] < dmap[y - 1][x])
		{
			SearchMap(dmap, x - 1, y, MaxX, MaxY, score);
		}
		else if (dmap[y][x - 1] > dmap[y - 1][x])
		{
			SearchMap(dmap, x, y - 1, MaxX, MaxY, score);
		}
	}
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

	int dmap[100][100] = { 0, };

	for (int i = 0; i < puddles.size(); i++)
	{
		dmap[puddles[i][1] - 1][puddles[i][0] - 1] = 1000;
	}

	//¸ÊÇÎ
	dmap[0][0] = -1;

	Maping(dmap, 0, 0, m, n);
	int nScore = 1;

	SearchMap(dmap, m - 1, n - 1, m, n, nScore);
	
	system("pause");

	return answer;
}