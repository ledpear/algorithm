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
	stack<int> sInput;
	int nTemp;
	for (int i = 0; i < nSize; i++)
	{
		cin >> nTemp;
		sInput.push(nTemp);
	}

	stack<int> sCompare;
	stack<int> sOutput;
	while (!sInput.empty())
	{
		if (sCompare.empty())
		{
			sOutput.push(-1);
			sCompare.push(sInput.top());
			sInput.pop();
		}
		else
		{
			if (sInput.top() > sCompare.top())
				sCompare.pop();
			else
			{
				sOutput.push(sCompare.top());
				sCompare.push(sInput.top());
				sInput.pop();
			}
		}
	}

	while (sOutput.size() > 1)
	{
		cout << sOutput.top() << ' ';
		sOutput.pop();
	}
	cout << sOutput.top() << '\n';

	system("pause");

	return 0;
}