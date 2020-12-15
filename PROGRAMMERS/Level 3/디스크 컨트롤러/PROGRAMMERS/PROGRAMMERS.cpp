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

	void Compare(int nNodePos);

private:
	vector<vector<int>> vHeap;
};

pHeap::pHeap()
{
}

pHeap::~pHeap()
{
}

void pHeap::Compare(int nNodePos)
{
	if (nNodePos == 0)
		return;

	int ParentNode = nNodePos / 2;
	if (vHeap[ParentNode][eWork] < vHeap[nNodePos][eWork])
	{

	}
}

void pHeap::Push(vector<int> vNode)
{
	if (vHeap.size() == 0)
		vHeap.push_back(vNode);
	else
	{
		vHeap.push_back(vNode);
		int NodePos = vHeap.size() - 1;
		int ParentNode = NodePos / 2;

	}
}

int main()
{
	int nLast = -1;
	vector<vector<int>> jobs = { {4, 9},{ 4, 5 } ,{ 4, 1 } };
	int answer = 0;

	int nSize = jobs.size();

	//��û �ð� ����
	vector<vector<int>> Request_Sort = jobs;
	sort(Request_Sort.begin(), Request_Sort.end(), RequestCompare);
	for (int i = 0; i < Request_Sort.size(); i++)
	{
		Request_Sort[i].push_back(i);
	}

	//�۾��ð� ����
	vector<vector<int>> Work_Sort = Request_Sort;
	sort(Work_Sort.begin(), Work_Sort.end(), WorkCompare);

	//�۾� �Ϸ��Ѱ��� Ȯ���ϴ� bool�迭
	vector<bool> bWorked(Work_Sort.size(), false);

	//�� ����
	//������ job ������� 

	//��û �ð� ������ ����
	//�۾� �ð� ������ ����
	//�۾� �Ϸ��Ѱ��� Ȯ���ϴ� bool�迭
	//1.�۾����� ���μ����� ������ �۾��ð������� �迭���� �ش� ���μ����� �����ߴ��� Ȯ��(�ð��� �Ѿ�����)
	//2.�����ߴٸ� ���μ��� �����ϰ� 1�� �ƴ϶�� ��û �ð� ���� �迭���� Ž��
	
	//��û�� �ð� ������ ���� ���μ��� Ž��

	

	int nTime = 0;
	int nRequestPosition = 0;
	int nWorkPosition = 0;
	int nTotal = 0;

	while (true)
	{
		//���࿡ ó���� �۾��϶� ����ó�� �ؾ���
		if (nTime >= Work_Sort[nWorkPosition][eRequest])
		{
			if (bWorked[Work_Sort[nWorkPosition][ePosition]])
			{
				nWorkPosition++;										//������ ��ġ ����
			}
			else
			{
				nTime += Work_Sort[nWorkPosition][eWork];				//�ð� ����
				bWorked[Work_Sort[nWorkPosition][ePosition]] = true;	//�۾� üũ
				nTotal += (nTime - Work_Sort[nWorkPosition][eRequest]);	//��Ż�ð� ���

				nWorkPosition++;										//������ ��ġ ����
			}

			if(nWorkPosition >= nSize) break;						//����ó��
		}
		else if (nTime >= Request_Sort[nRequestPosition][eRequest])
		{
			if (bWorked[Request_Sort[nRequestPosition][ePosition]])
			{
				nRequestPosition++;										//������ ��ġ ����
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

