#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

//define
#define DEF_MIN -2147483648
#define DEF_MAX 2147483647

using ull = unsigned long long ;
using location =  pair<int, int> ;
using matrix = vector<vector<int>>;

//custum function

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int nSize(0), nSum(0);

	//Solution
	cin >> nSize;
	for (int nPeople = 0; nPeople < nSize; ++nPeople)
	{
		int nOpinion(0);
		cin >> nOpinion;
		nSum += nOpinion;
	}

	//Output
	if (nSize / 2 < nSum)
	{
		cout << "Junhee is cute!" << '\n';
	}
	else
	{
		cout << "Junhee is not cute!" << '\n';
	}

	////////////////////////////////////
	system("pause");
	return 0;
}