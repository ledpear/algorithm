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
typedef unsigned long long ull;
typedef pair<ull, ull> p;	// 0ÀÇ °¹¼ö, 1ÀÇ °¹¼ö


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ull nInput;
	cin >> nInput;

	vector<p> vDP_p(nInput + 1);

	if (nInput == 1)
		cout << 1 << '\n';
	else
	{
		vDP_p[1] = make_pair(0, 1);

		for (ull i = 2; i <= nInput; i++)
		{
			p pTemp;
			pTemp.first = vDP_p[i - 1].first + vDP_p[i - 1].second;
			pTemp.second = vDP_p[i - 1].first;
			vDP_p[i] = pTemp;
		}

		ull Result = vDP_p[nInput].first + vDP_p[nInput].second;

		cout << Result << '\n';
	}

	system("pause");

	return 0;
}