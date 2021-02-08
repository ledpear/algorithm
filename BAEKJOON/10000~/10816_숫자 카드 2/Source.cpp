#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

typedef pair<int, int> P;
vector<P> vArr;

int search(int nTarget)
{
	int nFirst = 0;
	int nLast = vArr.size() - 1;
	int nFind;
	while (nFirst <= nLast)
	{
		nFind = (nFirst + nLast) / 2;
		if (vArr[nFind].first == nTarget)
			return nFind;
		else
		{
			if (vArr[nFind].first < nTarget)
				nFirst = nFind + 1;
			else
				nLast = nFind - 1;
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nSize, nTest;

	cin >> nSize;
	
	int nTemp, nFind;
	cin >> nTemp;
	vArr.push_back(P(nTemp, 1));
	for (int i = 1; i < nSize; i++)
	{
		cin >> nTemp;
		nFind = search(nTemp);
		if (nFind == -1)
		{
			vArr.push_back(P(nTemp, 1));
			sort(vArr.begin(), vArr.end());
		}			
		else
			vArr[nFind].second += 1;
	}

	sort(vArr.begin(), vArr.end());

	cin >> nTest;
	vector<int> vTest(nTest);
	for (int i = 0; i < nTest; i++)
		cin >> vTest[i];

	int i;
	for (i = 0; i < nTest - 1; i++)
	{
		nFind = search(vTest[i]);
		if (nFind == -1)
			cout << '0';
		else
			cout << vArr[nFind].second;
		cout << ' ';
	}
	nFind = search(vTest[i]);
	if (nFind == -1)
		cout << '0\n';
	else
		cout << vArr[nFind].second << '\n';

	system("pause");

	return 0;
}