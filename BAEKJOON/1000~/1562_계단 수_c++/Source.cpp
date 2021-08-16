#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

//define

using ull = unsigned long long;
using location = pair<int, int>;
using matrix = vector<vector<int>>;
using dp = vector<vector<vector<int>>>;

const int LIMIT = 1000000000;
//custum function

int DFS(int lastNum, int bitMask, int target, dp &DP, int place = 1)
{
	int result = 0;

	//목표 자릿수에 도달 했다면 조건에 맞는지 확인
	if (place == target)
	{
		return bitMask == 0b1111111111;
	}

	//이전에 탐색했던 상황이라면 해당 값 반환
	if (DP[place][lastNum][bitMask] != -1)
	{
		return DP[place][lastNum][bitMask];
	}

	//내려갈때와 올라갈 때
	int routes[2] = { -1, 1 };
	for (auto route : routes)
	{
		int nextNum = lastNum + route;
		if (0 <= nextNum && nextNum <= 9)
		{
			result = (result + DFS(nextNum, bitMask | (1 << nextNum), target, DP, place + 1)) % LIMIT;
		}
	}

	return DP[place][lastNum][bitMask] = result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//DFS로 탐색을 한다.
	//단 이전에 탐색했던 상황(자릿수, 맨 뒷자리, 비트마스크)이라면 해당 결과를 반환한다
	//Declaration
	int target(0), answer(0);
	cin >> target;

	//Solution
	//10의 자리 미만에선 조건에 맞는 숫자가 나올 수 없다.
	if (target < 10)
	{
		//Output
		cout << "0\n";
	}
	else
	{
		//메모이제이션용 배열
		dp DP = dp(101, vector<vector<int>>(10, vector<int>(1 << 10, -1)));
		//맨 앞자리 부터 시작하여 숫자를 만들어 갔을 때 조건에 맞는 숫자를 탐색
		//맨 앞자리가 0인 숫자는 없으므로 1부터 시작
		for (int digit(1); digit < 10; ++digit)
		{
			answer = (answer + DFS(digit, 1 << digit, target, DP)) % LIMIT;
		}

		//Output
		cout << answer << '\n';
	}

	return 0;
}