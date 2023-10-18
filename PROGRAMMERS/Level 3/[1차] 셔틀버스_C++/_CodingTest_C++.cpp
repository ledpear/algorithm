#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int timeCompare(pair<int, int> lhs, pair<int, int> rhs)
{
    if (lhs.first == rhs.first)
    {
        if (lhs.second < rhs.second)
            return -1;
        else if (lhs.second == rhs.second)
            return 0;
        else
            return 1;
    }

    if (lhs.first < rhs.first)
        return -1;
    else
        return 1;
}

string solution(int n, int t, int m, vector<string> timetable) 
{
    string answer = "";

    //타임테이블 정렬
    sort(timetable.begin(), timetable.end());

    pair<int, int> shuttleTime = { 9, 0 };
    pair<int, int> answerTime = { 9, 0 };
    
    int crewCount = 0;
    int timeTableIndex = 0;

    //대기열이 다 찰수도 있으니깐 하나씩 순회하면서 어느순간 오버하는지 확인
    //오버하는 순간이 없다면 마지막 시간이 탑승시간

    //셔틀버스 시간을 순회
    pair<int, int> crewTime = { atoi(timetable[timeTableIndex].substr(0, 2).c_str()), atoi(timetable[timeTableIndex].substr(3, 5).c_str())};
    pair<int, int> lastCrewTime = { 9, 0 };
    for (int shuttleCount = 0; shuttleCount < n; ++shuttleCount)
    {
        //크루 탑승(최대인원이 다 찰경우 그 사람 직전 시간이 최대시간
        while ((timeTableIndex < timetable.size()) && timeCompare(crewTime, shuttleTime) < 1)
        {
            ++crewCount;
            if (crewCount == m)
                lastCrewTime = crewTime;

            //크루타임 갱신
            ++timeTableIndex;
            if (timeTableIndex < timetable.size())
                crewTime = { atoi(timetable[timeTableIndex].substr(0, 2).c_str()), atoi(timetable[timeTableIndex].substr(3, 5).c_str()) };
            else
                break;

            if (crewCount == m)
                break;
        }

        if (shuttleCount == n - 1)
        {
            if (crewCount == m)
            {
                answerTime = { lastCrewTime.first, lastCrewTime.second - 1 };
                if (answerTime.second < 0)
                {
                    --answerTime.first;
                    answerTime.second = 59;

                    if (answerTime.first < 0)
                        answerTime.first = 23;
                }
            }
            else
                answerTime = shuttleTime;
        }        

        //마지막에 셔틀 초기화 및 시간갱신
        {
            crewCount = 0;
            shuttleTime.second += t;
            if (shuttleTime.second >= 60)
            {
                ++shuttleTime.first;
                shuttleTime.second -= 60;
            }
        }        
    }

    //혹시 24시 넘었을때
    if (answerTime.first >= 24)
        answerTime = { 23, 59 };

    //결과 문자열화
    {
        if (answerTime.first < 10)
            answer += '0';

        answer += to_string(answerTime.first);
        answer += ':';

        if (answerTime.second < 10)
            answer += '0';

        answer += to_string(answerTime.second);
    }    

    return answer;
}

int main()
{
    //solution(1, 1, 5, { "08:00", "08:01", "08:02", "08:03" });
    //solution(2, 10, 2, { "09:10", "09:09", "08:00" });
    //solution(1, 10, 3, { "08:55", "08:55", "08:59" });
    solution(1, 1, 5, { "00:01", "00:01", "00:01","00:01", "00:01", "00:02", "00:03", "00:04" }); //"00:00"
    //solution(10, 1, 5, { "09:00", "09:00", "09:00", "09:00", "09:00" });
}