// CodingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int ZigZagRow(int pos, int numRows)
{
	int ZeroPosition = numRows + numRows - 2;	//���� ���

	if (ZeroPosition == 0)	return 0;			//0�̸� ������ ���� ������ ����ó��

	int Remaninder = pos % ZeroPosition;		//������ �� ���

	if (Remaninder < numRows)					//������ ���� numRows���� ������ ������α� ������ ������ �� ��ȯ
	{
		return Remaninder;
	}
	else										//������ ���� numRows���� ũ�ų� ������ �����̱� ������ ����Ͽ� ��ȯ
	{
		return ZeroPosition - Remaninder;
	}
}

int main()
{
	string s = "PAYPALISHIRING";
	int numRows = 2;

	string answer = "";
	vector<string> Zigzag(numRows, "");

	for (int i = 0; i < s.size(); i++)
	{
		Zigzag[ZigZagRow(i, numRows)] += s[i];	//�־��� ���ڿ��� ������� Row�� ����Ͽ� ����
	}

	for (int i = 0; i < Zigzag.size(); i++)
	{
		answer += Zigzag[i];					//������ Row�� ���ڿ��� ������
	}

    return 0;
}

