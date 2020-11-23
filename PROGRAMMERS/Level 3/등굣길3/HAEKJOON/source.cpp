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
int dmap[101][101] = { {0,}, };

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

	bool bmap[101][101] = { 0, };

	for (int i = 0; i < puddles.size(); i++)
	{
		bmap[puddles[i][1]][puddles[i][0]] = true;
	}

	//¸ÊÇÎ
	dmap[1][0] = 1;

	//Maping(1, 1, m, n, 0, bmap);

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			if (bmap[y][x])
				dmap[y][x] = 0;
			else
				dmap[y][x] = (dmap[y - 1][x] + dmap[y][x - 1]) % 1000000007;;
		}
	}

	return dmap[n][m];
}