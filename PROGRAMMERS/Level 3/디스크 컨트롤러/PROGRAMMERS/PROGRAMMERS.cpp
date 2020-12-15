// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//0 : ��û�� �ð�
//1 : �۾��ð�
//2 : ������
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
//���� Ȱ���� Ǯ�̹�
//1. �ð��� 1�����ؼ� ����
//2. ���μ��� ��û �ð����� ���ĵǾ��ִ� ���� �迭���� ó������ ������ ������� ����
//3. ���� �ð��� ��û�� �ð��� ��ġ�ϸ� ���� �߰�
//4. ��ȯ�� ���μ����� ������ ����� ��ġ�ϸ� ����
//5. ���� �ִ������� �ۼ��ؼ�
//6. �� ũ�⸦ ���� �� �� �ֳ�? -> �������� �õ�
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

	//��û �ð� ����
	sort(jobs.begin(), jobs.end(), RequestCompare);

	//�۾��ð� ����
// 	vector<vector<int>> Work_Sort = Request_Sort;
// 	sort(Work_Sort.begin(), Work_Sort.end(), WorkCompare);
// 
// 	//�۾� �Ϸ��Ѱ��� Ȯ���ϴ� bool�迭
// 	vector<bool> bWorked(Work_Sort.size(), false);

	//�� ����
	//������ job ������� 

	//��û �ð� ������ ����
	//�۾� �ð� ������ ����
	//�۾� �Ϸ��Ѱ��� Ȯ���ϴ� bool�迭
	//1.�۾����� ���μ����� ������ �۾��ð������� �迭���� �ش� ���μ����� �����ߴ��� Ȯ��(�ð��� �Ѿ�����)
	//2.�����ߴٸ� ���μ��� �����ϰ� 1�� �ƴ϶�� ��û �ð� ���� �迭���� Ž��
	
	//��û�� �ð� ������ ���� ���μ��� Ž��

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

