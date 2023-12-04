#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>

#include <string>
#include <vector>

#include <unordered_map>
#include <unordered_set>
#include <sstream>
using namespace std;

void parsing(const string& data, vector<string>& result, const char delimiter = ' ')
{
    string token;
    stringstream splitStream(data);

    while (getline(splitStream, token, delimiter))
        result.push_back(token);
}

vector<int> solution(vector<string> id_list, vector<string> reports, int k) 
{
    vector<int> answer;

    //신고 중복 체크 map
    unordered_map<string, unordered_set<string>> duplicateCheck;
    unordered_map<string, int> reportCount;

    for (const string& report : reports)
    {
        vector<string> parsingResult;
        parsing(report, parsingResult);
        const string& reporter = parsingResult[0];
        const string& target = parsingResult[1];

        //중복체크
        if (duplicateCheck.find(reporter) == duplicateCheck.end())
            duplicateCheck[reporter] = unordered_set<string>();

        if (duplicateCheck[reporter].find(target) == duplicateCheck[reporter].end())
        {
            duplicateCheck[reporter].insert(target);
            if (reportCount.find(target) == reportCount.end())
                reportCount[target] = 0;

            ++reportCount[target];
        }
    }

    //결과 입력
    for (const string& reporter : id_list)
    {
        if (duplicateCheck.find(reporter) == duplicateCheck.end())
        {
            answer.emplace_back(0);
            continue;
        }

        int count = 0;
        for (const string& target : duplicateCheck[reporter])
        {
            if (reportCount[target] >= k)
                ++count;
        }

        answer.emplace_back(count);
    }

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";

    solution({ "muzi", "frodo", "apeach", "neo" }, { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" }, 2);
    solution({ "con", "ryan" }, { "ryan con", "ryan con", "ryan con", "ryan con" }, 3);
}