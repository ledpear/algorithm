#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> works) 
{
    long long answer = 0;
    priority_queue<int> pq;
    for (const int work : works)
        pq.push(work);

    for (int i = n; i > 0; --i)
    {
        int currWork = pq.top();
        pq.pop();

        if (currWork == 0)
            break;

        --currWork;
        pq.push(currWork);
    }

    while (pq.empty() == false)
    {
        answer += static_cast<long long>(pq.top()) * static_cast<long long>(pq.top());
        pq.pop();
    }

    return answer;
}

int main()
{
    solution(4, { 4,3,3 });
}