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
int solution(vector<int> money) {
	int answer = 0;

	int nSize(money.size());
	vector<int> vDpStart(nSize, 0), vDpEnd(nSize, 0);
	
	vDpStart[0] = money[0];
	vDpStart[1] = max(money[0], money[1]);
	vDpEnd[0] = money[1];
	vDpEnd[1] = max(money[1], money[2]);
	for (int i = 2; i < nSize - 1; i++)
	{
		int nStartCount(i), nEndCount(i + 1);
		vDpStart[i] = max(vDpStart[i - 1], vDpStart[i - 2] + money[i]);
		vDpEnd[i] = max(vDpEnd[i - 1], vDpEnd[i - 2] + money[i + 1]);
	}
	answer = max(vDpStart[nSize - 2], vDpEnd[nSize - 2]);

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
	cout << solution(vector<int>({ 1,2,3,4 })) << '\n';
	cout << solution(vector<int>({ 1,2,3,1 })) << '\n';
	cout << solution(vector<int>({ 1000,5,10,6,2000 })) << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}