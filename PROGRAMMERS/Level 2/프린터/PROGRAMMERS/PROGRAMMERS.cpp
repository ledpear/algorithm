// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

struct LinkedList
{
	LinkedList * nPointer = nullptr;
	int nValue;
	int nPosition;
};

LinkedList *ListHead;
LinkedList *ListTail;
int ListMax;

void PushBack(int nValue, int nPositionSet = -1)
{
	LinkedList *TempList = new LinkedList;
	TempList->nValue = nValue;

	if (ListMax < nValue)
		ListMax = nValue;

	if (nPositionSet == -1)
		TempList->nPosition = ListTail->nPosition + 1;
	else
		TempList->nPosition = nPositionSet;

	ListTail->nPointer = TempList;
	ListTail = TempList;
}

LinkedList PopFront(LinkedList &list)
{
	LinkedList *tempPointer;
	tempPointer = &list;

	while (true)
	{
		if (tempPointer->nValue == ListMax)
		{
			ListHead = tempPointer;
			return *tempPointer;
		}
		else
		{
			tempPointer = tempPointer->nPointer;
		}
	}
}

int main()
{
	vector<int> priorities;
	priorities.push_back(1);
	priorities.push_back(1);
	priorities.push_back(9);
	priorities.push_back(1);
	priorities.push_back(1);
	priorities.push_back(1);
	int location = 0;

	int answer = 0;
	LinkedList list;
	list.nPosition = 0;
	list.nValue = priorities[0];
	ListMax = list.nValue;
	ListHead = &list;
	ListTail = &list;

	for (int i = 1; i < priorities.size(); i++)
	{
		PushBack(priorities[i]);
	}

	int nPrint = 1;
	while (true)
	{
		if (ListHead->nValue == ListMax && ListHead->nPosition == location)
			return nPrint;
		else if (ListHead->nValue == ListMax)
		{
			LinkedList * TempList = ListHead;
			ListHead = ListHead->nPointer;
			delete TempList;

			nPrint++;

			LinkedList * tempList = ListHead;
			ListMax = -1;
			while (true)
			{
				if (ListMax < tempList->nValue)
					ListMax = tempList->nValue;
				if (tempList->nPointer == nullptr)
					break;
				else
					tempList = tempList->nPointer;
			}
		}
		else
		{
			PushBack(ListHead->nValue, ListHead->nPosition);
			ListHead = ListHead->nPointer;
		}
	}



 	//LinkedList * tempList = ListHead;
 	//while (true)
 	//{
 	//	cout << tempList->nValue << endl;
 	//	if (tempList->nPointer == nullptr)
 	//		break;
 	//	else
 	//		tempList = tempList->nPointer;
 	//}

	system("pause");
    return 0;
}

