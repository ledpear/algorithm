#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

using namespace std;
//money의 숫자를 조합해서 n을 만든다.
//dp 사용
//money 순회하면서 해당 숫자로 n을 만들 수 있는 경우의 수를 더한다.
//정답이 커질 수 있으니, 1000000007로 나눈 나머지를 return 해주세요.

int solution(int n, vector<int> moneys) 
{
    vector<int> dp(n + 1, 0);
    sort(moneys.begin(), moneys.end());
    dp[0] = 1;
    for (const int money : moneys)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (i < money)
                continue;

            //dp[i] = max(dp[i], dp[i - money] + 1);
            dp[i] = (dp[i] + dp[i - money]) % 1000000007;
        }
    }

    return dp[n];
}

int main()
{
    solution(5, { 1,2,5 });
}