// sample_c++.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> solution(vector<vector<int>> line) 
{
    //순회하면서 교점을 구한다(정수 좌표에만 그려야한다
    vector<pair<long long, long long>> points;
    bool isFirst = true;
    long long xMin = 0;
    long long xMax = 0;
    long long yMin = 0;
    long long yMax = 0;
    for (long long i = 0; i < line.size(); ++i)
    {
        for (long long j = i + 1; j < line.size(); ++j)
        {
            double a = line[i][0];
            double b = line[i][1];
            double e = line[i][2];
            double c = line[j][0];
            double d = line[j][1];
            double f = line[j][2];

            //평행하거나 일치하는 경우(분모가 0인 경우) 예외처리
            double common = (a * d) - (b * c);
            if (common == 0)
                continue;

            //교점 계산
            double x = ((b * f) - (e * d)) / common;
            double y = ((e * c) - (a * f)) / common;

            //정수인지 판단한다 - 부동소수점 이슈로 로직 수정 가능성 있음
            if (x != static_cast<long long>(x))
                continue;

            if (y != static_cast<long long>(y))
                continue;

            //교점 등록 및 최대 최소 기록
            points.push_back(pair<long long, long long>(x, y));
            if (isFirst)
            {
                isFirst = false;

                xMin = x;
                xMax = x;
                yMin = y;
                yMax = y;
            }
            else
            {
                if (xMax < x)
                    xMax = x;
                if (xMin > x)
                    xMin = x;
                if (yMax < y)
                    yMax = y;
                if (yMin > y)
                    yMin = y;
            }
        }
    }

    //x축의 최대 최소와 y축의 최대 최소로 범위 구한다
    long long xLength = xMax - xMin + 1;
    long long yLength = yMax - yMin + 1;

    //구해진 최대 최소를 바탕으로 string을 계산
    vector<string>answer(yLength, string(xLength,'.'));
    for (pair<long long, long long> point : points)
    {
        long long x = point.first - xMin;
        long long y = (yLength - 1) - (point.second - yMin);

        answer[y][x] = '*';
    }

    return answer;
}

int main()
{
    {
        vector<vector<int>> line;
        line.push_back(vector<int>{2, -1, 4});
        line.push_back(vector<int>{-2, -1, 4});
        line.push_back(vector<int>{0,-1,1});
        line.push_back(vector<int>{5,-8,-12});
        line.push_back(vector<int>{5,8,12});
        vector<string> answer = solution(line);
        int a = 10;
    }
}