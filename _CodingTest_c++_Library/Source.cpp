//#include "Header.h"

#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;

//define
#define DEF_MIN -2147483648
#define DEF_MAX 2147483647

typedef unsigned long long ull;
typedef pair<ull, ull> p;
typedef vector<vector<int>> vmap;

//custum function
//template <typename T>

struct DijkstraCompare
{
	bool operator()(p a, p b)	//Node, W
	{
		return a.second > b.second;
	}
};

 vector<int> Dijkstra(int nNodeSize, int nEdgeSize, int nTarget, vector<vector<p>> vEgde)
 {
 	vector<int> vResult(nNodeSize + 1, DEF_MAX);
 	priority_queue<p, vector<p>, DijkstraCompare> pq; //(nNode, nW)
 
 	pq.push(p(nTarget, 0));
 	vResult[nTarget] = 0;
 
 	while (!pq.empty())
 	{
 		int nNowNode, nNowCost;
 		nNowNode = pq.top().first;
 		nNowCost = pq.top().second;
 		pq.pop();
 
 		if (vResult[nNowNode] < nNowCost) continue;
 
 		for (int i = 0; i < vEgde[nNowNode].size(); i++)
 		{
 			int nTargetNode, nTargetCost;
 			nTargetNode = vEgde[nNowNode][i].first;
 			nTargetCost = vEgde[nNowNode][i].second;
 
 			if (vResult[nTargetNode] > nNowCost + nTargetCost)
 			{
 				vResult[nTargetNode] = nNowCost + nTargetCost;
 				pq.push(p(nTargetNode, vResult[nTargetNode]));
 			}
 		}
 	}
 
 	return vResult;
 }

 vmap FloydWarshall(const vmap vMap)
 {
	 int nNodeSize = vMap.size();
	 vmap vResult = vMap;

	 for (int i = 0; i < nNodeSize; i++)
	 {
		 for (int j = 0; j < nNodeSize; j++)
		 {
			 for (int k = 0; k < nNodeSize; k++)
			 {
				 if (k != i && k != j && i != j && vResult[i][k] != DEF_MAX && vResult[k][j] != DEF_MAX)
				 {
					 if (vResult[i][j] > vResult[i][k] + vResult[k][j])
					 {
						 vResult[i][j] = vResult[i][k] + vResult[k][j];
					 }
				 }
			 }
		 }
	 }

	 return vResult;
 }

 class BinaryNum
 {
 public:
	 BinaryNum(int nDec = 0)
	 {
		 clear();
		 nDecNumber = nDec;

		 if (nDec == 0)
		 {
			 vBinNumber.push_back(0);
			 strNumber += '0';
			 return;
		 }

		 while (nDec > 0)
		 {
			 vBinNumber.push_back(nDec % 2);
			 strNumber = to_string(vBinNumber.back()) + strNumber;
			 nDec /= 2;
		 }
	 }

	 BinaryNum& operator=(int nDec)
	 {
		 clear();
		 nDecNumber = nDec;

		 if (nDec <= 0)
		 {
			 vBinNumber.push_back(0);
			 strNumber += '0';
		 }
		 else
		 {
			 while (nDec > 0)
			 {
				 vBinNumber.push_back(nDec % 2);
				 strNumber = to_string(vBinNumber.back()) + strNumber;
				 nDec /= 2;
			 }
		 }

		 return *this;
	 }

	 int getDec() { return nDecNumber; }
	 vector<bool> getBin() { return vBinNumber; }
	 string getString() { return strNumber; }

 protected:
 private:
	 vector<bool> vBinNumber;
	 int nDecNumber;
	 string strNumber;

	 void clear()
	 {
		 nDecNumber = 0;
		 vBinNumber.clear();
		 strNumber = "";
	 }
 };

 void PrintMap(const vmap& vMap)
 {
	 int nSizeX = vMap.size();
	 int nSizeY = vMap[0].size();

	 for (int i = 0; i < nSizeX; i++)
	 {
		 for (int j = 0; j < nSizeY; j++)
			 cout << vMap[i][j] << ' ';
		 cout << '\n';
	 }
 }

 bool DfsMap(const vmap& vMap, vmap& vVisit, int nX, int nY)
 {
	 //방문처리
	 if (vVisit[nX][nY] == true) return false;
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
				 DFS(vMap, vVisit, nPosX, nPosY);
			 }
		 }
	 }
	 return true;
 }

 bool DfsEgde(vector<int>& vVisit, const vector<vector<int>>& vEdge, int nNode)
 {
	 if (vVisit[nNode] == true) return false;
	 vVisit[nNode] = true;

	 for (int i = 0; i < vEdge[nNode].size(); i++)
	 {
		 DfsEgde(vVisit, vEdge, vEdge[nNode][i]);
	 }

	 return true;
 }

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration


	//Input


	//Solution


	//Output


	////////////////////////////////////
	system("pause");
	return 0;
}