// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//0 : 요청한 시간
//1 : 작업시간
//2 : 포지션
enum
{
	eRequest = 0,
	eWork,
	ePosition,
	eMax
};

bool RequestCompare(vector<int> a, vector<int> b)
{
	return a[eRequest] < b[eRequest];
}

bool WorkCompare(vector<int> a, vector<int> b)
{
	return a[eWork] < b[eWork];
}

//////////////////////
//힙를 활용한 풀이법
//1. 시간은 1씩더해서 진행
//2. 프로세스 요청 시간으로 정렬되어있는 벡터 배열에서 처음부터 끝까지 순서대로 진행
//3. 지금 시간과 요청한 시간과 일치하면 힙에 추가
//4. 반환한 프로세스와 벡터의 사이즈가 일치하면 종료
//5. 힙은 최대힙으로 작성해서
//6. 힙 크기를 동적 할 수 있나? -> 동적으로 시도
class pHeap
{
public:
	pHeap();
	~pHeap();

	void Push(vector<int> vNode);
	vector<int> Pop();

	void CompareUP(int nNodePos);
	void CompareDOWN(int nNodePos);

	int GetSize();

private:
	vector<vector<int>> vHeap;
};

pHeap::pHeap()
{
	vector<int> temp(1);
	vHeap.push_back(temp);
}

pHeap::~pHeap()
{
}

void pHeap::CompareUP(int nNodePos)
{
	if (nNodePos == 1)
		return;

	int ParentNode = nNodePos / 2;
	if (vHeap[ParentNode][eWork] > vHeap[nNodePos][eWork])
	{
		vector<int> temp = vHeap[ParentNode];
		vHeap[ParentNode] = vHeap[nNodePos];
		vHeap[nNodePos] = temp;

		CompareUP(ParentNode);
	}
}

void pHeap::CompareDOWN(int nNodePos)
{
	if (nNodePos * 2 >= vHeap.size())
		return;

	int ParentNode = nNodePos / 2;
	if (vHeap[ParentNode][eWork] > vHeap[nNodePos][eWork])
	{
		vector<int> temp = vHeap[ParentNode];
		vHeap[ParentNode] = vHeap[nNodePos];
		vHeap[nNodePos] = temp;

		CompareDOWN(ParentNode);
	}
}

void pHeap::Push(vector<int> vNode)
{
	vHeap.push_back(vNode);
	int NodePos = vHeap.size() - 1;
	CompareUP(NodePos);
}

vector<int> pHeap::Pop()
{
	if (vHeap.size() > 1)
	{
		vector<int> temp = vHeap[1];

		vHeap[1] = vHeap[vHeap.size() - 1];
		vHeap.pop_back();

		return temp;
	}	
}

int pHeap::GetSize()
{
	return vHeap.size() - 1;
}

int main()
{
	int nLast = -1;
	vector<vector<int>> jobs = { {0, 3},{ 1, 9 } ,{ 2, 6 } };
	int answer = 0;

	int nSize = jobs.size();

	//요청 시간 정렬
	sort(jobs.begin(), jobs.end(), RequestCompare);

	//작업시간 정렬
// 	vector<vector<int>> Work_Sort = Request_Sort;
// 	sort(Work_Sort.begin(), Work_Sort.end(), WorkCompare);
// 
// 	//작업 완료한건지 확인하는 bool배열
// 	vector<bool> bWorked(Work_Sort.size(), false);

	//힙 구현
	//정렬한 job 순서대로 

	//요청 시간 정렬한 벡터
	//작업 시간 정렬한 벡터
	//작업 완료한건지 확인하는 bool배열
	//1.작업중인 프로세스가 없으면 작업시간정렬한 배열에서 해당 프로세스가 도착했는지 확인(시간이 넘었는지)
	//2.도착했다면 프로세스 진행하고 1로 아니라면 요청 시간 정렬 배열에서 탐색
	
	//요청한 시간 순서로 다음 프로세스 탐색

	int nTime = 0;
	pHeap Heap;
	int nPosition = 0;
	int nRunnigTime = 0;
	int nEnd = 0;
	int nTotal = 0;
	vector<int> vWork;

	while (true)
	{
		if (nPosition < nSize && jobs[nPosition][eRequest] == nTime)
		{
			if (nRunnigTime == 0)
			{
				vWork = jobs[nPosition];
				nRunnigTime = jobs[nPosition][eWork];
				nPosition++;
			}
			else
			{
				Heap.Push(jobs[nPosition]);
				nPosition++;
			}
		}

		if (nRunnigTime == 0 && !vWork.empty())
		{
			nTotal += nTime - vWork[eRequest];
			if (++nEnd == nSize)	break;

			vWork.clear();

			if (Heap.GetSize() != 0)
			{
				vWork = Heap.Pop();
				nRunnigTime = vWork[eWork];				
			}
		}

		nTime++;
		if (nRunnigTime > 0)
			nRunnigTime--;
	}

	answer = nTotal / nSize;

    return 0;
}

