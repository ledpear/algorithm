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

void BT(vector<int>& vArr, int nSize, int nCount, int k, int& nMin, vector<int>& vMinArr)
{
	if (nCount + 1 == k)
	{
		int nLCM = 1;
		vArr.push_back(nSize);
		for (int i = 0; i < vArr.size(); i++)
		{
			nLCM = LCM(nLCM, vArr[i]);
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
		BT(vArr, nSize - i, nCount + 1, k, nMin, vMinArr);
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


		BT(vArr, nSize, 0, k, nMin, vMin);

		for (int i = 0; i < vMin.size(); i++)
			cout << vMin[i] << ' ';
		cout << '\n';
	}

	system("pause");

	return 0;
}