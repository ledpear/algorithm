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
	//같은 숫자를 count해서 높은 숫자 순서로 정렬한다
	//하나씩 count를 더해나가면서 빼고 k를 넘으면 그때 뺀 갯수를 리턴한다
	//map으로 key는 숫자 value는 count로 순회해서 만들고
	//vector로 다시 뺀다음 정렬해서 순회한다
	int answer = 0;
	map<int, int> tangerineMap;
	const int size = tangerine.size();
	for (int i = 0; i < size; ++i)
	{
		const int tangerineSize = tangerine.at(i);
		//이미 있는 숫자라면 더해준다
		if (tangerineMap.find(tangerineSize) != tangerineMap.end())
			++tangerineMap.at(tangerineSize);
		//없다면 넣어준다
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