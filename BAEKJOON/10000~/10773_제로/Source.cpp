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
	int nCount;
	cin >> nCount;
	int nTemp;
	stack<int> s;
	for (int i = 0; i < nCount; i++)
	{
		cin >> nTemp;
		if (nTemp != 0)
			s.push(nTemp);
		else
		{
			if(!s.empty())
				s.pop();
		}
	}

	int nSum = 0;
	while (!s.empty())
	{
		nSum += s.top();
		s.pop();
	}
	cout << nSum << '\n';

	system("pause");

	return 0;
}