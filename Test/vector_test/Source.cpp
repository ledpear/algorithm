#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//define

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

	vector<int> test1(3);
	test1[0] = 1;
	test1[1] = 1;
	test1[2] = 1;

	vector<int> &test2 = test1;
	cout << test2[1] << '\n';

	test2[1] = 2;
	cout << test1[1] << '\n';
	cout << test2[1] << '\n';
	//Solution


	//Output


	////////////////////////////////////
	system("pause");
	return 0;
}