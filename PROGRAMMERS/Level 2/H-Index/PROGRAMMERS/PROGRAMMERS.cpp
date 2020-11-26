// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> citations;
// 	citations.push_back(3);
// 	citations.push_back(0);
// 	citations.push_back(6);
// 	citations.push_back(1);
	citations.push_back(1);
/*	citations.push_back(5);*/

	sort(citations.begin(), citations.end());

	int answer = 0;
	int pos = 0;
	int undo = -1;
	int undoPos = 0;
	bool UndoReset = true;
	int Max = 0;

	if (citations.size() == 1 && citations[0] == 1)
		return 1;

	for (int i = 0; i < citations.size(); i++)
	{
		if (i < citations[i] && citations[i] <= citations.size() - i)
		{
			pos = i;
			if (undo != citations[i])
			{
				undo = Max;
				Max = citations[i];
				
				UndoReset = true;
			}
			else
				UndoReset = false;
		}
	}

	if (UndoReset)
		answer = Max;
	else
		answer = undo;

	system("pause");
	return answer;
}

