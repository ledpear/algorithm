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

int main()
{
	int nLast = -1;
	vector<vector<int>> jobs = { {0, 3},{4, 9},{5, 6} };
	int answer = 0;

	int nSize = jobs.size();

	//요청 시간 정렬
	vector<vector<int>> Request_Sort = jobs;
	sort(Request_Sort.begin(), Request_Sort.end(), RequestCompare);
	for (int i = 0; i < Request_Sort.size(); i++)
	{
		Request_Sort[i].push_back(i);
	}

	//작업시간 정렬
	vector<vector<int>> Work_Sort = Request_Sort;
	sort(Work_Sort.begin(), Work_Sort.end(), WorkCompare);

	//작업 완료한건지 확인하는 bool배열
	vector<bool> bWorked(Work_Sort.size(), false);

	//힙 구현
	//정렬한 job 순서대로 

	//요청 시간 정렬한 벡터
	//작업 시간 정렬한 벡터
	//작업 완료한건지 확인하는 bool배열
	//1.작업중인 프로세스가 없으면 작업시간정렬한 배열에서 해당 프로세스가 도착했는지 확인(시간이 넘었는지)
	//2.도착했다면 프로세스 진행하고 1로 아니라면 요청 시간 정렬 배열에서 탐색
	
	//요청한 시간 순서로 다음 프로세스 탐색

	int nTime = 0;
	int nRequestPosition = 0;
	int nWorkPosition = 0;
	int nTotal = 0;

	while (true)
	{
		//만약에 처리한 작업일때 예외처리 해야함
		if (nTime >= Work_Sort[nWorkPosition][eRequest])
		{
			if (bWorked[Work_Sort[nWorkPosition][ePosition]])
			{
				nWorkPosition++;										//포지션 위치 증가
			}
			else
			{
				nTime += Work_Sort[nWorkPosition][eWork];				//시간 진행
				bWorked[Work_Sort[nWorkPosition][ePosition]] = true;	//작업 체크
				nTotal += (nTime - Work_Sort[nWorkPosition][eRequest]);	//토탈시간 계산

				nWorkPosition++;										//포지션 위치 증가
			}

			if(nWorkPosition >= nSize) break;						//예외처리
		}
		else if (nTime >= Request_Sort[nRequestPosition][eRequest])
		{
			if (bWorked[Request_Sort[nRequestPosition][ePosition]])
			{
				nRequestPosition++;										//포지션 위치 증가
			}
			else
			{
				nTime += Request_Sort[nRequestPosition][eWork];
				bWorked[Request_Sort[nRequestPosition][ePosition]] = true;
				nTotal += (nTime - Request_Sort[nRequestPosition][eRequest]);

				nRequestPosition++;
			}

			if (nRequestPosition >= nSize) break;
		}
		else
		{
			nTime = Request_Sort[nRequestPosition][eRequest];
		}
	}

	answer = nTotal / nSize;

    return 0;
}

