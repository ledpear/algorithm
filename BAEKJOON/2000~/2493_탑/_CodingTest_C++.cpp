#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main()
{
	//순서대로 값을 넣는다
	//넣을때 만약 새로 들어가는 숫자가 크다면 자기보다 큰 수가 나올때까지 pop한다.
	int size = 0;
	cin >> size;
	vector<int> tops(size, 0);
	for (int& top : tops)
		cin >> top;

	vector<pair<int,int>> sendTops;
	vector<int> result(size, 0);

	for(int topIndex = 1; topIndex <= size; ++topIndex)
	{
		const int top = tops[topIndex - 1];
		if (sendTops.empty())
		{
			sendTops.push_back(make_pair(top, topIndex));
			continue;
		}

		//수신 체크
		//순차적으로 탐색한다.
		//만약 가장 처음의 숫자가 지금 높이보다 낮다면 클리어하고 넣어준다.
		if (sendTops[0].first < top)
		{
			sendTops.clear();
			sendTops.push_back(make_pair(top, topIndex));
			continue;
		}

		for (int sendTopIndex = sendTops.size() - 1; sendTopIndex >= 0; --sendTopIndex)
		{
			const int sendTop = sendTops[sendTopIndex].first;
			//지금 높이보다 높은걸 찾으면 나간다.
			if (sendTop >= top)
			{
				//등록
				result[topIndex - 1] = sendTops[sendTopIndex].second;
				//sendTop 정리
				//지금보다 낮은 얘들은 다 정리한다.
				sendTops.erase(sendTops.begin() + sendTopIndex + 1, sendTops.end());
				sendTops.push_back(make_pair(top, topIndex));
				break;
			}
		}
	}

	for (int top : result)
		cout << top << " ";
}