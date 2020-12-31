// CodingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


int main()
{
	ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
	ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

	int num1 = 0;
	int num2 = 0;
	ListNode *answer = new ListNode();
	ListNode *temp1, *temp2, *AnswerTemp;
	temp1 = l1;
	temp2 = l2;
	AnswerTemp = answer;
	int count = 0;

	bool bVal1, bVal2;
	bVal1 = true;
	bVal2 = true;

	bool UpPoint = false;
	int sum;

	while (true)
	{
		//초기화
		sum = 0;
		num1 = 0;
		num2 = 0;
		//List 1
		if (bVal1)
		{
			num1 = temp1->val;
			temp1 = temp1->next;
			if (temp1 == NULL)
				bVal1 = false;
		}
		//List 2
		if (bVal2)
		{
			num2 = temp2->val;
			temp2 = temp2->next;
			if (temp2 == NULL)
				bVal2 = false;
		}
		//합 계산
		sum = num1 + num2;
		//올림수 덧셈
		if (UpPoint)
		{
			sum += 1;
			UpPoint = false;
		}
		//합한 값이 10 이상일때 올림수를 설정
		if (sum >= 10)
		{
			printf("%d : UpPoint\n", sum);
			sum -= 10;
			UpPoint = true;
		}

		//값 설정
		AnswerTemp->val = sum;

		if (!bVal1 && !bVal2)
		{
			//두 수가 마지막 노드 일때 올림수가 있으면 처리
			if (UpPoint)
			{
				AnswerTemp->next = new ListNode(1);
			}
			break;
		}

		//노드 추가
		AnswerTemp->next = new ListNode();
		AnswerTemp = AnswerTemp->next;

		++count;
	}

    return 0;
}

