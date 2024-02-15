#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>


using namespace std;

//이번달 까지 선물을 많이 보낸사람이 다음달에 선물하나를 받는다
//선물을 주고 받은 기록이 없거나 수가 같으면 [선물지수]가 높은 사람이 선물을 받는다.
//[선물지수]는 이번달까지 자신이 친구들에게 준 선물의 수에서 받은 선물의 수를 뺀 값
//지수까지 같다면 선물을 주고받지 않는다.
// 
//선물을 가장 많이 받을 친구가 받을 선물의 수 리턴

//풀이
//각 사람 별로 1대1로 매칭하여 선물을 주고 받는 결과를 계산해야한다
//그러기 위해서 일단 
//1.배열로 각 사람이 누구에게 선물을 몇개 줬는지 계산하고, 선물지수도 계산
//2.정리된 데이터로 1대1 매칭하여 결과를 계산한다.
//  결과를 계산할 때 조건 우선순위
//   1. 더 많이 보낸 사람
//   2. 지수가 더 높은 사람
//   3. 둘다 같으면 보내지않는다


//놓친 부분

void parsing(const string& data, vector<string>& result, const char delimiter = ' ')
{
    string token;
    stringstream splitStream(data);

    while (getline(splitStream, token, delimiter))
        result.push_back(token);
}

int solution(vector<string> friends, vector<string> gifts) 
{
    int answer = 0;
    const int friendSize = friends.size();

    //각 사람이 누구에게 선물을 몇개 줬는지 계산하면서 선물지수도 계산
    //사람을 인덱스로 바꿔서 정리한다.
    unordered_map<string, int> nameIndex;
    for (int i = 0; i < friendSize; ++i)
        nameIndex.insert(make_pair(friends[i], i));

    //각 사람별 보낸 선물 개수
    vector<vector<int>> giftTable(friendSize, vector<int>(friendSize, 0));
    //선물 지수
    vector<int> giftScoreTable(friendSize , 0);

    //데이터 순회
    for (const string& gift : gifts)
    {
        vector<string> giftFriend;
        parsing(gift, giftFriend);

        const int senderIndex = nameIndex[giftFriend[0]];
        const int receiverIndex = nameIndex[giftFriend[1]];

        ++giftTable[senderIndex][receiverIndex];
        ++giftScoreTable[senderIndex];
        --giftScoreTable[receiverIndex];
    }

    //결과 분석
    vector<int> nextGift(friendSize, 0);
    for (int targetIndex = 0; targetIndex < friendSize - 1; ++targetIndex)
    {
        for (int matchIndex = targetIndex + 1; matchIndex < friendSize; ++matchIndex)
        {
            //   1. 더 많이 보낸 사람
            if (giftTable[targetIndex][matchIndex] > giftTable[matchIndex][targetIndex])
                ++nextGift[targetIndex];
            else if (giftTable[targetIndex][matchIndex] < giftTable[matchIndex][targetIndex])
                ++nextGift[matchIndex];
            else
            {
                //   2. 지수가 더 높은 사람
                if (giftScoreTable[targetIndex] > giftScoreTable[matchIndex])
                    ++nextGift[targetIndex];
                else if (giftScoreTable[targetIndex] < giftScoreTable[matchIndex])
                    ++nextGift[matchIndex];
            }
        }
    }

    answer = *max_element(nextGift.begin(), nextGift.end());
    return answer;
}

int main()
{
    {
        vector<string> friends = { "muzi", "ryan", "frodo", "neo" };
        vector<string> gifts = { "muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi" };
        int answer = solution(friends, gifts);
        cout << answer << endl;
    }
    {
        vector<string> friends = { "joy", "brad", "alessandro", "conan", "david" };
        vector<string> gifts = { "alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david" };
        int answer = solution(friends, gifts);
        cout << answer << endl;
    }
    {
        vector<string> friends = { "a", "b", "c" };
        vector<string> gifts = { "a b", "b a", "c a", "a c", "a c", "c a" };
        int answer = solution(friends, gifts);
        cout << answer << endl;
    }
}