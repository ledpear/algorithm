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
#include <unordered_set>

using namespace std;

//define
#define DEF_MIN -2147483648
#define DEF_MAX 2147483647

using ull = unsigned long long ;
using location =  pair<int, int> ;
using matrix = vector<vector<int>>;

//custum function

int solution(int N, int number) {
	int answer = 0;
	vector<unordered_set<int>> s(8);

	string strTemp("");
	string strN = to_string(N);
	for (int i = 0; i < 8; ++i)
	{
		strTemp += strN;
		s[i].insert(stoi(strTemp));
	}

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			for (auto& op1 : s[j])
			{
				for (auto& op2 : s[i - j - 1])
				{
					s[i].insert(op1 + op2);
					s[i].insert(op1 - op2);
					s[i].insert(op1 * op2);
					if (op2 != 0) s[i].insert(op1 / op2);
				}
			}
		}
		if (s[i].find(number) != s[i].end())
		{
			answer = i + 1;
			break;
		}
	}

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
	cout << solution(5, 12) << '\n';
	cout << solution(2, 11) << '\n';


	////////////////////////////////////
	system("pause");
	return 0;
}