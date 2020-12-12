// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int nLast = -1;
	vector<int> numbers = { 1,3,4,5,8,2,1,4,5,9,5 };
	string hand = "right";
	string answer = "";

	int LeftHand = 10;
	int RightHand = 12;

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
		{
			answer += 'L';
			LeftHand = numbers[i];
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
		{
			answer += 'R';
			RightHand = numbers[i];
		}
		else
		{
			if (numbers[i] == 0)
				numbers[i] = 11;

			int Left_X, Left_Y, Right_X, Right_Y, Number_X, Number_Y;
			int Left_Move, Right_Move;

			Left_X = (LeftHand - 1) % 3;
			Left_Y = (LeftHand - 1) / 3;
			Right_X = (RightHand - 1) % 3;
			Right_Y = (RightHand - 1) / 3;
			Number_X = (numbers[i] -1) % 3;
			Number_Y = (numbers[i] - 1) / 3;

			Left_Move = abs(Number_X - Left_X) + abs(Number_Y - Left_Y);
			Right_Move = abs(Number_X - Right_X) + abs(Number_Y - Right_Y);

			if (Left_Move < Right_Move)
			{
				answer += 'L';
				LeftHand = numbers[i];
			}
			else if (Left_Move > Right_Move)
			{
				answer += 'R';
				RightHand = numbers[i];
			}
			else
			{
				if (hand == "left")
				{
					answer += 'L';
					LeftHand = numbers[i];
				}
				else if (hand == "right")
				{
					answer += 'R';
					RightHand = numbers[i];
				}
			}
		}
	}

    return 0;
}

