// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int nLast = -1;

	//Ʈ���� ���̴� 1
	//�ٸ��� ���� ��ŭ �迭�� ���� �ݺ�ó��
	//�Ѱ��� �ൿ�� �Ҷ����� ++

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
		if (nBridge[bridge_length - 1] != 0	)// ������ �κ�
		{
			nPass++;
			nBridge_Weigth -= nBridge[bridge_length - 1];
		}			

		for (int i = bridge_length - 1; i > 0; --i)	//Ʈ�� �̵�
		{
			nBridge[i] = nBridge[i - 1];
			if (i == 1)
				nBridge[0] = 0;
		}

		if (nPos < truck_weights.size())
		{
			if (nBridge_Weigth + truck_weights[nPos] <= weight)	//������ �κ�
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

