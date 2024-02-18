#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

#include <queue>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) 
{
    long long answer = -1;

    long long minVal = 0, maxVal = 1e5 + (1e5 * 2) * (2 * 1e9);

    //이분탐색
    //최소와 최저의 중간으로 최적해를 찾는다
    //시간을 대입해서 g와 s가 만족하는지 확인하고 만족한다면 맥스를 만족하지 못한다면 민은 바꾼다.
    while (minVal <= maxVal)
    {
        //안되면 더해서 나누는 걸로 바꾸자
        long long currTime = (maxVal / 2) + (minVal / 2);
        long long gold = 0;
        long long silver = 0;
        long long weight = 0;
        for (int i = 0; i < g.size(); ++i)
        {
            long long count = (currTime + t[i]) / (t[i] * 2);
            gold += min(static_cast<long long>(g[i]), static_cast<long long>(count * w[i]));
            silver += min(static_cast<long long>(s[i]), static_cast<long long>(count * w[i]));
            weight += min(static_cast<long long>(g[i]+s[i]), static_cast<long long>(count * w[i]));
        }

        if (gold >= a && silver >= b && weight >= a + b)
        {
            answer = currTime;
            maxVal = currTime - 1;
        }
        else
            minVal = currTime + 1;
    }

    return answer;
}

int main()
{
    solution(10, 10, { 100 }, { 100 }, { 7 }, { 10 });
    solution(90, 500, { 70,70,0 }, { 0,0,500 }, { 100,100,2 }, { 4,8,1 });
    solution(100, 100, { 70,10,100 }, { 10,40,100 }, {25,10,5 }, { 2,3,5 });
}