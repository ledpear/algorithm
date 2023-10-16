#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) 
{
    vector<int> answer;

    //n개로 이루어진 집합 중 합이 s가 되어야 한다
    //n이 s보다 크면 무조건 -1
    if (n > s)
    {
        answer.push_back(-1);
        return answer;
    }

    //나누고 올림한값을 뺀다
    while (s > 0)
    {
        int num = s / n + (s % n != 0 ? 1 : 0);
        answer.push_back(num);
        s -= num;
        --n;
    }

    sort(answer.begin(), answer.end(), [](int rhs, int lhs)->bool { return rhs < lhs; });

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}