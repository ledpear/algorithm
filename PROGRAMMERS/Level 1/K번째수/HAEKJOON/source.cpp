#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>

using namespace std;

int main()
{
	vector<int> array;
	vector<vector<int>> commands;
	vector<int> answer;

	array.push_back(1);
	array.push_back(5);
	array.push_back(2);
	array.push_back(6);
	array.push_back(3);
	array.push_back(7);
	array.push_back(4);

	vector<int> temp;
	temp.push_back(2);
	temp.push_back(5);
	temp.push_back(3);
	commands.push_back(temp);
	temp.clear();

	temp.push_back(4);
	temp.push_back(4);
	temp.push_back(1);
	commands.push_back(temp);
	temp.clear();

	temp.push_back(1);
	temp.push_back(7);
	temp.push_back(3);
	commands.push_back(temp);
	temp.clear();

	vector<int> vSort;
	for (int i = 0; i < commands.size(); i++)
	{
		for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
		{
			vSort.push_back(array[j]);
		}

		sort(vSort.begin(), vSort.end());
		answer.push_back(vSort[commands[i][3] - 1]);
		vSort.clear();
	}

	return 0;
}