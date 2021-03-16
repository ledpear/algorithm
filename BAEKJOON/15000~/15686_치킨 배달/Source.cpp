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

using namespace std;

//define
#define DEF_MIN -2147483648
#define DEF_MAX 2147483647

typedef unsigned long long ull;
typedef pair<int, int> p;
typedef vector<vector<int>> vmap;

//custum function
int ChickenDistance(const vector<p>& vHome, const vector<p>& vChichen)
{
	int nSum = 0;
	for (int i = 0; i < vHome.size(); i++)
	{
		int nMin = DEF_MAX;
		for (int j = 0; j < vChichen.size(); j++)
		{
			nMin = min(nMin, abs(vHome[i].first - vChichen[j].first) + abs(vHome[i].second - vChichen[j].second));
		}
		nSum += nMin;
	}
	return nSum;
}

void BT(const vector<p>& vHome, const vector<p>& vChichen, vector<p>& vSelectChichen, int nChickenSize, int &nResult, int nLastPos = 0)
{
	int nSize;
	nSize = vSelectChichen.size();

	//원하는 크기만큼 배열이 완성되면 값 계산
	if (nChickenSize == nSize)
	{
		nResult = min(nResult, ChickenDistance(vHome, vSelectChichen));
		return;
	}

	int nStart;
	
	if (nSize == 0)
		nStart = 0;
	else
		nStart = nLastPos + 1;

	//원하는 크리만큼 배열을 만들기위해 백트레킹 수행
	for (int i = nStart; i <= vChichen.size() - (nChickenSize - nSize); i++)
	{
		vSelectChichen.push_back(vChichen[i]);
		BT(vHome, vChichen, vSelectChichen, nChickenSize, nResult, i);
		vSelectChichen.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//갈수 있는 치킨집의 배열을 만들고
	//전체 순회하면서 최솟값을 계산
	//Declaration
	int nMapSize, nChickenSize, nResult = DEF_MAX;
	vmap vMap;
	vector<p> vHome, vChichen, vSelectChichen;

	//Input
	cin >> nMapSize >> nChickenSize;
	for (int i = 0; i < nMapSize; i++)
	{
		for (int j = 0; j < nMapSize; j++)
		{
			int nTemp;
			cin >> nTemp;

			if (nTemp == 1)
				vHome.push_back(p(i, j));
			else if(nTemp == 2)
				vChichen.push_back(p(i, j));
		}
	}

	//Solution
	BT(vHome, vChichen, vSelectChichen, nChickenSize, nResult);

	//Output
	cout << nResult << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}