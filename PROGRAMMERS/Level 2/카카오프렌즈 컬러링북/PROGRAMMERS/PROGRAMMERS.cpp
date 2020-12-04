// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

void Search(vector<vector<int>> picture, vector<vector<bool>> &bFind, int x, int y, int m, int n, int &max_size_of_one_area, int nValue)
{
	if (x < 0 || y < 0 || x >= n || y >= m)
		return;

	if (picture[y][x] == nValue && bFind[y][x] == false)
	{
		max_size_of_one_area++;
		bFind[y][x] = true;
		Search(picture, bFind, x - 1, y, m, n, max_size_of_one_area, nValue);
		Search(picture, bFind, x, y - 1, m, n, max_size_of_one_area, nValue);
		Search(picture, bFind, x + 1, y, m, n, max_size_of_one_area, nValue);
		Search(picture, bFind, x, y + 1, m, n, max_size_of_one_area, nValue);
	}
}

int main()
{
	int nLast = -1;
	int m, n;
	vector<vector<int>> picture;
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	m = 6;
	n = 4;

	vector<int> temp;
	
	temp = { 1, 1, 1, 0 };
	picture.push_back(temp);
	temp = { 1, 2, 2, 0 };
	picture.push_back(temp);
	temp = { 1, 0, 0, 1 };
	picture.push_back(temp);
	temp = { 0, 0, 0, 1 };
	picture.push_back(temp);
	temp = { 0, 0, 0, 3 };
	picture.push_back(temp);
	temp = { 0, 0, 0, 3 };
	picture.push_back(temp);

// 	bool **bFind = new bool *[m];
// 	for (int i = 0; i < m; i++)
// 	{
// 		bFind[i] = vector <
// 	}

	int nMax = -1;
	vector<vector<bool>> bFind(m, vector<bool>(n));
	

	for (int y = 0; y < m; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (bFind[y][x] == false && picture[y][x] != 0)
			{
				max_size_of_one_area = 0;
				number_of_area++;

				Search(picture, bFind, x, y, m, n, max_size_of_one_area, picture[y][x]);

				if (nMax < max_size_of_one_area)	nMax = max_size_of_one_area;
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = nMax;

    return 0;
}

