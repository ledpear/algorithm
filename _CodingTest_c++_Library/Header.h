#pragma once
#include "Source.cpp"

//custum function
//�ִܰ��
struct DijkstraCompare;
vector<int> Dijkstra(int nNodeSize, int nEdgeSize, int nTarget, vector<vector<p>> vEgde);
vmap FloydWarshall(const vmap vMap);

//DFS
bool DFS(const vmap& vMap, vmap& vVisit, int nX, int nY);

//Print
void PrintMap(const vmap& vMap);


//custum Class
//��Ʈ����ŷ
class BinaryNum;