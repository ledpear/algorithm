#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

#include <map>
#include <functional>

int solution(int k, vector<int> tangerine) 
{
	//���� ���ڸ� count�ؼ� ���� ���� ������ �����Ѵ�
	//�ϳ��� count�� ���س����鼭 ���� k�� ������ �׶� �� ������ �����Ѵ�
	//map���� key�� ���� value�� count�� ��ȸ�ؼ� �����
	//vector�� �ٽ� ������ �����ؼ� ��ȸ�Ѵ�
	int answer = 0;
	map<int, int> tangerineMap;
	const int size = tangerine.size();
	for (int i = 0; i < size; ++i)
	{
		const int tangerineSize = tangerine.at(i);
		//�̹� �ִ� ���ڶ�� �����ش�
		if (tangerineMap.find(tangerineSize) != tangerineMap.end())
			++tangerineMap.at(tangerineSize);
		//���ٸ� �־��ش�
		else
			tangerineMap.insert(pair<int, int>(tangerineSize, 1));
	}

	vector<pair<int, int>> tangerineSizeList(tangerineMap.begin(), tangerineMap.end());
	sort(tangerineSizeList.begin(), tangerineSizeList.end(), [](const pair<int, int>a, const pair<int, int> b ) {return a.second > b.second;});

	int count = 0;
	for (int i = 0; i < tangerineSizeList.size(); ++i)
	{
		count += tangerineSizeList.at(i).second;
		++answer;
		if (count >= k)
			break;
	}

	return answer;
}

int main()
{
	return 0;
}