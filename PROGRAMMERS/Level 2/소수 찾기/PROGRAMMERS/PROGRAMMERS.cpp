// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

 void MakeNumber(string numbers, vector<bool> bUse, vector<int> &MadeNumber, vector<bool> &bNumber, string strNumber)
 {
 	int num = stoi(strNumber);
 	if (bNumber[num] == false)
 	{
 		MadeNumber.push_back(num);
 		bNumber[num] = true;
 	}
 
 	for (int i = 0; i < numbers.size(); i++)
 	{
 		if (bUse[i] == false)
 		{
 			string strTemp = strNumber + numbers[i];
 			vector<bool> bTempUse = bUse;
 			bTempUse[i] = true;
 			MakeNumber(numbers, bTempUse, MadeNumber, bNumber, strTemp);
 		}
 	}
 }

int main()
{
	int nLast = -1;
	string numbers = "17";
	int answer = 0;
 
 	vector<bool> bNumber(100000000);
 	bNumber[0] = true;
 	//size가 숫자의 크기
 	//bool 배열로 해당 카드 사용했는지 확인
 
	vector<bool> PrimeNumber(100000000);
 	PrimeNumber[0] = true;
 	PrimeNumber[1] = true;
	int MaxSize = (int)pow(10, numbers.size() + 1);
	for (int i = 2; i < MaxSize; i++)
	{
		if (!PrimeNumber[i])
		{
			int nCount = 2;
			while (true)
			{
				if (i * nCount >= MaxSize)
					break;
				else if (PrimeNumber[i * nCount] == false)
					PrimeNumber[i*nCount++] = true;
				else
					nCount++;
			}
		}
	}

	vector<int> MadeNumber;

	for (int i = 0; i < numbers.size(); i++)
	{
		vector<bool> bUse(numbers.size());
		string strNumber = "";
		bUse[i] = true;
		strNumber += numbers[i];
		MakeNumber(numbers, bUse, MadeNumber, bNumber, strNumber);
	}

	for (int i = 0; i < MadeNumber.size(); i++)
	{
		if (PrimeNumber[MadeNumber[i]] == false)
			answer++;
	}

    return 0;
}

