// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

class qHeap
{
public:
	qHeap() {}
	~qHeap() {}

	int GetSize() { return vHeap.size(); }

	int GetMax();
	int GetMin();

	void Push(int nInput);
	void PopMax();
	void PopMin();

	void SetSort(int topPosition, int position);

	vector<int> vHeap;
	
};

void qHeap::PopMax()
{
	if(vHeap.size() != 0)
		vHeap.erase(vHeap.begin());
}

void qHeap::PopMin()
{
	if (vHeap.size() != 0)
		vHeap.erase(vHeap.begin() + (vHeap.size() - 1));
}

int qHeap::GetMax()
{
	if (vHeap.size() == 0)
		return 0;
	else
		return vHeap[0];
}

int qHeap::GetMin()
{
	if (vHeap.size() == 0)
		return 0;
	else
		return vHeap[vHeap.size() - 1];
}

void qHeap::SetSort(int topPosition, int position)
{
	int pos = position;
	int temp = vHeap[position];

	while (true)
	{
		if (topPosition == pos)
		{
			vHeap[pos] = temp;
			break;
		}
		else if (vHeap[pos - 1] < temp)
		{
			vHeap[pos] = vHeap[pos - 1];
			--pos;
		}
		else
		{
			vHeap[pos] = temp;
			break;
		}
	}
}

void qHeap::Push(int nInput)
{
	vHeap.push_back(nInput);

	int position = vHeap.size() - 1;
	int ParentPosition;

	while (position != 0)
	{
		int nLog = log2(position + 1);

		ParentPosition = pow(2, nLog) - 2;

		//ParentPosition = (position - 1) / 2;

		if (vHeap[ParentPosition] < vHeap[position])
		{
			int temp = vHeap[ParentPosition];
			vHeap[ParentPosition] = vHeap[position];
			vHeap[position] = temp;

			SetSort(ParentPosition + 1, position);

			position = ParentPosition;
		}
		else
		{
			SetSort(ParentPosition + 1, position);
			break;
		}
	}
}


int main()
{
	int nLast = -1;
	vector<string> operations = { "I 7", "I 5", "I -5","D -1" };
	vector<int> answer;


	qHeap heap;

	for (int i = 0; i < operations.size(); i++)
	{
		string temp = operations[i].substr(2);
		int num = atoi(temp.c_str());

		if (operations[i][0] == 'I')
		{
			heap.Push(num);
		}
		else
		{
			if (num == 1)
			{
				heap.PopMax();
			}
			else
				heap.PopMin();
		}
	}
	
	answer.push_back(heap.GetMax());
	answer.push_back(heap.GetMin());

    return 0;
}

