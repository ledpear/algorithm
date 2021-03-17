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
typedef pair<ull, ull> p;
typedef vector<vector<int>> vmap;

//custum function

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int nSize, nCount = 0;
	vector<vector<bool>> vArr(102, vector<bool>(102, false));

	//Input
	//Solution
	cin >> nSize;
	for (int i = 0; i < nSize; i++)
	{
		int nTempX, nTempY;
		cin >> nTempX >> nTempY;

		for (int a = nTempY; a < nTempY + 10; a++)
		{
			for (int b = nTempX; b < nTempX + 10; b++)
			{
				if (vArr[a][b] == false)
				{
					nCount++;
					vArr[a][b] = true;
				}
			}				
		}
	}
	//Output
	cout << nCount << '\n';


	////////////////////////////////////
	system("pause");
	return 0;
}