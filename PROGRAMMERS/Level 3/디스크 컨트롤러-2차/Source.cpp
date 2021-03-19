#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

//define
#define DEF_MIN -2147483648
#define DEF_MAX 2147483647

using ull = unsigned long long ;
using location =  pair<int, int> ;
using matrix = vector<vector<int>>;
using job = vector<int>;

enum eJob
{
	eEmpty = -1,
	eInput = 0,
	eRun
};

//custum function
struct HeapCompare
{
	bool operator()(job a, job b)	//
	{
		if (a[1] == b[1])
			return a[0] > b[0];
		else
			return a[1] > b[1];
	}
};

int solution(vector<vector<int>> jobs) {
	
	int answer = 0;

	priority_queue<job, vector<job>, HeapCompare> pqScheduler;
	job vNowSchedul(0);
	int nJobOrder(0), nMS(0), nJobSize(jobs.size()), nSum(0);
	sort(jobs.begin(), jobs.end());

	while (true)
	{
		//작업 추가
		if (nJobOrder != nJobSize)
		{
			while (true)//해당 ms의 작업이 없을 때 까지 추가
			{
				if (nJobOrder == nJobSize)	//순서가 크기랑 같아지면 반환
				{
					break;
				}

				const vector<int> vJob = jobs[nJobOrder];

				if (nMS < vJob[eInput] )	//해당시간에 작업이 없으면 반환
				{
					break;
				}

				pqScheduler.push(vJob);
				++nJobOrder;
			}
		}

		if (pqScheduler.empty() == false)// 대기열에 작업이 있으면 추가
		{
			vNowSchedul = pqScheduler.top();
			int nSchedulEndTime = nMS + vNowSchedul[eRun];

			pqScheduler.pop();

			//종료시간 합산
			nSum += nSchedulEndTime - vNowSchedul[eInput];

			//시간 진행
			nMS = nSchedulEndTime;

			//초기화
			vNowSchedul.clear();
		}
		else if (nJobOrder != nJobSize)//대기열에 작업이 없고 아직 진행하지 않은 작업이 있으면 시간 진행
		{
			const vector<int> vJob = jobs[nJobOrder];
			nMS = vJob[eInput];
		}
		else
		{
			break;
		}
	}
	answer = nSum / nJobSize;

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration

	//Solution
	cout << solution(vector<vector<int>>{ {0, 3}, { 1,9 }, { 2, 6 } }) << '\n';
	cout << solution(vector<vector<int>>{ {0, 3}, { 0,9 }, { 0, 6 } }) << '\n';
	cout << solution(vector<vector<int>>{ {8, 3}, { 3,9 }, { 2, 6 } }) << '\n';
	cout << solution(vector<vector<int>>{ {0, 3}, { 1,9 }, { 2, 6 } }) << '\n';

	//Output


	////////////////////////////////////
	system("pause");
	return 0;
}