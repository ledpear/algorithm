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

//출발점에서 각 지점까지의 코스트와 각자 가는 거리 코스트를 더한 최소 코스트를 반환하면 풀릴듯
void FloydWarshall(vector<vector<int>>& resultCost)
{
	int nNodeSize = resultCost.size()-1;
	for (int k = 1; k <= nNodeSize; ++k)
		for (int i = 1; i <= nNodeSize; ++i)
			for (int j = 1; j <= nNodeSize; ++j)
				if (resultCost[i][j] > resultCost[i][k] + resultCost[k][j])
					resultCost[i][j] = resultCost[i][k] + resultCost[k][j];
}

int solution(int nodeCount, int start, int targetA, int targetB, vector<vector<int>> fares)
{
    int answer = INF;
	//n*n의 매트릭스를 만든다
	vector<vector<int>> costMap(nodeCount + 1, vector<int>(nodeCount + 1, INF));

	//경로 cost를 갱신
	for (const vector<int>& fare : fares)
	{
		int start = fare[0];
		int end = fare[1];
		int cost = fare[2];

		costMap[start][end] = cost;
		costMap[end][start] = cost;
	}

	for (int i = 1; i <= nodeCount; ++i)
		costMap[i][i] = 0;

	//플로이드 와샬 적용
	FloydWarshall(costMap);

	//각 지점별로 최소값을 계산
	for (int stopOverNode = 1; stopOverNode <= nodeCount; ++stopOverNode)
	{
		int totalCost = 0;
		//출발지에서 경유지까지 비용
		totalCost += costMap[start][stopOverNode];

		//경유지에서 각자 집까지의 비용
		totalCost += costMap[stopOverNode][targetA];
		totalCost += costMap[stopOverNode][targetB];

		//최소값 계산
		answer = min(answer, totalCost);
	}

    return answer;
}

int main()
{
	//{
	//	vector<vector<int>> fares;
	//	fares.push_back({ 4,1,10 });
	//	fares.push_back({ 3,5,24 });
	//	fares.push_back({ 5,6,2 });
	//	fares.push_back({ 3,1,41 });
	//	fares.push_back({ 5,1,24 });
	//	fares.push_back({ 4,6,50 });
	//	fares.push_back({ 2,4,66 });
	//	fares.push_back({ 2,3,22 });
	//	fares.push_back({ 1,6,25 });
	//	solution(6, 4, 6, 2, fares);
	//}

	//{
	//	vector<vector<int>> fares;
	//	fares.push_back({ 5,7,9 });
	//	fares.push_back({ 4,6,4 });
	//	fares.push_back({ 3,6,1 });
	//	fares.push_back({ 3,2,3 });
	//	fares.push_back({ 2,1,6 });
	//	solution(7, 3, 4, 1, fares);
	//}
	{
		vector<vector<int>> fares;
		fares.push_back({ 2,6,6 });
		fares.push_back({ 6,3,7 });
		fares.push_back({ 4,6,7 });
		fares.push_back({ 6,5,11 });
		fares.push_back({ 2,5,12 });
		fares.push_back({ 5,3,20 });
		fares.push_back({ 2,4,8 });
		fares.push_back({ 4,3,9 });
		solution(6,4,5,6, fares);
	}
	
}