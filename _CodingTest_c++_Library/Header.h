#pragma once
#include "Source.cpp"

//custum function
//����
struct HeapCompare;

//�ִܰ��
struct DijkstraCompare;
vector<int> Dijkstra(int nNodeSize, int nEdgeSize, int nTarget, vector<vector<p>> vEgde);
vmap FloydWarshall(const vmap vMap);

//DFS
bool DfsMap(const vmap& vMap, vmap& vVisit, int nX, int nY);
bool DfsEgde(vector<int>& vVisit, const vector<vector<int>>& vEdge, int nNode)

//BFS
int BfsMap(vmap& vMap, int nX, int nY) //�ٲ� ������ ���� ��ȯ
int BfsEgde(vector<int>& vVisit, const vector<vector<int>>& vEdges, int nStart, int nTarget) // ���������� �ִ� �Ÿ� ���

//Print
void PrintMap(const vmap& vMap);


//custum Class
//��Ʈ����ŷ
class BinaryNum;