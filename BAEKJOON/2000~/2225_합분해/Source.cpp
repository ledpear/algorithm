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
	//N을 만들때 2..3..4..K개 까지 순차적으로 경우의수를 구해서 메모이제이션방식으로 해결
	//3개를 사용할땐 0부터 N까지 2개로 해당수를 만들수 있는 경우의 수를 구하면됨
	//Declaration
	int N, K;
	vector<vector<int>> vDP;

	//Input
	cin >> N >> K;
	vDP = vector<vector<int>>(K, vector<int>(N + 1, 1));

	//Solution
	for (int j = 1; j < K; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			vDP[j][i] = (vDP[j - 1][i] + vDP[j][i - 1]) % 1000000000;
		}
	}

	//Output
	cout << vDP[K - 1][N] << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}