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
	//사용한 로프 * 최소 로프의 최대중량이 물체를 들어올릴 떄 최대 중량이다
	//모든 로프를 사용해야한다면 주어진 로프의 최대중량 중 가장 작은 값 * 갯수로 하면 되겠지만
	//모든 로프를 사용해야 할 필요가 없으므로 가장 작은 값부터 하나씩 빼면서 들어올릴 수 있는 물체의 최대 중량을 구한다.
	//Declaration
	int nSize, nMax = 0;
	vector<int> vArr;

	//Input
	cin >> nSize;
	vArr = vector<int>(nSize);
	for (int i = 0; i < nSize; i++)
		cin >> vArr[i];

	//Solution
	sort(vArr.begin(), vArr.end());
	for (int i = 0; i < nSize; i++)
	{
		nMax = max(nMax, vArr[i] * (nSize - i));
	}

	//Output
	cout << nMax << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}