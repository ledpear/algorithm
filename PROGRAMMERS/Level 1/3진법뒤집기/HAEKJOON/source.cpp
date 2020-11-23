#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int main()
{
	int nScore = 0;

	int n = 125;

	stack<int> nStack;
	vector<int> nVector;

	while (true)
	{
		nStack.push(n % 3);
		n = n / 3;
		if (n < 3)
		{
			nStack.push(n);
			break;
		}
	}

	int nTemp;
	while (true)
	{
		nTemp = nStack.top();
		nVector.push_back(nTemp);
		nStack.pop();
		
		if (nStack.empty())
			break;
	}

	int nSum = 0;
	int a = 1;
	for (int i = 0; i < nVector.size(); i++)
	{
		nSum += a * nVector[i];
		a *= 3;
	}

	system("pause");
	return nScore;
}