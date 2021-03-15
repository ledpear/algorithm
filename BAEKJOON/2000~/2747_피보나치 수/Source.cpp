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
	int nInput, num1, num2, nTemp;

	//Input
	cin >> nInput;

	//Solution
	num1 = 0;
	num2 = 1;
	for (int i = 0; i < nInput - 1; i++)
	{
		nTemp = num2;
		num2 += num1;
		num1 = nTemp;
	}

	//Output
	if(nInput == 0)
		cout << num1 << '\n';
	else
		cout << num2 << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}