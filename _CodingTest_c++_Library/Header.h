#pragma once
#include "Source.cpp"

//custum function
//�ִܰ��
struct DijkstraCompare;
vector<int> Dijkstra(int nNodeSize, int nEdgeSize, int nTarget, vector<vector<p>> vEgde);
vmap FloydWarshall(const vmap vMap);

//DFS
bool DfsMap(const vmap& vMap, vmap& vVisit, int nX, int nY);
bool DfsEgde(vector<int>& vVisit, const vector<vector<int>>& vEdge, int nNode)

//Print
void PrintMap(const vmap& vMap);


//custum Class
//��Ʈ����ŷ
class BinaryNum;