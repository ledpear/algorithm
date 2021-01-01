// CodingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int ZigZagRow(int pos, int numRows)
{
	int ZeroPosition = numRows + numRows - 2;	//원점 계산

	if (ZeroPosition == 0)	return 0;			//0이면 나눌수 없기 때문에 예외처리

	int Remaninder = pos % ZeroPosition;		//나머지 값 계산

	if (Remaninder < numRows)					//나머지 값이 numRows보다 작으면 순서대로기 때문에 나머지 값 반환
	{
		return Remaninder;
	}
	else										//나머지 값이 numRows보다 크거나 같으면 역순이기 때문에 계산하여 반환
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
		Zigzag[ZigZagRow(i, numRows)] += s[i];	//주어진 문자열을 순서대로 Row를 계산하여 저장
	}

	for (int i = 0; i < Zigzag.size(); i++)
	{
		answer += Zigzag[i];					//저장한 Row별 문자열을 재조합
	}

    return 0;
}

