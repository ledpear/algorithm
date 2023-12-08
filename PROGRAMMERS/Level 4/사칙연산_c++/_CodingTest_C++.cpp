#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> arr)
{
    //dp로 범위에 최대값을 구한다
    int size = (arr.size() + 1) / 2;
    vector<vector<int>> dpArr(size, vector<int>(size, INT_MIN));
    for (int i = 0; i < size; ++i)
        dpArr[i][i] = atoi(arr[i * 2].c_str());

    for (int range = 1; range < size; ++range)
    {
        for (int start = 0; start + range < size; ++start)
        {
            const int end = start + range;
            for (int mid = start; mid < end; ++mid)
            {
                int newVal = dpArr[start][mid];
                if (arr[mid * 2 + 1][0] == '+')
                    newVal += dpArr[mid + 1][end];
                else
                    newVal -= dpArr[mid + 1][end];

                dpArr[start][end] = max(dpArr[start][end], newVal);
            }
        }
    }

    vector<vector<int>> dpArrMin(size, vector<int>(size, INT_MAX));
    for (int i = 0; i < size; ++i)
        dpArrMin[i][i] = atoi(arr[i * 2].c_str());

    for (int range = 1; range < size; ++range)
    {
        for (int start = 0; start + range < size; ++start)
        {
            const int end = start + range;
            for (int mid = start; mid < end; ++mid)
            {
                int newVal = dpArrMin[start][mid];
                if (arr[mid * 2 + 1][0] == '+')
                    newVal += dpArrMin[mid + 1][end];
                else
                    newVal -= dpArrMin[mid + 1][end];

                dpArrMin[start][end] = min(dpArrMin[start][end], newVal);
            }
        }
    }

    for (int range = 1; range < size; ++range)
    {
        for (int start = 0; start + range < size; ++start)
        {
            const int end = start + range;
            for (int mid = start; mid < end; ++mid)
            {
                int newVal = dpArr[start][mid];
                if (arr[mid * 2 + 1][0] == '+')
                    newVal += dpArr[mid + 1][end];
                else
                    newVal -= dpArrMin[mid + 1][end];

                dpArr[start][end] = max(dpArr[start][end], newVal);
            }
        }
    }

    return dpArr[0][size-1];
}

int main()
{
    solution({ "1", "-", "3", "+", "5", "-", "8" });
}