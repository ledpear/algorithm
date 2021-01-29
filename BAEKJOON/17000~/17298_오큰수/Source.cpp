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

	stack<int> s;
	vector<int> vResult(nSize, -1);

	for (int i = 0; i < nSize; i++)
	{
		if (s.empty())
			s.push(i);
		else
		{
			while (!s.empty() && vArr[i] > vArr[s.top()])
			{
				vResult[s.top()] = vArr[i];
				s.pop();
			}
			s.push(i);
		}
	}

	for (int i = 0; i < nSize - 1; i++)
		cout << vResult[i] << ' ';
	cout << vResult[nSize - 1] << '\n';

	system("pause");

	return 0;
}