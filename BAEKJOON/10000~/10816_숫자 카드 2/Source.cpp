#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nSize, nTest;
	map<int, int> mArr;

	cin >> nSize;
	
	int nTemp, nFind;

	for (int i = 0; i < nSize; i++)
	{
		cin >> nTemp;
		auto iter = mArr.find(nTemp);
		if (iter != mArr.end())
			iter->second++;
		else
			mArr.insert({ nTemp, 1 });
	}

	cin >> nTest;

	for (int i = 0; i < nTest; i++)
	{
		cin >> nTemp;

		auto iter = mArr.find(nTemp);
		if (iter != mArr.end())
			cout << iter->second;
		else
			cout << '0';
		cout << ' ';
	}

	system("pause");

	return 0;
}