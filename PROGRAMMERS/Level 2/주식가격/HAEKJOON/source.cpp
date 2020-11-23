#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int prices[5] = { 1,2,3,4,5 };
	size_t prices_len = 5;
	int* answer = (int*)malloc(sizeof(int) * prices_len);

	for (int i = 0; i < prices_len; i++)
	{
		answer[i] = 0;
		for (int j = i + 1; j < prices_len; j++)
		{
			answer[i]++;
			if (prices[i] > prices[j])
				break;
		}
	}
	
	system("pause");
	return 0;
}