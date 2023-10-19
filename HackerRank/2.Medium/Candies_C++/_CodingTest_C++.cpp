#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

using namespace std;

long candies(int n, vector<int> arr) 
{
    vector<long> resultFront(n, 0);
    {
        long prevNum = arr.front();
        long point = 1;
        resultFront[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            long currentNum = arr[i];
            if (prevNum < currentNum)
                ++point;
            else
                point = 1;

            resultFront[i] = point;
            prevNum = currentNum;
        }
    }
    
    vector<long> resultBack(n, 0);
    {
        long prevNum = arr.back();
        long point = 1;
        resultBack[n-1] = 1;
        for (int i = n - 2; i >= 0; --i)
        {
            long currentNum = arr[i];
            if (prevNum < currentNum)
                ++point;
            else
                point = 1;

            resultBack[i] = point;
            prevNum = currentNum;
        }
    }

    long answer = 0;
    for (int i = 0; i < n; ++i)
        answer += max(resultFront[i], resultBack[i]);

    return answer;
}

int main()
{
    {
        cout << candies(10, { 2,4,2,6,1,7,8,9,2,1 }) << endl;
        cout << candies(8, { 2,4,3,5,2,6,4,5 }) << endl;
        cout << candies(6, { 4,6,4,5,6,2 }) << endl;
    }

    return 0;
}