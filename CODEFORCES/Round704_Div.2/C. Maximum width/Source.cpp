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
typedef pair<ull, ull> p;		//min, max

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N_size, M_size;
	cin >> N_size >> M_size;
	string strN, strM;
	cin >> strN;
	cin >> strM;

	vector<p> vArr(M_size, p(-1, -1));

	for (int i = 0; i < M_size; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < N_size; j++)
			{
				if (strM[i] == strN[j])
				{
					vArr[i].first = j;
					break;
				}
			}
		}
		else
		{
			for (int j = vArr[i - 1].first + 1; j < N_size; j++)
			{
				if (strM[i] == strN[j])
				{
					vArr[i].first = j;
					break;
				}
			}
		}
	}

	for (int i = M_size - 1; i >= 0; i--)
	{
		if (i == M_size - 1)
		{
			for (int j = N_size - 1; j >= 0; j--)
			{
				if (strM[i] == strN[j])
				{
					vArr[i].second = j;
					break;
				}
			}
		}
		else
		{
			for (int j = vArr[i + 1].second - 1; j >= 0; j--)
			{
				if (strM[i] == strN[j])
				{
					vArr[i].second = j;
					break;
				}
			}
		}
	}

	int nMax = 0;
	for (int i = 0; i < M_size - 1; i++)
	{
		if (nMax < vArr[i + 1].second - vArr[i].first)
		{
			nMax = vArr[i + 1].second - vArr[i].first;
		}
	}

	cout << nMax << '\n';
	system("pause");

	return 0;
}