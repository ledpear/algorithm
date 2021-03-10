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
	//����� ���� * �ּ� ������ �ִ��߷��� ��ü�� ���ø� �� �ִ� �߷��̴�
	//��� ������ ����ؾ��Ѵٸ� �־��� ������ �ִ��߷� �� ���� ���� �� * ������ �ϸ� �ǰ�����
	//��� ������ ����ؾ� �� �ʿ䰡 �����Ƿ� ���� ���� ������ �ϳ��� ���鼭 ���ø� �� �ִ� ��ü�� �ִ� �߷��� ���Ѵ�.
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