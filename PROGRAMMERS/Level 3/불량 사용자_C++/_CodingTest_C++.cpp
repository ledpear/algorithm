#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;
bool idCheck(const string& user, const string& banned)
{
    if (user.size() != banned.size())
        return false;

    int i = 0;
    for (; i < user.size(); ++i)
    {
        if (banned[i] == '*')
            continue;

        if (banned[i] != user[i])
            break;
    }

    if (i == user.size())
        return true;

    return false;
}

void dfs(vector<bool>& userIdVisit, int bannedIdIndex, const vector<string>& user_id, const vector<string>& banned_id, unordered_set<string>& duplicateCheck)
{
    //마지막 인덱스까지 순회했으면 등록
    if (banned_id.size() <= bannedIdIndex)
    {
        //아이디 리스트를 문자열로 만든다.
        string idListSting = "";
        for (int i = 0; i < userIdVisit.size(); ++i)
        {
            if (userIdVisit[i])
                idListSting.push_back(static_cast<char>(i + 48));
        }

        if (duplicateCheck.find(idListSting) == duplicateCheck.end())
            duplicateCheck.insert(idListSting);

        return;
    }

    const string& ban = banned_id[bannedIdIndex];
    for (int i = 0; i < userIdVisit.size(); ++i)
    {
        if (userIdVisit[i])
            continue;

        if (idCheck(user_id[i], banned_id[bannedIdIndex]))
        {
            userIdVisit[i] = true;
            dfs(userIdVisit, bannedIdIndex + 1, user_id, banned_id, duplicateCheck);
            userIdVisit[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) 
{
        vector<bool> userIdVisit(user_id.size(), false);
    unordered_set<string> duplicateCheck;
    dfs(userIdVisit, 0, user_id, banned_id, duplicateCheck);

    return duplicateCheck.size();
}

int main()
{
    solution(vector<string>{"frodo", "fradi", "crodo", "abc123", "frodoc"}, vector<string>{"*rodo", "*rodo", "******"});
}