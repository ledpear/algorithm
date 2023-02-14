#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//define

using ull = unsigned long long;
using location = pair<int, int>;
using matrix = vector<vector<int>>;

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
	bool operator()(location a, location b)	//Node, W
	{
		return a.second > b.second;
	}
};

 vector<int> Dijkstra(int nNodeSize, int nEdgeSize, int nTarget, vector<vector<location>> vEgde)//��� ����, ���� ����, ��������, ���(1��)�� ����� ����(2��)
 {
 	vector<int> vResult(nNodeSize + 1, INT_MAX);
	//�켱���� ť(��������)
 	priority_queue<location, vector<location>, DijkstraCompare> pq; //(nNode, nW) : (���, ����ġ)
 
	//���� ��� ����
 	pq.push(location(nTarget, 0));
 	vResult[nTarget] = 0;
 
 	while (!pq.empty())
 	{
		int nNowNode = pq.top().first;
		int nNowCost = pq.top().second;
 		pq.pop();
 
		//����Ǿ��ִ� ����ġ�� ť�� ����� ������ ũ�ٸ� �Ѿ��
		if (vResult[nNowNode] < nNowCost)
		{
			continue;
		}
 
		//����ġ ����
 		for (int i = 0; i < vEgde[nNowNode].size(); i++)
 		{
			//���ļ� �� �� �������� ����ġ
			int nTargetNode = vEgde[nNowNode][i].first;
			int nTargetCost = vEgde[nNowNode][i].second;
 
			//����Ǿ� �ִ� ����ġ���� ���� ��带 ���ļ� ������ �� ���ٸ� ����
 			if (vResult[nTargetNode] > nNowCost + nTargetCost)
 			{
 				vResult[nTargetNode] = nNowCost + nTargetCost;
 				pq.push(location(nTargetNode, vResult[nTargetNode]));
 			}
 		}
 	}
 
 	return vResult;
 }

 matrix FloydWarshall(const matrix vMap)
 {
	 int nNodeSize = vMap.size();
	 matrix vResult = vMap;

	 for (int i = 0; i < nNodeSize; i++)
	 {
		 for (int j = 0; j < nNodeSize; j++)
		 {
			 for (int k = 0; k < nNodeSize; k++)
			 {
				 if (k != i && k != j && i != j && ( vResult[i][k] != INT_MAX ) && ( vResult[k][j] != INT_MAX ) )
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

 void PrintMap(const matrix& vMap)
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

 bool DfsMap(const matrix& vMap, matrix& vVisit, int nX, int nY)
 {
	 //�湮ó��
	 if (vVisit[nX][nY] == true)
	 {
		 return false;
	 }
	 vVisit[nX][nY] = true;

	 //ũ�� ����
	 int nSizeX = vMap.size();
	 int nSizeY = vMap[0].size();

	 //�̵����� ����
	 int nMoveX[4] = { 0, 0, 1, -1 };
	 int nMoveY[4] = { 1, -1, 0, 0 };

	 //�̵��� �� �ִ� ���� �̵�
	 for (int i = 0; i < 4; i++)
	 {
		 int nPosX = nX + nMoveX[i];
		 int nPosY = nY + nMoveY[i];

		 //���� �� �湮 ����ó��
		 if (nPosX >= 0 && nPosX < nSizeX && nPosY >= 0 && nPosY < nSizeY && vVisit[nPosX][nPosY] == false)
		 {
			 //����
			 int nPosValue = vMap[nPosX][nPosY];
			 if (nPosValue != 0)
			 {
				 DfsMap(vMap, vVisit, nPosX, nPosY);
			 }
		 }
	 }
	 return true;
 }

 bool DfsEgde(vector<int>& vVisit, const vector<vector<int>>& vEdge, int nNode)
 {
	 if (vVisit[nNode] == true)
	 {
		 return false;
	 }
	 vVisit[nNode] = true;

	 for (int i = 0; i < vEdge[nNode].size(); i++)
	 {
		 DfsEgde(vVisit, vEdge, vEdge[nNode][i]);
	 }

	 return true;
 }

 int BfsMap(matrix& vMap, int nX, int nY)
 {
	 int nCount = 0;
	 int nSizeX = vMap.size();
	 int nSizeY = vMap[0].size();

	 queue<location> qPoint;
	 qPoint.push(location(nX, nY));

	 while (qPoint.empty() == false)
	 {
		 const int nNowX = qPoint.front().first;
		 const int nNowY = qPoint.front().second;
		 const int nValue = vMap[nNowX][nNowY];
		 qPoint.pop();

		 //�̵����� ����
		 int nMoveX[4] = { 0, 0, 1, -1 };
		 int nMoveY[4] = { 1, -1, 0, 0 };

		 //�̵��� �� �ִ� ���� �̵�
		 for (int i = 0; i < 4; i++)
		 {
			 int nPosX = nNowX + nMoveX[i];
			 int nPosY = nNowY + nMoveY[i];

			 //���� �� �湮 ����ó��
			 if (nPosX >= 0 && nPosX < nSizeX && nPosY >= 0 && nPosY < nSizeY && vMap[nPosX][nPosY] == 0)
			 {
				 //����
				 ++nCount;
				 vMap[nPosX][nPosY] = 2;
				 qPoint.push(location(nPosX, nPosY));
			 }
		 }
	 }

	 return nCount;
 }

 int BfsEgde(vector<int>& vVisit, const vector<vector<int>>& vEdges, int nStart, int nTarget)
 {
	 using node = pair<int, int>;
	 int nCount(0);

	 queue<node> qNode;
	 qNode.push(node(nStart, nCount));
	 vVisit[nStart] = true;

	 while (qNode.empty() == false)
	 {
		 const int nNowNode = qNode.front().first;
		 const int nDist = qNode.front().second;
		 qNode.pop();

		 //���������� Ȯ��
		 if (nNowNode == nTarget)
		 {
			 nCount = nDist;
			 break;
		 }

		 //�̵��� �� �ִ� ���� �̵�
		 for (auto& nTargetNode : vEdges[nNowNode])
		 {
			 if (vVisit[nTargetNode] == false)
			 {
				 vVisit[nTargetNode] = true;
				 qNode.push(node(nTargetNode, nDist + 1));
			 }
		 }
	 }

	 return nCount;
 }

 vector<string> parsing(const string& data, const char delimiter = ' ') 
 {
	 vector<string> result;
	 string token;
	 stringstream splitStream(data);

	 while (getline(splitStream, token, delimiter)) {
		 result.push_back(token);
	 }
	 return result;
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