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
#include <functional>

using namespace std;
typedef unsigned long long ull;
typedef pair<ull, ull> p;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int nSize, nTemp;
	cin >> nSize;
	//priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> vArr;
// 	cin >> nTemp;
// 	vArr.push_back(nTemp);
	for (int i = 0; i < nSize; i++)
	{
		cin >> nTemp;

		auto iter = upper_bound(vArr.begin(), vArr.end(), nTemp);
		vArr.insert(iter, nTemp);


		cout << vArr[(vArr.size() - 1) / 2] << '\n';
	}
	system("pause");
	return 0;
}