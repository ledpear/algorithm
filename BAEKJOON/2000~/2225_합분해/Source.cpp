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
	//N�� ���鶧 2..3..4..K�� ���� ���������� ����Ǽ��� ���ؼ� �޸������̼ǹ������ �ذ�
	//3���� ����Ҷ� 0���� N���� 2���� �ش���� ����� �ִ� ����� ���� ���ϸ��
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