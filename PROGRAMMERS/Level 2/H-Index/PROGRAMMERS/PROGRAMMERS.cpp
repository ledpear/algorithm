// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	vector<int> citations;
 	citations.push_back(3);
 	citations.push_back(0);
 	citations.push_back(6);
 	citations.push_back(1);
	citations.push_back(5);
/*	citations.push_back(5);*/

	int answer = 0;

	sort(citations.begin(), citations.end(), greater<>());


	//��ǥ�� �� �� n ����
	//h�� �̻� �ο�� ���� h�� �̻��̰�
	//������ ���� h�� ���� �ο�

	int nMax = -1;
	int nPos = -1;
	int i;
	for (i = 0; i < citations.size(); i++)
	{
		if (i >= citations[i])
		{
			break;
		}
	}
	answer = i;

	system("pause");
	return answer;
}

