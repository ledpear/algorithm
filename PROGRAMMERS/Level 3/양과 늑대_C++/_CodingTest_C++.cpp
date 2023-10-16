#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

using namespace std;

//백트레킹
void backTracking(const vector<int>& info, vector<bool>& visit, vector<bool>& duplicationCheck, const vector<vector<int>>& nodeEdge, deque<int> routeQueue, int& maxScore, int sheepCount, int wolfCount, int currentNode)
{
	//시작은 정해져있으니 시작할 때 갈 수 있는 경로를 큐에 넣는다
	//큐에 있는 걸 빼고 처리 후 다시 넣는다
	//경로 관리는 일단 하지말자

	//양 or 늑대 카운트
	if (info[currentNode] == 0)
		++sheepCount;
	else
		++wolfCount;

	//늑대가 많아지는 순간 양은 무조건 0이 될 수 밖에 없다 (1씩 증가하기 때문)
	if (sheepCount <= wolfCount)
		return;

	//점수 계산
	if (maxScore < sheepCount)
		maxScore = sheepCount;

	//갈수있는 경로 추가
	int addCount = 0;
	for (const int nextNode : nodeEdge[currentNode])
	{
		if (visit[nextNode])
			continue;

		if (duplicationCheck[nextNode])
			continue;

		routeQueue.push_back(nextNode);
		duplicationCheck[nextNode] = true;
		++addCount;
	}

	//탈출부(리턴필요)
	if (routeQueue.empty())
		return;

	//현재 노드에서 나아가는지

	//이전 방문지 경로에서 나아가는지

	const int routeCount = routeQueue.size();
	for (int index = 0; index < routeCount; ++index)
	{
		int nextNode = routeQueue.front();

		//전처리
		routeQueue.pop_front();
		visit[nextNode] = true;
		duplicationCheck[nextNode] = false;

		//본처리
		backTracking(info, visit, duplicationCheck, nodeEdge, routeQueue, maxScore, sheepCount, wolfCount, nextNode);

		//후처리
		routeQueue.push_back(nextNode);
		visit[nextNode] = false;
		duplicationCheck[nextNode] = true;
	}

	for (int i = 0; i < addCount; ++i)
	{
		duplicationCheck[routeQueue.back()] = false;
		routeQueue.pop_back();
	}
}

int solution(vector<int> info, vector<vector<int>> edges)
{
	int answer = 0;

	//BFS를 사용하자(일단 백트레킹을 쓰자)
	//백트레킹을 써야할거같은데

	//각 노드 별 갈 수 있는 경로 구분
	const int nodeSize = info.size();
	vector<vector<int>> nodeEdge(nodeSize, vector<int>());
	for (const vector<int>& edge : edges)
		nodeEdge[edge[0]].push_back(edge[1]);

	deque<int> routeQueue;
	vector<bool> visit(nodeSize, false);
	vector<bool> duplicationCheck(nodeSize, false);
	backTracking(info, visit, duplicationCheck, nodeEdge, routeQueue, answer, 0, 0, 0);

	return answer;
}

int main()
{
	{
		vector<vector<int>> edges;
		edges.push_back({ 0,1 });
		edges.push_back({ 1,2 });
		edges.push_back({ 1,4 });
		edges.push_back({ 0,8 });
		edges.push_back({ 8,7 });
		edges.push_back({ 9,10 });
		edges.push_back({ 9,11 });
		edges.push_back({ 4,3 });
		edges.push_back({ 6,5 });
		edges.push_back({ 4,6 });
		edges.push_back({ 8,9 });
		solution(vector<int>{0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1}, edges);
	}

	{
		vector<vector<int>> edges;
		edges.push_back({ 0,1 });
		edges.push_back({ 0,2 });
		edges.push_back({ 1,3 });
		edges.push_back({ 1,4 });
		edges.push_back({ 2,5 });
		edges.push_back({ 2,6 });
		edges.push_back({ 3,7 });
		edges.push_back({ 4,8 });
		edges.push_back({ 6,9 });
		edges.push_back({ 9,10 });
		solution(vector<int>{0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0}, edges);
	}
	
}