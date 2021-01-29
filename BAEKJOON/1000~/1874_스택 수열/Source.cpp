#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int nSize;
	cin >> nSize;
	vector<int> vArr(nSize);
	for (int i = 0; i < nSize; i++)
		cin >> vArr[i];

	int nPoint = 1;
	int nPosition = 0;
	stack<int> sStack;
	vector<char> vResult;
	while (nPoint <= nSize)
	{
		if (sStack.empty())
		{
			sStack.push(nPoint++);
			vResult.push_back('+');
		}
		else
		{
			if (sStack.top() == vArr[nPosition])
			{
				sStack.pop();
				nPosition++;
				vResult.push_back('-');
			}
			else
			{
				sStack.push(nPoint++);
				vResult.push_back('+');
			}
		}
	}

	while (!sStack.empty() && sStack.top() == vArr[nPosition])
	{
		sStack.pop();
		nPosition++;
		vResult.push_back('-');
	}

	if (sStack.empty())
	{
		for (int i = 0; i < vResult.size(); i++)
			cout << vResult[i] << '\n';
	}
	else
		cout << "NO\n";

	system("pause");

	return 0;
}