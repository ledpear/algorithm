// CodingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> nums1;
	vector<int> nums2;

	int nTotal = nums1.size() + nums2.size();	// ��ü ũ�� ���
	bool bEven = nTotal % 2 == 0;	//¦������ �Ǵ�

	int nNumPos1 = 0;
	int nNumPos2 = 0;

	vector<int> vTotal;
	while (true)
	{
		if (nNumPos1 == nums1.size())	//num1�迭�� ��� ��ȸ�Ͽ��� ��
		{
			vTotal.push_back(nums2[nNumPos2++]);
		}
		else if (nNumPos2 == nums2.size())	//num2�迭�� ��� ��ȸ�Ͽ��� ��
		{
			vTotal.push_back(nums1[nNumPos1++]);
		}
		else if (nums1[nNumPos1] <= nums2[nNumPos2])	//num1�� �� ���� ��
		{
			vTotal.push_back(nums1[nNumPos1++]);
		}
		else if (nums1[nNumPos1] > nums2[nNumPos2])		//num2�� �� ���� ��
		{
			vTotal.push_back(nums2[nNumPos2++]);
		}

		//�߾Ӱ��� ������ �ݺ��� ����
		//Ȧ�� �� �� nTotal / 2 + 1 �߾� ���� �°�
		//¦�� �϶��� �߾ӿ� �ش��ϴ� �� ���ڸ� �����ϱ� ������ nTotal / 2 + 1 ��ŭ ��ȸ
		if (vTotal.size() >= nTotal / 2 + 1)
			break;
	}

	double answer = 0;

	//¦�� Ȧ���� ���� ��ȯ�� ���
	if (bEven)
		answer = (double)(vTotal[vTotal.size() - 1] + vTotal[vTotal.size() - 2]) / 2;
	else
		answer = vTotal[vTotal.size() - 1];

	return answer;

	lambda[]int test = [](int x) {
		return x + 10;
	}

    return 0;
}

