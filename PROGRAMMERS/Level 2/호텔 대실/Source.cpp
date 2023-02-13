#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

#include <queue>
using namespace std;

int getNormalizeTiem(string time)
{
	int hour = atoi(time.substr(0, 2).c_str());
	int min = atoi(time.substr(3, 2).c_str());

	return hour * 60 + min;
}

struct cmp
{
	bool operator()(pair<int, int> l, pair<int, int> r)
	{
		return l.first > r.first;
	}
};

int solution(vector<vector<string>> book_time)
{
	//시작 시간이 빠른 순으로 정렬
	priority_queue < pair<int, int>, vector<pair<int, int>>, cmp> pq;
	for (vector<string> reservation : book_time)
	{
		const int startTime = getNormalizeTiem(reservation[0]);
		const int endTime = getNormalizeTiem(reservation[1]) + 10;
		pq.push(pair<int, int>(startTime, endTime));
	}

	//vector를 만들어 크기당 방으로 사용한다
	//하나씩 빼면서 확인

	//처음 방을 넣어준다
	vector<int> rooms;
	rooms.push_back(pq.top().second);
	pq.pop();

	while (pq.empty() == false)
	{
		const pair<int, int> times = pq.top();
		pq.pop();

		//가능한 방 확인
		bool isPassible = false;
		for (int i = 0; i < rooms.size(); ++i)
		{
			//방의 시간이 예약시간 이하라면 가능하다(10분을 미리 더해줬기때문)
			if (rooms[i] <= times.first)
			{
				//시간 갱신
				rooms[i] = times.second;
				//가능한 방 찾음
				isPassible = true;
				break;
			}
		}

		//가능한 방이 없으면 추가해준다
		if (isPassible == false)
			rooms.push_back(times.second);
	}

	return rooms.size();
}

int main()
{
	vector<vector<string>> book_time;
	{
		vector<string> times;
		times.push_back("15:00");
		times.push_back("17:00");
		book_time.push_back(times);
	}
	{
		vector<string> times;
		times.push_back("16:40");
		times.push_back("18:20");
		book_time.push_back(times);
	}
	{
		vector<string> times;
		times.push_back("14:20");
		times.push_back("15:20");
		book_time.push_back(times);
	}
	{
		vector<string> times;
		times.push_back("14:10");
		times.push_back("19:20");
		book_time.push_back(times);
	}
	{
		vector<string> times;
		times.push_back("18:20");
		times.push_back("21:20");
		book_time.push_back(times);
	}

	int result = solution(book_time);
	return 0;
}