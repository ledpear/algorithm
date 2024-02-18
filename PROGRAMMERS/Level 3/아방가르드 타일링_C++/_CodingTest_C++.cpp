#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

using namespace std;

//세로는 3으로 고정
//타일은 90도씩 회전 가능
//2 = 3, 3 = 10가지 방법으로 타일링 가능
//I자 타일을 세웠을때 중복 발생

int solution(int n) 
{
    vector<int> dp(n+4, 0);
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 10;
    for (int i = 4; i <= n; ++i)
    {
        long long currentVal = 0;
        for (int j = 1; j < i; ++j)
        {
            currentVal += (dp[j] * dp[i - j]);
        }
        currentVal -= i - 2;
        dp[i] = currentVal % 1000000007;
    }

    return dp[n];
}

int main()
{
    for (int i = 1; i < 10; ++i)
        cout << solution(i) << endl;
}