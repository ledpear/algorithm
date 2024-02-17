#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

//브루트포스로 푼다.
void makeCase(const int n, const int pos, const int count, vector<int>& current, vector<int>& answer, const vector<int>& info, int& maxScore)
{
    if (n == count)
    {
        //점수계산(점수의 차이를 계산해야함
        int scoreDiff = 0;
        for (int i = 0; i < info.size(); ++i)
        {
            const int currentPoint = 10 - i;
            if (current[i] > info[i])
                scoreDiff += currentPoint;
            else if (info[i] > current[i])
                scoreDiff -= currentPoint;
            else if(info[i] == current[i] && info[i] != 0)
                scoreDiff -= currentPoint;
        }

        //지금 점수차이보다 큰지 확인
        if (scoreDiff > maxScore)
        {
            maxScore = scoreDiff;
            answer = current;
        }
        else if (scoreDiff == maxScore)
        {
            //가장 낮은 숫자가 더 많은지 비교
            for (int i = current.size() - 1; i >= 0; --i)
            {
                if (current[i] > answer[i])
                {
                    answer = current;
                    break;
                }
                else if (current[i] < answer[i])
                    break;
            }
        }

        return;
    }

    if (pos > 10)
        return;

    for (int i = 0; i <= n; ++i)
    {
        if (count + i > n)
            continue;

        current[pos] = i;
        makeCase(n, pos + 1, count + i, current, answer, info, maxScore);
        current[pos] = 0;
    }
}

vector<int> solution(int n, vector<int> info) 
{
    vector<int> answer = { 0,0,0,0,0,0,0,0,0,0,0 };
    vector<int> current = { 0,0,0,0,0,0,0,0,0,0,0 };
    int maxDiffScore = 0;
    makeCase(n, 0, 0, current, answer, info, maxDiffScore);
    int answerSum = accumulate(answer.begin(), answer.end(), 0);
    if(answerSum != n)
        return { -1 };

    if (maxDiffScore <= 0)
        return { -1 };

    return answer;
}

int main()
{
    {
        vector<int> result = solution(5, { 2,1,1,1,0,0,0,0,0,0,0 });
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
    //{
    //    vector<int> result = solution(1, { 1,0,0,0,0,0,0,0,0,0,0 });
    //    for (int i : result)
    //        cout << i << " ";
    //    cout << endl;
    //}
    //{
    //    vector<int> result = solution(9, { 0,0,1,2,0,1,1,1,1,1,1 });
    //    for (int i : result)
    //        cout << i << " ";
    //    cout << endl;
    //}
    //{
    //    vector<int> result = solution(10, { 0,0,0,0,0,0,0,0,3,4,3 });
    //    for (int i : result)
    //        cout << i << " ";
    //    cout << endl;
    //}
    //{
    //    vector<int> result = solution(10, { 0,0,0,0,0,0,0,0,0,1,9 });
    //    for (int i : result)
    //        cout << i << " ";
    //    cout << endl;
    //}
}