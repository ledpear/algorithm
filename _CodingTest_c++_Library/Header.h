#pragma once
#include "Source.cpp"

//custum function
//최단경로
struct DijkstraCompare;
vector<int> Dijkstra(int nNodeSize, int nEdgeSize, int nTarget, vector<vector<p>> vEgde);
vmap FloydWarshall(const vmap vMap);

//DFS
bool DFS(const vmap& vMap, vmap& vVisit, int nX, int nY);

//Print
void PrintMap(const vmap& vMap);


//custum Class
//비트마스킹
class BinaryNum;