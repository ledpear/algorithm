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
	//Input
	//Solution
	//Output

	for (int i = 0; i < 3; i++)
	{
		int nSum = 0, nTemp;
		for (int j = 0; j < 4; j++)
		{
			cin >> nTemp;
			nSum += nTemp;
		}
		if (nSum == 0)
			cout << "D\n";
		else if (nSum == 1)
			cout << "C\n";
		else if (nSum == 2)
			cout << "B\n";
		else if (nSum == 3)
			cout << "A\n";
		else if (nSum == 4)
			cout << "E\n";
	}


	////////////////////////////////////
	system("pause");
	return 0;
}