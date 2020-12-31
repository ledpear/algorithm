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

	int nTotal = nums1.size() + nums2.size();	// 전체 크기 계산
	bool bEven = nTotal % 2 == 0;	//짝수인지 판단

	int nNumPos1 = 0;
	int nNumPos2 = 0;

	vector<int> vTotal;
	while (true)
	{
		if (nNumPos1 == nums1.size())	//num1배열을 모두 순회하였을 때
		{
			vTotal.push_back(nums2[nNumPos2++]);
		}
		else if (nNumPos2 == nums2.size())	//num2배열을 모두 순회하였을 때
		{
			vTotal.push_back(nums1[nNumPos1++]);
		}
		else if (nums1[nNumPos1] <= nums2[nNumPos2])	//num1이 더 작을 때
		{
			vTotal.push_back(nums1[nNumPos1++]);
		}
		else if (nums1[nNumPos1] > nums2[nNumPos2])		//num2가 더 작을 때
		{
			vTotal.push_back(nums2[nNumPos2++]);
		}

		//중앙값을 얻으면 반복문 종료
		//홀수 일 땐 nTotal / 2 + 1 중앙 값이 맞고
		//짝수 일때도 중앙에 해당하는 두 숫자를 얻어야하기 때문에 nTotal / 2 + 1 만큼 순회
		if (vTotal.size() >= nTotal / 2 + 1)
			break;
	}

	double answer = 0;

	//짝수 홀수에 따라 반환값 계산
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

