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
#include <set>
#include <unordered_map>
#include <functional>

using namespace std;
typedef unsigned long long ull;
typedef pair<ull, ull> p;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nTestSize;
	cin >> nTestSize;

	for (int nTest = 0; nTest < nTestSize; nTest++)
	{
		int nSize;
		cin >> nSize;
		vector<int> vArr(nSize);

		unordered_map<int, pair<int, int>> dict;	//pos, size

		for (int i = 0; i < nSize; i++)
		{
			cin >> vArr[i];
			if(dict.find(vArr[i]) == dict.end())
			{
				dict.insert(make_pair(vArr[i], make_pair(i, 1)));
			}
			else
			{
				++dict[vArr[i]].second;
			}
		}

		unordered_map<int, pair<int, int>>::iterator iter;
		for (iter = dict.begin(); iter != dict.end(); iter++) 
		{
			if (iter->second.second == 1)
			{
				cout << iter->second.first + 1 << '\n';
			}
		}
	}

	system("pause");

	return 0;
}