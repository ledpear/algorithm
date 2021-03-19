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

enum 
{
	eStart = 0,
	eEnd
};

//custum function
int solution(vector<vector<int>> routes) {
	int answer = 0;

	//범위가 작은것 부터 하던가
	//범위를 추가해 가면서 하던가

	sort(routes.begin(), routes.end());

	int nCameraPos = routes[0][1], nCount(1);

	for (auto& vCar : routes)
	{
		if (nCameraPos < vCar[eStart])
		{
			nCameraPos = vCar[eEnd];
			++nCount;
		}
		else
		{
			if (nCameraPos > vCar[eEnd])
			{
				nCameraPos = vCar[eEnd];
			}
		}
	}
	answer = nCount;

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration


	//Solution


	//Output
	cout << solution(vector<vector<int>>{ {-20, 15}, { -14, -5 }, { -18, -13 }, { -5,-3 }}) << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}