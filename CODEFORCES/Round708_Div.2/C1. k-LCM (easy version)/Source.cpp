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

//define
#define DEF_MIN -2147483648
#define DEF_MAX 2147483647

int GCD(int a, int b) {
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int LCM(int a, int b) {
	return a * b / GCD(a, b);
}

void BT(vector<int>& vArr, int nSize, int nCount, int k, int& nMin, vector<int>& vMinArr, map<p, int> &vDP)
{
	if (nCount + 1 == k)
	{
		vArr.push_back(nSize);

		int nLCM = vArr[0];
		for (int i = 1; i < vArr.size(); i++)
		{
			if (nLCM > vArr[i])
			{
				auto iter = vDP.find(p(vArr[i], nLCM));
				if (iter != vDP.end())
				{
					nLCM = iter->second;
				}
				else
				{
					vDP.insert(make_pair(p(vArr[i], nLCM), LCM(vArr[i], nLCM)));
					nLCM = vDP[p(vArr[i], nLCM)];
				}
			}
			else
			{
				auto iter = vDP.find(p(nLCM, vArr[i]));
				if (iter != vDP.end())
				{
					nLCM = iter->second;
				}
				else
				{
					vDP.insert(make_pair(p(nLCM, vArr[i]), LCM(nLCM, vArr[i])));
					nLCM = vDP[p(nLCM, vArr[i])];
				}
			}
			
		}

		if (nMin > nLCM)
		{
			nMin = nLCM;
			vMinArr = vArr;
		}
		vArr.pop_back();
		return;
	}

	for (int i = nSize - (k - nCount - 1); i >= 1; i--)
	{
		vArr.push_back(i);
		BT(vArr, nSize - i, nCount + 1, k, nMin, vMinArr, vDP);
		vArr.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nTestSize;
	cin >> nTestSize;

	for (int nTest = 0; nTest < nTestSize; nTest++)
	{
		int nSize, k, nMin = DEF_MAX;
		cin >> nSize >> k;
		vector<int> vArr, vMin;
		map<p, int> pMap;

		BT(vArr, nSize, 0, k, nMin, vMin, pMap);

		for (int i = 0; i < vMin.size(); i++)
			cout << vMin[i] << ' ';
		cout << '\n';
	}

	system("pause");

	return 0;
}