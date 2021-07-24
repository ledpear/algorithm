#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//define

using ull = unsigned long long ;
using location =  pair<int, int> ;
using matrix = vector<vector<int>>;

//custum function

vector<int> getPiArr(string subStr) 
{
	int size(subStr.size());
	vector<int> piArr(size);

	int index = 1;

	int sameCount = 0;

	while (index < size)
	{
		if (subStr[index] == subStr[sameCount])
		{
			++sameCount;
			piArr[index] = sameCount;
			++index;
		}
		else if (sameCount != 0)
		{
			sameCount = piArr[sameCount - 1];
		}
		else
		{
			++index;
		}
	}

	return piArr;
}

string solution(string mainStr, string subStr)
{
	int mainSize = mainStr.size();
	int subSize = subStr.size();

	//vector<int> subPiArr = getPiArr(subStr);
	vector<int> mainPiArr(mainSize + 1);
	//main�� ������ result�� ��ź�� �������� �ε����� �̵���Ű�� ������ �ӵ��� ����Ų��.
	string resultStr(mainStr);
	int mainIndex(0), subIndex(0), resultIndex(0);

	while (mainIndex < mainSize)
	{
		if (mainStr[mainIndex] == subStr[subIndex])
		{
			//�ε����� �޶������� �����ұ�?
			resultStr[resultIndex] = mainStr[mainIndex];
			++resultIndex;
			++subIndex;
			++mainIndex;
			mainPiArr[mainIndex] = subIndex;

			if (subIndex == subSize)
			{
				//resultStr = resultStr.substr(0, resultStr.size() - subSize);
				//subIndex = subPiArr[subIndex - 1];
				
				//����� ��ġ������ ����
				subIndex = mainPiArr[resultIndex - subSize];
				//��ź�� ������ sub�� ũ�⸸ŭ ���ش�
				resultIndex -= subSize;
			}
		}
		else if (subIndex != 0)
		{
			//subIndex = subPiArr[subIndex - 1];
// 			int backPos = mainIndex - subSize - 1;
// 			if (backPos >= 0)
// 			{
// 				subIndex = mainPiArr[mainIndex - subSize - 1];
// 			}
// 			else
// 			{
// 				subIndex = 0;
// 			}
			subIndex = 0;
		}
		else
		{
			//resultStr += mainStr[mainIndex];
			resultStr[resultIndex] = mainStr[mainIndex];
			++resultIndex;
			++mainIndex;
		}
	}

	return resultStr.substr(0, resultIndex);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	string inputStr(""), bombStr("");
	cin >> inputStr;
	cin >> bombStr;

	//Solution
	string resultStr = solution(inputStr, bombStr);


	//Output
	if (resultStr.size() != 0)
	{
		cout << resultStr << '\n';
	}
	else
	{
		cout << "FRULA\n";
	}

	////////////////////////////////////
	system("pause");
	return 0;
}