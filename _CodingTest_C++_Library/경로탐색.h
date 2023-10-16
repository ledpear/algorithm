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

bool DfsMap(const vector<vector<int>>& vMap, vector<vector<bool>>& vVisit, int nX, int nY)
{
	//방문처리
	if (vVisit[nX][nY] == true)
	{
		return false;
	}
	vVisit[nX][nY] = true;

	//크기 정의
	int nSizeX = vMap.size();
	int nSizeY = vMap[0].size();

	//이동패턴 정의
	int nMoveX[4] = { 0, 0, 1, -1 };
	int nMoveY[4] = { 1, -1, 0, 0 };

	//이동할 수 있는 곳은 이동
	for (int i = 0; i < 4; i++)
	{
		int nPosX = nX + nMoveX[i];
		int nPosY = nY + nMoveY[i];

		//범위 및 방문 예외처리
		if (nPosX >= 0 && nPosX < nSizeX && nPosY >= 0 && nPosY < nSizeY && vVisit[nPosX][nPosY] == false)
		{
			//조건
			int nPosValue = vMap[nPosX][nPosY];
			if (nPosValue != 0)
			{
				DfsMap(vMap, vVisit, nPosX, nPosY);
			}
		}
	}
	return true;
}

bool DfsEgde(vector<bool>& visit, const vector<vector<int>>& edges, int node)
{
	if (visit[node] == true)
	{
		return false;
	}
	visit[node] = true;

	for (int i = 0; i < edges[node].size(); i++)
	{
		DfsEgde(visit, edges, edges[node][i]);
	}

	return true;
}

bool DfsBackTracking()
{
	//탈출부(리턴필요)

	//중복 예외처리

	//만족했을때
	//방문 처리
	//재귀
	//방문 해제

	return true;
}

int BfsMap(vector<vector<int>>& vMap, int nX, int nY)
{
	int nCount = 0;
	int nSizeX = vMap.size();
	int nSizeY = vMap[0].size();

	queue<pair<int, int>> qPoint;
	qPoint.push(pair<int, int>(nX, nY));

	while (qPoint.empty() == false)
	{
		const int nNowX = qPoint.front().first;
		const int nNowY = qPoint.front().second;
		const int nValue = vMap[nNowX][nNowY];
		qPoint.pop();

		//이동패턴 정의 (상하좌우)
		int nMoveX[4] = { 0, 0, 1, -1 };
		int nMoveY[4] = { 1, -1, 0, 0 };

		//이동할 수 있는 곳은 이동
		for (int i = 0; i < 4; i++)
		{
			int nPosX = nNowX + nMoveX[i];
			int nPosY = nNowY + nMoveY[i];

			//범위 및 방문 예외처리
			if (nPosX >= 0 && nPosX < nSizeX && nPosY >= 0 && nPosY < nSizeY && vMap[nPosX][nPosY] == 0)
			{
				//조건
				++nCount;
				vMap[nPosX][nPosY] = 2;
				qPoint.push(pair<int, int>(nPosX, nPosY));
			}
		}
	}

	return nCount;
}

int BfsEgde(vector<int>& visit, const vector<vector<int>>& edges, int start, int target)
{
	using node = pair<int, int>;
	int nCount(0);

	queue<node> qNode;
	qNode.push(node(start, nCount));
	visit[start] = true;

	while (qNode.empty() == false)
	{
		const int nNowNode = qNode.front().first;
		const int nDist = qNode.front().second;
		qNode.pop();

		//목적지인지 확인
		if (nNowNode == target)
		{
			nCount = nDist;
			break;
		}

		//이동할 수 있는 곳은 이동
		for (auto& nTargetNode : edges[nNowNode])
		{
			if (visit[nTargetNode] == false)
			{
				visit[nTargetNode] = true;
				qNode.push(node(nTargetNode, nDist + 1));
			}
		}
	}

	return nCount;
}