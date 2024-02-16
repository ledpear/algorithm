﻿#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) 
{
    vector<int> dpArr(n + 1, 0);
    vector<int> dpArr2(n + 1, 0);
    if (tops[0] == 1)
    {
        dpArr[1] = 4;
        dpArr2[1] = 3;
    }
    else
    {
        dpArr[1] = 3;
        dpArr2[1] = 2;
    }

    for (int i = 2; i <= n; ++i)
    {
        unsigned long long val = 0;
        if (tops[i - 1] == 1)
            val = dpArr[i - 1] * 3;
        else
            val = dpArr[i - 1] * 2;

        val += dpArr2[i - 1];

        if (tops[i - 2] == 1)
            val += dpArr2[i - 1];
        else
            val += 2;

        dpArr[i] = val % 10007;
    }

    return dpArr[n];
}

int main()
{
    //cout << solution(4, { 1,1, 0, 1 }) << endl;
    cout << solution(2, { 1, 1 }) << endl;
    //cout << solution(10, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }) << endl;
}