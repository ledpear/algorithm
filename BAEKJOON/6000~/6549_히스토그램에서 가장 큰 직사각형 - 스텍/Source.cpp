#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>

using namespace std;
typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		ull nSize;
		cin >> nSize;
		if (nSize == 0)
			break;

		ull nMax = 0;

		set<ull> sArr;
		vector<ull> vArr(nSize);
		for (int i = 0; i < nSize; i++)
		{
			cin >> vArr[i];
			if (sArr.find(vArr[i]) == sArr.end())
				sArr.insert(vArr[i]);
		}

		for (ull key : sArr)
		{			
			ull nCount = 0;
			ull nTemp;
			for (int i = 0; i < nSize; i++)
			{
				if (key <= vArr[i])
				{
					nCount++;
				}
				else
				{
					nTemp = nCount * key;
					if (nMax < nTemp)
						nMax = nTemp;
					nCount = 0;
				}
			}
			nTemp = nCount * key;
			if (nMax < nTemp)
				nMax = nTemp;
		}
		cout << nMax << '\n';
	}

	system("pause");

	return 0;
}