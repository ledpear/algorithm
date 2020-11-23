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
	vector<int> scoville;
	priority_queue<int, vector<int>, greater<int>> qList;
	int K = 0;
	scoville.push_back(1);
	scoville.push_back(2);
	scoville.push_back(3);
	scoville.push_back(9);
	scoville.push_back(10);
	scoville.push_back(12);

	for (int i = 0; i < scoville.size(); i++)
	{
		qList.push(scoville[i]);
	}

	int nSt, nSe;
	int nNew;
	int nCount = 0;
	while (1)
	{
		if (qList.top() >= K)
			break;

		nSt = qList.top();
		qList.pop();
		nSe = qList.top();
		qList.pop();
		nNew = nSt + nSe * 2;
		qList.push(nNew);
		nCount++;
	}
	
	system("pause");
	return 0;
}