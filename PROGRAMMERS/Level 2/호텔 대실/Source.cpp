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
	//���� �ð��� ���� ������ ����
	priority_queue < pair<int, int>, vector<pair<int, int>>, cmp> pq;
	for (vector<string> reservation : book_time)
	{
		const int startTime = getNormalizeTiem(reservation[0]);
		const int endTime = getNormalizeTiem(reservation[1]) + 10;
		pq.push(pair<int, int>(startTime, endTime));
	}

	//vector�� ����� ũ��� ������ ����Ѵ�
	//�ϳ��� ���鼭 Ȯ��

	//ó�� ���� �־��ش�
	vector<int> rooms;
	rooms.push_back(pq.top().second);
	pq.pop();

	while (pq.empty() == false)
	{
		const pair<int, int> times = pq.top();
		pq.pop();

		//������ �� Ȯ��
		bool isPassible = false;
		for (int i = 0; i < rooms.size(); ++i)
		{
			//���� �ð��� ����ð� ���϶�� �����ϴ�(10���� �̸� ������⶧��)
			if (rooms[i] <= times.first)
			{
				//�ð� ����
				rooms[i] = times.second;
				//������ �� ã��
				isPassible = true;
				break;
			}
		}

		//������ ���� ������ �߰����ش�
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