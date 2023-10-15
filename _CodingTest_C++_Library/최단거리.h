#pragma once
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

//custum function
//template <typename T>
struct HeapCompare
{
	bool operator()(vector<int> a, vector<int> b)	//
	{
		if (a[1] == b[1])
			return a[0] > b[0];
		else
			return a[1] > b[1];
	}
};

struct DijkstraCompare
{
	bool operator()(pair<int, int> a, pair<int, int> b)	//Node, W
	{
		return a.second > b.second;
	}
};

vector<int> Dijkstra(int nNodeSize, int nEdgeSize, int nTarget, vector<vector<pair<int, int>>>& vEgde)//노드 개수, 간선 개수, 시작지점, 노드(1차)와 연결된 간선(2차)
{
	vector<int> vResult(nNodeSize + 1, INT_MAX);
	//우선순위 큐(오름차순)
	priority_queue<pair<int, int>, vector<pair<int, int>>, DijkstraCompare> pq; //(nNode, nW) : (노드, 가중치)

	//시작 노드 삽입
	pq.push(pair<int, int>(nTarget, 0));
	vResult[nTarget] = 0;

	while (!pq.empty())
	{
		int nNowNode = pq.top().first;
		int nNowCost = pq.top().second;
		pq.pop();

		//저장되어있는 가중치가 큐에 저장된 값보다 크다면 넘어간다
		if (vResult[nNowNode] < nNowCost)
		{
			continue;
		}

		//가중치 갱신
		for (int i = 0; i < vEgde[nNowNode].size(); i++)
		{
			//거쳐서 갈 때 목적지와 가중치
			int nTargetNode = vEgde[nNowNode][i].first;
			int nTargetCost = vEgde[nNowNode][i].second;

			//저장되어 있는 가중치보다 현재 노드를 거쳐서 갈때가 더 낮다면 갱신
			if (vResult[nTargetNode] > nNowCost + nTargetCost)
			{
				vResult[nTargetNode] = nNowCost + nTargetCost;
				pq.push(pair<int, int>(nTargetNode, vResult[nTargetNode]));
			}
		}
	}

	return vResult;
}

//vMap[A][B]는 A에서 B로 갈때 최소 Cost
void FloydWarshall(vector<vector<int>>& resultCost)
{
	//int 범위를 신경쓰면서 사용해야함 (1억까지) (그냥 INT_MAX를 쓰면 임시변수에서 오버플로우)
	int nNodeSize = resultCost.size() - 1;
	for (int k = 1; k <= nNodeSize; ++k)
		for (int i = 1; i <= nNodeSize; ++i)
			for (int j = 1; j <= nNodeSize; ++j)
				if (resultCost[i][j] > resultCost[i][k] + resultCost[k][j])
					resultCost[i][j] = resultCost[i][k] + resultCost[k][j];
}

void FloydWarshall_old(vector<vector<int>>& resultCost)
{
	int nNodeSize = resultCost.size();
	for (int i = 0; i < nNodeSize; i++)
	{
		for (int j = 0; j < nNodeSize; j++)
		{
			for (int k = 0; k < nNodeSize; k++)
			{
				//이 조건문이 왜 들어간지 모르겠다
				if (k != i && k != j && i != j && (resultCost[i][k] != INT_MAX) && (resultCost[k][j] != INT_MAX))
				{
					if (resultCost[i][j] > resultCost[i][k] + resultCost[k][j])
						resultCost[i][j] = resultCost[i][k] + resultCost[k][j];
				}
			}
		}
	}
}

//MST