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

using namespace std;

//시작 지점을 찾는다 : 나가기만 하는 노드이면서 엣지가 2개 이상
//그래프를 탐색해서 종류가 무엇인지 찾는다.(함수로하자)

void dfs( unordered_map<int, pair<vector<int>, vector<int>>>& nodeMap, const int node, unordered_set<int>& nodeVisit, unordered_set<string>& edgeVisit)
{
    //n은 함수 시작할 때
    //edge는 함수 진입할 때 증가
    for (const auto nextNode : nodeMap[node].first)
    {
        string edge = to_string(node) + "/" + to_string(nextNode);
        if (edgeVisit.find(edge) != edgeVisit.end())
            continue;

        edgeVisit.insert(edge);
        if (nodeVisit.find(nextNode) == nodeVisit.end())
            nodeVisit.insert(nextNode);

        dfs(nodeMap, nextNode, nodeVisit, edgeVisit);
    }
}

vector<int> solution(vector<vector<int>> edges) 
{
    vector<int> answer;
    unordered_map<int, pair<vector<int>, vector<int>>> nodeMap; //first : 출발 노드 / Second : 도착노드
    for (const auto& edge : edges)
    {
        const int startNode = edge[0];
        if (nodeMap.find(startNode) == nodeMap.end())
            nodeMap.insert(make_pair(startNode, make_pair(vector<int>(), vector<int>())));

        const int endNode = edge[1];
        if (nodeMap.find(endNode) == nodeMap.end())
            nodeMap.insert(make_pair(endNode, make_pair(vector<int>(), vector<int>())));

        nodeMap[startNode].first.push_back(endNode);
        nodeMap[endNode].second.push_back(startNode);
    }

    //시작 지점을 찾는다.
    int centerNode = -1;
    for (auto& node : nodeMap)
    {
        if ((node.second.first.size() >= 2) && (node.second.second.size() == 0))
        {
            centerNode = node.first;
            break;
       }
    }

    int donut = 0;
    int stick = 0;
    int eight = 0;
    for (const int startNode : nodeMap[centerNode].first)
    {
        unordered_set<int> nodeVisit;
        unordered_set<string> edgeVisit;
        nodeVisit.insert(startNode);
        dfs(nodeMap, startNode, nodeVisit, edgeVisit);
        const int nodeSize = nodeVisit.size();
        const int edgeSize = edgeVisit.size();
        if (nodeSize == edgeSize)
            ++donut;
        else if (nodeSize - 1 == edgeSize)
            ++stick;
        else
            ++eight;
    }

    return {centerNode, donut, stick, eight};
}

int main()
{
    {
        auto result = solution({ {2,3},{4,3}, {1,1},{2,1} });
        int a = 10;
    }
    {
        auto result = solution({ {4,11},{1,12},{8,3},{12,7},{4,2},{7,11},{4,8},{9,6},{10,11},{6,10},{3,5},{11,1}, {5,3},{11,9},{3,8} });
        int a = 10;
    }
}