#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> rectangles, int characterX, int characterY, int itemX, int itemY) 
{
    int answer = INT_MAX;

    //맵에 사각형을 적용한다
    vector<vector<int>> map(101, vector<int>(101, 0));
    for (const vector<int> rectangle : rectangles)
    {
        int leftBottomX = rectangle[0] * 2;
        int leftBottomY = rectangle[1] * 2;
        int rightTopX = rectangle[2] * 2;
        int rightTopY = rectangle[3] * 2;

        for (int x = leftBottomX; x <= rightTopX; ++x)
        {
            for (int y = leftBottomY; y <= rightTopY; ++y)
            {
                if (map[y][x] == -1)
                    continue;
                
                if ((x == leftBottomX || x == rightTopX) || y == leftBottomY || y == rightTopY)
                    map[y][x] = 1;
                else
                    map[y][x] = -1;
            }
        }
    }

    //캐릭터 위치에서 BFS로 진행
    deque<vector<int>> bfsQueue;
    bfsQueue.push_back({ characterX*2, characterY*2, 0 });
    vector<int> moveX{ 0, 0, -1, 1 };
    vector<int> moveY{ 1, -1, 0, 0 };
    vector<vector<bool>> visit(51, vector<bool>(51, false));
    visit[characterY][characterX] = true;
    while (bfsQueue.empty() == false)
    {
        vector<int> currPos = bfsQueue.front();
        bfsQueue.pop_front();

        if (answer <= currPos[2])
            continue;

        //위치 검증
        if (currPos[0] == itemX *2 && currPos[1] == itemY*2)
            answer = min(answer, currPos[2]);

        //상하좌우 이동
        for (int dir = 0; dir < 4; ++dir)
        {
            vector<int> movePos{ currPos[0] + moveX[dir], currPos[1] + moveY[dir], currPos[2] + 1};

            for (int i = 0; i < 2; ++i)
            {
                if (movePos[i] < 0 || movePos[i] >50)
                    continue;
            }
            
            if (visit[movePos[1]][movePos[0]] == false && map[movePos[1]][movePos[0]] == 1)
            {
                bfsQueue.push_back(movePos);
                visit[movePos[1]][movePos[0]] = true;
            }
        }
    }

    return answer / 2;
}

int main()
{
    solution({ { 1, 1, 7, 4 }, { 3, 2, 5, 5 }, { 4, 3, 6, 9 },{ 2, 6, 8, 8} }, 1, 3, 7, 8);
}