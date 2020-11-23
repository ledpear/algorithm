#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int target;
	vector<vector<int>> triangle;

	vector<int> vtemp;
	vtemp.push_back(7);
	triangle.push_back(vtemp);
	vtemp.clear();

	vtemp.push_back(3);
	vtemp.push_back(8);
	triangle.push_back(vtemp);
	vtemp.clear();

	vtemp.push_back(8);
	vtemp.push_back(1);
	vtemp.push_back(0);
	triangle.push_back(vtemp);
	vtemp.clear();

	vtemp.push_back(2);
	vtemp.push_back(7);
	vtemp.push_back(4);
	vtemp.push_back(4);
	triangle.push_back(vtemp);
	vtemp.clear();

	vtemp.push_back(4);
	vtemp.push_back(5);
	vtemp.push_back(2);
	vtemp.push_back(6);
	vtemp.push_back(5);
	triangle.push_back(vtemp);
	vtemp.clear();

	int answer = 0;
	int count = 0;
	string str = "";
	//TargetNumber(triangle, 0, 0, 0, answer, str, count);
	int d[501][501] = { {-1,} };
	d[0][0] = triangle[0][0];
	int nMax = 0;

	for (int i = 1; i < triangle.size(); i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				d[i][j] = d[i - 1][j] + triangle[i][j];
			}
			else if (j == i)
			{
				d[i][j] = d[i - 1][j - 1] + triangle[i][j];
			}
			else
			{
				d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + triangle[i][j];
			}
			if (i == triangle.size() - 1)
			{
				nMax = max(nMax, d[i][j]);
			}
		}
	}
	
	system("pause");
	return answer;
}