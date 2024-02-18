#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

//주사위 갯수 n 일 때, n/2개를 가져가서 굴린다.
//n은 2,4,6,8,10 중 하나고 1~5개까지 주사위를 가져가게 된다.
//주사위를 선택하는 경우의 수 * 주사위를 굴렸을 때 나오는 조합의 경우의 수
//10*9*8*7*6 = 30240 ->이걸 줄인다.
//주사위를 굴렸을 때 나오는 조합의 경우의 수
//6의 5제곱 = 7776
//=

void makeScoreList(const vector<vector<int>>& dice, const vector<int>& myDice, vector<int>& result, int myScore, int myCount)
{
    if (myCount < myDice.size())
    {
        const vector<int>& currentDice = dice[myDice[myCount]];
        for (const int score : currentDice)
            makeScoreList(dice, myDice, result, myScore + score, myCount + 1);

        return;
    }
    else
        result.push_back(myScore);
}

//score 구성 : 0은 승리횟수 1 ~ n은 선택한 주사위
void selectDice(const vector<vector<int>>& dice, const int diceSize, const int lastIndex, const int maxCount, vector<int>& choice, unordered_set<string>& history, vector<int>& score)
{
    //승률 계산
    if (choice.size() == maxCount)
    {
        string log = "";
        for (const int index : choice)
            log += to_string(index);

        //이미 검증되었으면 리턴
        if (history.find(log) != history.end())
            return;

        //히스토리 기록
        history.insert(log);

        //상대방 주사위 배열 만들기
        vector<int> opponent;
        int myIndex = 0;
        for (int i = 0; i < diceSize; ++i)
        {
            if (myIndex < maxCount && i == choice[myIndex])
            {
                ++myIndex;
                continue;
            }

            opponent.push_back(i);
        }

        //상대방 주사위도 기록
        string opponentLog = "";
        for (const int index : opponent)
            opponentLog += to_string(index);

        history.insert(opponentLog);

        //승률 계산
        vector<int> myScoreArr(0);
        makeScoreList(dice, choice, myScoreArr, 0, 0);
        vector<int> youScoreArr(0);
        makeScoreList(dice, opponent, youScoreArr, 0, 0);

        //정렬
        sort(myScoreArr.begin(), myScoreArr.end());
        sort(youScoreArr.begin(), youScoreArr.end());

        //비교
        int myWinCount = 0;
        int youWinCount = 0;
        {
            int myScoreIndex = 0;
            int youSocreIndex = 0;
            int myWin = 0;
            while (myScoreIndex < myScoreArr.size() )
            {
                int myScore = myScoreArr[myScoreIndex];
                int youScore = youScoreArr[youSocreIndex];

                if (myScore > youScore)
                {
                    ++myWin;
                    if(youSocreIndex < youScoreArr.size() - 1)
                        ++youSocreIndex;
                    else
                    {
                        myWinCount += myWin;
                        ++myScoreIndex;
                    }
                }
                else
                {
                    myWinCount += myWin;
                    ++myScoreIndex;
                }
            }
        }
        {
            int myScoreIndex = 0;
            int youSocreIndex = 0;
            int youWin = 0;
            while (youSocreIndex < youScoreArr.size())
            {
                int myScore = myScoreArr[myScoreIndex];
                int youScore = youScoreArr[youSocreIndex];

                if (myScore < youScore)
                {
                    ++youWin;
                    if (myScoreIndex < myScoreArr.size() - 1)
                        ++myScoreIndex;
                    else
                    {
                        youWinCount += youWin;
                        ++youSocreIndex;
                    }
                }
                else
                {
                    youWinCount += youWin;
                    ++youSocreIndex;
                }
            }
        }

        const int winCount = myWinCount > youWinCount ? myWinCount : youWinCount;
        const vector<int>& winDice = myWinCount > youWinCount ? choice : opponent;

        if (score[0] < winCount)
        {
            score[0] = winCount;
            for (int i = 0; i < maxCount; ++i)
                score[i + 1] = winDice[i];
        }

        return;
    }

    //주사위 선택
    for (int i = lastIndex + 1; i < diceSize; ++i)
    {
        choice.push_back(i);
        selectDice(dice, diceSize, i, maxCount, choice, history, score);
        choice.pop_back();
    }
}

vector<int> solution(vector<vector<int>> dice) 
{
    //주사위 경우의 수
    const int diceSize = dice.size();
    const int maxCount = diceSize / 2;
    vector<int> choice;
    unordered_set<string> history;
    vector<int> score = { 0 };

    for (int i = 0; i < maxCount; ++i)

        score.push_back(0);

    selectDice(dice, diceSize, -1, maxCount, choice, history, score);

    //마지막에 1씩 더해줘야함(인덱스)
    vector<int> answer;
    for (int i = 1; i < score.size(); ++i)
        answer.push_back(score[i] + 1);

    return answer;
}

int main()
{
    {
        vector<int> result = solution({ {1, 2, 3, 4, 5, 6}, {3, 3, 3, 3, 4, 4}, {1, 3, 3, 4, 4, 4}, {1, 1, 4, 4, 5, 5} });
        for (int a : result)
            cout << a << " ";
        cout << endl;
    }
    {
        vector<int> result = solution({ {1, 2, 3, 4, 5, 6}, {2, 2, 4, 4, 6, 6} });
        for (int a : result)
            cout << a << " ";
        cout << endl;
    }
    {
        vector<int> result = solution({ {40, 41, 42, 43, 44, 45}, {43, 43, 42, 42, 41, 41}, {1, 1, 80, 80, 80, 80}, {70, 70, 1, 1, 70, 70} });
        for (int a : result)
            cout << a << " ";
        cout << endl;
    }
}