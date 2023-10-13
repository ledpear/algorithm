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
#include <unordered_set>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::ios_base;

using ull = unsigned long long;
using location = pair<int, int>;
using matrix = vector<vector<int>>;

using namespace std;

int solution(int n)
{
	int answer = -1;
	const int quotient = n / 5;
	const int remainder = n % 5;
	//5로 나눈 나머지가 3으로 나누어 떨어질때
	if (remainder % 3 == 0)
		answer = quotient + (remainder / 3);
	//5로 나눈 나머지 + 5가 3으로 나누어 떨어질때
	else if ((n > 5) && (remainder + 5) % 3 == 0)
		answer = (quotient - 1) + ((remainder + 5) / 3);
	//5로 나눈 나머지 + 10가 3으로 나누어 떨어질때
	else if ((n > 10) && (remainder + 10) % 3 == 0)
		answer = (quotient - 2) + ((remainder + 5) / 3);
	//3으로 나누어 떨어질때
	else if (n % 3 == 0)
		answer = n / 3;
	//이외에는 불가능

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//input
	int n = 0;
	//cin >> n;

	////5로 바로 나누어졌을 때
	//int answer = -1;
	//const int quotient = n / 5;
	//const int remainder = n % 5;
	//if (remainder % 2 == 0)
	//	answer = quotient + (remainder / 2);
	////나머지+5가 2로 나누어질때
	//else if ( (n > 5) &&  (remainder + 5) % 2 == 0)
	//	answer = (quotient - 1) + ((remainder + 5) / 2);
	////2로 나누어질 때
	//else if (n % 2 == 0)
	//	answer = n / 2;

	//cout << answer << endl;

	for (int i = 1; i < 1000000000; ++i)
		cout << solution(i) << endl;
	//이외엔 불가능
	////////////////////////////////////
	system("pause");
	return 0;
}