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
	string strInput;
	int nArr[26] = { 0, };

	//Input
	//Solution
	cin >> strInput;
	for (int i = 0; i < strInput.size(); i++)
	{
		nArr[strInput[i] - 'a']++;
	}

	//Output
	for (int i = 0; i < 26; i++)
	{
		cout << nArr[i] << ' ';
	}
	cout << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}