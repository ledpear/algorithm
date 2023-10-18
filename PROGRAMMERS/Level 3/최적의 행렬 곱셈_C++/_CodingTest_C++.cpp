#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int INF = 100000000;

void backTracking(vector<vector<int>> matrix_sizes, int lhsIndex, int rhsIndex, unsigned long long count, unsigned long long& min)
{
    if (lhsIndex != -1)
    {
        //연산되는 왼쪽, 오른쪽 인덱스를 받아서 행렬 크기 계산
        vector<int> lhs = matrix_sizes[lhsIndex];
        vector<int> rhs = matrix_sizes[rhsIndex];

        //count 갱신
        count += ((unsigned long long)lhs[0] * (unsigned long long)lhs[1] * (unsigned long long)rhs[1]);

        //탈출구
        if (matrix_sizes.size() == 2)
        {
            if (min > count)
                min = count;

            return;
        }

        //연산 후 제거 및 행렬 추가

        matrix_sizes.erase(matrix_sizes.begin() + lhsIndex);
        matrix_sizes.erase(matrix_sizes.begin() + rhsIndex - 1);
        matrix_sizes.push_back({ lhs[0], rhs[1] });
    }

    //행렬 추가 후 조합을 찾는다
    for (int i = 0; i < matrix_sizes.size() - 1; ++i)
    {
        for (int j = i + 1; j < matrix_sizes.size(); ++j)
        {
            //정방향
            if (matrix_sizes[i][1] == matrix_sizes[j][0])
                backTracking(matrix_sizes, i, j, count, min);

            //역방향
            if (matrix_sizes[j][1] == matrix_sizes[i][0])
                backTracking(matrix_sizes, j, i, count, min);
        }
    }
}

//백트레킹으로 다시 풀어보자 or dfs
int solution(vector<vector<int>> matrix_sizes) 
{
    unsigned long long answer = INF;
    backTracking(matrix_sizes, -1, -1, 0, answer);

    return answer;
}

int main()
{
    vector<vector<int>> matrix_sizes;
    matrix_sizes.push_back(vector<int>{5, 3});
    matrix_sizes.push_back(vector<int>{3, 10});
    matrix_sizes.push_back(vector<int>{10, 6});
    solution(matrix_sizes);
}