#pragma once
#include "Source.cpp"

//custum function
//정렬
struct HeapCompare;

//최단경로
struct DijkstraCompare;
vector<int> Dijkstra(int nNodeSize, int nEdgeSize, int nTarget, vector<vector<p>> vEgde);
vmap FloydWarshall(const vmap vMap);

//DFS
bool DfsMap(const vmap& vMap, vmap& vVisit, int nX, int nY);
bool DfsEgde(vector<int>& vVisit, const vector<vector<int>>& vEdge, int nNode)

//BFS
int BfsMap(vmap& vMap, int nX, int nY) //바뀐 영역의 수를 반환
int BfsEgde(vector<int>& vVisit, const vector<vector<int>>& vEdges, int nStart, int nTarget) // 목적지까지 최단 거리 계산

//Print
void PrintMap(const vmap& vMap);


//custum Class
//비트마스킹
class BinaryNum;