#pragma once
#include "Source.cpp"

//custum function
//최단경로
struct DijkstraCompare;
vector<int> Dijkstra(int nNodeSize, int nEdgeSize, int nTarget, vector<vector<p>> vEgde);
vmap FloydWarshall(const vmap vMap);

//DFS
bool DfsMap(const vmap& vMap, vmap& vVisit, int nX, int nY);
bool DfsEgde(vector<int>& vVisit, const vector<vector<int>>& vEdge, int nNode)

//Print
void PrintMap(const vmap& vMap);


//custum Class
//비트마스킹
class BinaryNum;