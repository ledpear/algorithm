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
	vector<vector<string>> clothes;
	int answer = 0;
#define close_name 0
#define close_type 1

	vector<string> temp;
	temp.push_back("1");
	temp.push_back("headgear1");
	clothes.push_back(temp);
	temp.clear();

	temp.push_back("1");
	temp.push_back("headgear1");
	clothes.push_back(temp);
	temp.clear();

	temp.push_back("1");
	temp.push_back("headgear2");
	clothes.push_back(temp);
	temp.clear();

	temp.push_back("1");
	temp.push_back("headgear2");
	clothes.push_back(temp);
	temp.clear();

	temp.push_back("1");
	temp.push_back("headgear3");
	clothes.push_back(temp);
	temp.clear();

	temp.push_back("1");
	temp.push_back("headgear3");
	clothes.push_back(temp);
	temp.clear();

	temp.push_back("1");
	temp.push_back("headgear3");
	clothes.push_back(temp);
	temp.clear();

	temp.push_back("1");
	temp.push_back("headgear4");
	clothes.push_back(temp);

	
	map<string, int> MapClothesType;
	std::map<string, int>::iterator iter;

	for (int i = 0; i < clothes.size(); i++)
	{
		iter = MapClothesType.find(clothes[i][close_type]);
		if (iter == MapClothesType.end())
		{
			MapClothesType.insert(make_pair(clothes[i][close_type], 1));
		}
		else
		{
			MapClothesType[clothes[i][close_type]]++;
		}
	}

	int sum = 1;
	for (iter = MapClothesType.begin(); iter != MapClothesType.end(); ++iter)
	{
		int num = iter->second + 1;
		sum *= num;
	}

	return sum - 1;

	vector<int> Sum_int;
	vector<int> Double_Sum_int;
	for (int i = 0; i < MapClothesType.size() - 1; i++)
	{
		if(i == 0)
			Sum_int.push_back(1);
		else
			Sum_int.push_back(Sum_int[i - 1] + (i + 1));

		if (i == 0)
			Double_Sum_int.push_back(1);
		else
			Double_Sum_int.push_back(Double_Sum_int[i - 1] + Sum_int[i]);
	}

	int nCount = 0;
	for (int i = 0; i < MapClothesType.size(); i++)
	{
		if (i == 0)
			nCount += clothes.size();
		else
		{
			int nCase = 1;
			int nCaseB = 1;

			for (int a = 0; a <= i; a++)
			{
				nCase *= (MapClothesType.size() - a);
			}
			for (int b = 0; b <= i - 1; b++)
			{
				nCaseB *= ((MapClothesType.size()-1) - b);
			}
			nCase /= Sum_int[i];
			nCaseB /= Sum_int[i - 1];






			nCount += nCase * nCaseB * clothes.size();
		}
	}
	//1,2,3,4
// 	for (int i = 0; i < MapClothesType.size(); i++)
// 	{
// 		if (i == 0)
// 			nCount += clothes.size();
// 		else if(i == 1)
// 		{
// 			int countx = 1;
// 
// 			for (std::map<string, int>::iterator it = MapClothesType.begin(); it != MapClothesType.end(); ++it)
// 				countx *= it->second;
// 			nCount += Double_Sum_int[MapClothesType.size() - i - 1] * countx * Sum_int[MapClothesType.size() - i - 1];
// 		}
// 	}

	system("pause");
	return answer;
}