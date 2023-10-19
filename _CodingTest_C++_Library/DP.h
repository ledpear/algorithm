#pragma once

#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

namespace std
{
    // Overlapping Subproblems
    // Bottom-UP
    int dp1(int target, vector<int> dice)
    {
        //목표 값까지 DP 배열을 만들고 반복할때까지 하나씩 추가
        vector<vector<int>> dp(target / dice[0], vector<int>(target + 1, 0));
        for (int val : dice)
        {
            if (val <= target)
                dp[0][val] = 1;
        }

        for (int i = 1; i < dp.size(); ++i)
        {
            for (int j = 1; j <= target; ++j)
            {
                for (int diceVal : dice)
                {
                    int dpTarget = j - diceVal;
                    if (dpTarget <= 0)
                        continue;

                    dp[i][j] += dp[i - 1][dpTarget];
                }
            }
        }

        int answer = 0;
        for (int i = 0; i < dp.size(); ++i)
            answer += dp[i][target];

        return answer;
    }
}