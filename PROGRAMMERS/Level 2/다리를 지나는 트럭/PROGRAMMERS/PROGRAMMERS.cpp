// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int nLast = -1;

	//트럭의 길이는 1
	//다리의 길이 만큼 배열을 만들어서 반복처리
	//한가지 행동을 할때마다 ++

	int bridge_length = 2;
	int weight = 10;
	vector<int> truck_weights;
	truck_weights.push_back(7);
	truck_weights.push_back(4);
	truck_weights.push_back(5);
	truck_weights.push_back(6);

	int nTime = 0;
	int nPos = 0;
	int nBridge_Weigth = 0;
	int *nBridge = new int[bridge_length] {};
	int nPass = 0;

	while (true)
	{
		if (nBridge[bridge_length - 1] != 0	)// 나가는 부분
		{
			nPass++;
			nBridge_Weigth -= nBridge[bridge_length - 1];
		}			

		for (int i = bridge_length - 1; i > 0; --i)	//트럭 이동
		{
			nBridge[i] = nBridge[i - 1];
			if (i == 1)
				nBridge[0] = 0;
		}

		if (nPos < truck_weights.size())
		{
			if (nBridge_Weigth + truck_weights[nPos] <= weight)	//들어오는 부분
			{
				nBridge[0] = truck_weights[nPos];
				nBridge_Weigth += truck_weights[nPos++];
			}
		}

		nTime++;
		if (nPass == truck_weights.size())
			break;
	}

	delete[] nBridge;

    return 0;
}

